
#include <ethash/progpow.hpp>
#include "../../test/unittests/helpers.hpp"
#include <ethash/ethash.hpp>
#include <ethash/ethash-internal.hpp>
#include <climits>


//int main(int argc, const char* argv[])
//{
//    std::string str_header_hash;
//    std::string str_mix_hash;
//    std::string str_nonce;
//    std::string str_boundary;
//
//    for (int i = 0; i < argc; ++i)
//    {
//        const std::string arg{argv[i]};
//
//        if (arg == "-h" && i + 1 < argc)
//            str_header_hash = std::string(argv[++i]);
//        else if (arg == "-m" && i + 1 < argc)
//            str_mix_hash = std::string(argv[++i]);
//        else if (arg == "-n" && i + 1 < argc)
//            str_nonce = std::string(argv[++i]);
//        else if (arg == "-b" && i + 1 < argc)
//            str_boundary = std::string(argv[++i]);
//    }
//
//    char final_hash[64];
//
//    if (progpow::light_verify(str_header_hash.c_str(), str_mix_hash.c_str(), str_nonce.c_str(), str_boundary.c_str(), final_hash))
//        printf("%.*s\n", 64, final_hash);
//    else {
//        printf("Not found\n");
//    }
//
//    return 0;
//}

#include <memory>
#include <cstdint>
#include <iostream>
#include <evhttp.h>
int main(int argc, const char* argv[])
{
    bool fLightMode = true;
    bool fFullMode = false;

    static int epoch_number = 0;
//    static ethash::epoch_context_full_ptr context_full {nullptr, nullptr};// = ethash::create_epoch_context_full(epoch_number);
    static ethash::epoch_context_ptr context_light{nullptr, nullptr};

    for (int i = 0; i < argc; ++i)
    {
        const std::string arg{argv[i]};

        if (arg == "-f") {
            fFullMode = true;
            fLightMode = false;
        }

        if (arg == "-e" && i + 1 < argc)
            epoch_number = atoi(argv[++i]);
    }


    if (fFullMode) {
        // TODO, not working yet
    } else if (fLightMode) {
        if (!context_light || context_light->epoch_number != epoch_number)
            context_light = ethash::create_epoch_context(epoch_number);
    }

    if (!event_init())
    {
        std::cerr << "Failed to init libevent." << std::endl;
        return -1;
    }
    char const SrvAddress[] = "127.0.0.1";
    std::uint16_t SrvPort = 5555;
    std::unique_ptr<evhttp, decltype(&evhttp_free)> Server(evhttp_start(SrvAddress, SrvPort), &evhttp_free);
    if (!Server)
    {
        std::cerr << "Failed to init http server." << std::endl;
        return -1;
    }
    void (*OnReq)(evhttp_request *req, void *) = [] (evhttp_request *req, void *)
    {
        auto *OutBuf = evhttp_request_get_output_buffer(req);

        if (!OutBuf)
            return;

        struct evkeyvalq headers{};
        const struct evhttp_uri *uri = evhttp_request_get_evhttp_uri(req);
        const char * query = evhttp_uri_get_query(uri);
        evhttp_parse_query_str(query, &headers);
//        printf("%s\n", evhttp_find_header(&headers, "header_hash"));
//        printf("%s\n", evhttp_find_header(&headers, "mix_hash"));
//        printf("%s\n", evhttp_find_header(&headers, "nonce"));
//        printf("%s\n", evhttp_find_header(&headers, "height"));
//        printf("%s\n", evhttp_find_header(&headers, "share_boundary"));
//        printf("%s\n", evhttp_find_header(&headers, "block_boundary"));
        const char* header_hash_str = evhttp_find_header(&headers, "header_hash");
        const char* mix_hash_str = evhttp_find_header(&headers, "mix_hash");
        const char* nonce_str = evhttp_find_header(&headers, "nonce");
        const char* height_str = evhttp_find_header(&headers, "height");
        const char* share_boundary_str = evhttp_find_header(&headers, "share_boundary");
        const char* block_boundary_str = evhttp_find_header(&headers, "block_boundary");

        if (!header_hash_str || !mix_hash_str || !nonce_str || !height_str || !share_boundary_str || !block_boundary_str) {
            evbuffer_add_printf(OutBuf, "<html><body><center><h1>Invalid data. Missing required data</h1></center></body></html>");
            evhttp_send_reply(req, HTTP_OK, "", OutBuf);
        } else {
            auto header_hash = to_hash256(header_hash_str);
            auto mix_hash = to_hash256(mix_hash_str);
            auto share_boundary = to_hash256(share_boundary_str);
            auto block_boundary = to_hash256(block_boundary_str);

            uint64_t nNonce;
            errno = 0;
            char *endp = nullptr;
            errno = 0; // strtoull will not set errno if valid
            unsigned long long int n = strtoull(nonce_str, &endp, 16);
            nNonce = (uint64_t) n;
            if (nNonce == 0 && endp == nonce_str) {
                std::cout << "Nonce wasn't a string" << std::endl;
                return;
            } else if (nNonce == ULLONG_MAX && errno) {
                std::cout << "Hex value was out of range" << std::endl;
                return;
            } else if (*endp) {
                std::cout << "Invalid hex string" << std::endl;
                return;
            }

            uint32_t nHeight;
            errno = 0;
            endp = nullptr;
            errno = 0; // strtoul will not set errno if valid
            unsigned long int nH = strtoul(height_str, &endp, 10);
            nHeight = (uint32_t) nH;
            if (nHeight == 0 && endp == height_str) {
                std::cout << "Nonce wasn't a string" << std::endl;
                return;
            } else if (nHeight == ULONG_MAX && errno) {
                std::cout << "Hex value was out of range" << std::endl;
                return;
            } else if (*endp) {
                std::cout << "Invalid hex string" << std::endl;
                return;
            }

            epoch_number = (int) nHeight / ETHASH_EPOCH_LENGTH;
            if (!context_light || context_light->epoch_number != epoch_number)
                context_light = ethash::create_epoch_context(epoch_number);

            const auto result = progpow::hash(*context_light, (int) nHeight, header_hash, nNonce);
            std::string share_met = "false";
            std::string block_met = "false";
            std::string mix_match = "false";
            if (result.mix_hash == mix_hash) {
                printf("mix hash matches\n");
                mix_match = "true";
            }

            if (ethash::is_less_or_equal(result.final_hash, share_boundary)) {
                printf("final hash meets share boundary\n");
                share_met = "true";
            }

            if (ethash::is_less_or_equal(result.final_hash, block_boundary)) {
                printf("final hash meets block boundary\n");
                block_met = "true";
            }

            evbuffer_add_printf(OutBuf, "{\"%s\":%s, \"%s\":%s, \"%s\":%s, \"%s\":\"%s\"}", "result", mix_match.c_str(),
                                "share", share_met.c_str(), "block", block_met.c_str(), "digest",
                                to_hex(result.final_hash).c_str());
            evhttp_send_reply(req, HTTP_OK, "", OutBuf);
        }
    };
    evhttp_set_gencb(Server.get(), OnReq, nullptr);
    if (event_dispatch() == -1)
    {
        std::cerr << "Failed to run messahe loop." << std::endl;
        return -1;
    }
    return 0;
}