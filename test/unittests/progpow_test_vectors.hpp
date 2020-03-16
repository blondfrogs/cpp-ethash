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
                "4b0050b03f6823e8ed6aabfceb2debca378682f987c7127a1ade109621b90afd",
                "412ce3770325c5802cf27cab26df1525fcd3f20b4c026b8d798120fffb96243c"},
        {49, "63155f732f2bf556967f906155b510c917e48e99685ead76ea83f4eca03ab12b", "0000000007073c07",
                "6cab845b005f0adef9971e5b4b44e9c95e606dca9fb5d888f564ac67404d03c9",
                "5eeb86db64e70fc4f53f81034d513ddeb858a43837db9fd9249b36a23af647a9"},
        {50, "9e7248f20914913a73d80a70174c331b1d34f260535ac3631d770e656b5dd922", "00000000076e482e",
                "40fad44d7014eacd87401262b2b1c7c1f9c645a10e8782875be396f7d400e6aa",
                "7eacf7e0ee839a73a2244c88757b4b8b84fd9a80e70189009c493257024b72c2"},
        {99, "de37e1824c86d35d154cf65a88de6d9286aec4f7f10c3fc9f0fa1bcc2687188d", "000000003917afab",
                "56566df0aacffc4dbff0d74a78ce055afdbe4dcf55013a8b5f326ce6d43b9509",
                "fc484737af7c483fb08601f8ad3a11528734c4a3870bdc34e7a1214bfe72211b"},
        {29950, "ac7b55e801511b77e11d52e9599206101550144525b5679f2dab19386f23dcce", "005d409dbc23a62a",
                "8c84e3839e839ef6a3efed9cab77a59c6fb12f88186190876996865512f7beef",
                "5a0dd9d7bf9c98732d8948f56a85f47af4cd104ab5f8e8a8402e12d03003103e"},
        {29999, "e43d7e0bdc8a4a3f6e291a5ed790b9fa1a0948a2b9e33c844888690847de19f5", "005db5fa4c2a3d03",
                "342bebfeb238d5194e2ee90ec212ea17a259aa44f24348580213608d5e6ec185",
                "7ccd59c33dceaf91e149f2cb16789a62127dc5e48502cc52c9490386ae01f216"},
        {30000, "d34519f72c97cae8892c277776259db3320820cb5279a299d0ef1e155e5c6454", "005db8607994ff30",
                "f1bb9e9ddc858326c6ac20df417d4c30c9f1893a35bcda6b5aef5ca692557dab",
                "02dee9fd78faa24674b80c3c675104d058f9e596273b19a1eb9b775e64cc0d5d"},
        {30049, "8b6ce5da0b06d18db7bd8492d9e5717f8b53e7e098d9fef7886d58a6e913ef64", "005e2e215a8ca2e7",
                "5e472feb5126c96a84e384c813472c526604471788824414df2623cd592b3d04",
                "7220fded09e1a3155e105f60c2fc69d09b3347c37caa931a296917ddf4791c47"},
        {30050, "c2c46173481b9ced61123d2e293b42ede5a1b323210eb2a684df0874ffe09047", "005e30899481055e",
                "7c0258166e09f42aecca64f2cb5a3bd004362e87839195c61088274950a3796d",
                "c0841ab796a1e007097acfb4385955995070fc05c212f8addaf7f96dff7a3c5f"},
        {30099, "ea42197eb2ba79c63cb5e655b8b1f612c5f08aae1a49ff236795a3516d87bc71", "005ea6aef136f88b",
                "4f909b7e7604cc2bb940be125d355ae32b025db0d9c2bd0dbab4a3f9307def39",
                "216fe0f13cedfb98cecf4f0fb69807aa63db3aac0ac6234e2d76191f868f18a1"},
        {59950, "49e15ba4bf501ce8fe8876101c808e24c69a859be15de554bf85dbc095491bd6", "02ebe0503bd7b1da",
                "ab36eb60cda5f6aecb936009d9b4690d6774895104e44cc87e18cee0eca3ea11",
                "e09c12e635cca96c85d5250bc36f6a9286d84c29d0fa1bdeca6316124b8cf522"},
        {59999, "f5c50ba5c0d6210ddb16250ec3efda178de857b2b1703d8d5403bd0f848e19cf", "02edb6275bd221e3",
                "e3adbf099afa3621762e3aa09bc7e5a5f6491ee2c6211adbec894c0a534b5585",
                "1f92090f87f136d3d46fa0993f154b6e86b7e79026e4dd7944e9fc4e50b5d9fe"},
        {170915, "5b3e8dfa1aafd3924a51f33e2d672d8dae32fa528d8b1d378d6e4db0ec5d665d", "0000000044975727",
                "f2442044ef99010106e99fb13dcaf9bc8ac5474c625c41968e84c0eebd8ddf45",
                "131ee07671facb0490ad4bd505acd1d7fae322d7102f5f3d28346dee0d1b68b3"},

};
}  // namespace
