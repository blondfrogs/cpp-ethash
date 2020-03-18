// ethash: C/C++ implementation of Ethash, the Ethereum Proof of Work algorithm.
// Copyright 2018-2019 Pawel Bylica.
// Licensed under the Apache License, Version 2.0.

/// @file
/// ProgPoW test vectors.

#pragma once

namespace  // In anonymous namespace to allow including in multiple compilation units.
{
/// Defines a test case for ProgPoW hash() function.
struct progpow_hash_test_case
{
    int block_number;
    const char* header_hash_hex;
    const char* nonce_hex;
    const char* mix_hash_hex;
    const char* final_hash_hex;
};

progpow_hash_test_case progpow_hash_test_cases[] = {
        {0, "0000000000000000000000000000000000000000000000000000000000000000", "0000000000000000",
                "40ce8bf6046c09f90f812f015d4ab8a1b504e7313e86d8a96197d5dadc3634e5",
                "e6480cfa901dd209a9d8bef73275896be179f86b42e136efe692e14a41cb17b2"},
        {49, "63155f732f2bf556967f906155b510c917e48e99685ead76ea83f4eca03ab12b", "0000000007073c07",
                "62f6b49f39092b76fc04bb8db1e435fa5c3182a15f3c179ae7353a073c752c11",
                "c3a419fc1e295899c0e0e596b1e9c7b609df96802b4b46157d07a632b8043979"},
        {50, "9e7248f20914913a73d80a70174c331b1d34f260535ac3631d770e656b5dd922", "00000000076e482e",
                "d6c6ec98a9dc1ed90eb70c476a32a1bc4d97329f9e867a4157378ce0a9b7f25e",
                "0ed2d84bd91987d85971d38dd649d7b605dfc524b4e05f8aee6eb34142169117"},
        {99, "de37e1824c86d35d154cf65a88de6d9286aec4f7f10c3fc9f0fa1bcc2687188d", "000000003917afab",
                "7b8d1d879bc69fb1d5cf9a39822f2ee7d2d6e24bf785dbe605b275005f513c29",
                "fbada78801c65f08951dc8b4e9b00c2308d996053d1ea2c7caa181ee808cb3f2"},
        {29950, "ac7b55e801511b77e11d52e9599206101550144525b5679f2dab19386f23dcce", "005d409dbc23a62a",
                "f8f15ab6c8d5f1d57875bcbf1700688c372874478a9e272a3f45d072c4f6e74a",
                "53539c8764df6552898fed503bf8a688c8f8fc967ea24e04907988a2fef287ad"},
        {29999, "e43d7e0bdc8a4a3f6e291a5ed790b9fa1a0948a2b9e33c844888690847de19f5", "005db5fa4c2a3d03",
                "398e0c0be1a3fc28306699222d5ceb9268698461f41fcdf8cc17acb0f1a54ca7",
                "adad72cff5199da834759ab50a7711c3848f6cc41887d629eef0818f60b97c26"},
        {30000, "d34519f72c97cae8892c277776259db3320820cb5279a299d0ef1e155e5c6454", "005db8607994ff30",
                "140759c86094fe8ce696d6d9c74f6ad92ddf91579e6f86d792bbd0656dcfc485",
                "826139aa4d7bf853a3ac392d8e0e2f474c1faa0ec7c5ea81eb3461171f9e1f63"},
        {30049, "8b6ce5da0b06d18db7bd8492d9e5717f8b53e7e098d9fef7886d58a6e913ef64", "005e2e215a8ca2e7",
                "0952d0329cacc09ac08d3a10e47af7927113f360a48407d7f37c3a9c5a6097b7",
                "0bcde14fd3e7e4bd8cc4b52a1105db135ca1de6c02f1923560ae40105b9c4fbd"},
        {30050, "c2c46173481b9ced61123d2e293b42ede5a1b323210eb2a684df0874ffe09047", "005e30899481055e",
                "db83342bddb5a4a80947ebaa70132232c6ddb6544d64f041150a9363885d18ce",
                "6baa8eff51feb3bb5561d005afee62db6b729fe28f28eb26f59befcbf12a9e09"},
        {30099, "ea42197eb2ba79c63cb5e655b8b1f612c5f08aae1a49ff236795a3516d87bc71", "005ea6aef136f88b",
                "bc5eeb1a460dcbaccb52d483ec77483088f35e80ba0724aa8084af49f231f7d4",
                "3539e51ab65eec649f9275905a91e9a20b2d481e6e116a5d3fd6b15cc743a37e"},
        {59950, "49e15ba4bf501ce8fe8876101c808e24c69a859be15de554bf85dbc095491bd6", "02ebe0503bd7b1da",
                "60721a35d08a7fd4b1acfe369b5132e6adf187e8150591e502620df0783aa297",
                "b9179bd7c4f9429d6f553b249a9ddc0160847f41990f596ebf3fbb9576ddf417"},
        {59999, "f5c50ba5c0d6210ddb16250ec3efda178de857b2b1703d8d5403bd0f848e19cf", "02edb6275bd221e3",
                "32a82af5594b09e9fee26d283aa52e7b57317670a6957f490023e29f456677b5",
                "0f058ff227a7c9c3dcb43bdef0db9e2721804a436412104ebe7374734c07887b"},
        {170915, "5b3e8dfa1aafd3924a51f33e2d672d8dae32fa528d8b1d378d6e4db0ec5d665d", "0000000044975727",
                "75de15add34e91e4924b08f95a31da83e0ac9ce9e53ba2210a61f70dc5263c88",
                "09bc06b70c99ae70f32c46610ba559fd43e16aa1e482f4d56bff5690e084ed97"},

};
}  // namespace
