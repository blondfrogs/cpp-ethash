
#include <ethash/progpow.hpp>
#include <ethash/hash_types.hpp>
#include <iostream>
#include "../unittests/helpers.hpp"

int main(int argc, const char* argv[])
{
    std::string str_header_hash;
    std::string str_mix_hash;
    std::string str_nonce;
    std::string str_boundary;

    for (int i = 0; i < argc; ++i)
    {
        const std::string arg{argv[i]};

        if (arg == "-h" && i + 1 < argc)
            str_header_hash = std::string(argv[++i]);
        else if (arg == "-m" && i + 1 < argc)
            str_mix_hash = std::string(argv[++i]);
        else if (arg == "-n" && i + 1 < argc)
            str_nonce = std::string(argv[++i]);
        else if (arg == "-b" && i + 1 < argc)
            str_boundary = std::string(argv[++i]);
    }


//    ethash::hash256 header = to_hash256(str_header_hash);
//    ethash::hash256 mix_hash = to_hash256(str_mix_hash);
//    ethash::hash256 boundary = to_hash256(str_boundary);

    std::string final_hash;

    if (progpow::light_verify(str_header_hash, str_mix_hash, str_nonce, str_boundary, final_hash))
        std::cout << final_hash << std::endl;
    else {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}