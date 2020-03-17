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
                "340fc592e231217f7b398e053ee949c7e58570658c7b45b10b1e353b4f2c584b",
                "f44a88c7828497c7bc545894f341a330b5e39c454edaa1655c37aa3486c0fd6f"},
        {49, "63155f732f2bf556967f906155b510c917e48e99685ead76ea83f4eca03ab12b", "0000000007073c07",
                "932e1fba96a4a821f71668f300b8b2233de1f15516a82c21884352a5a6ed1bc6",
                "25d56941b4d65b2f04f8e5d7b017a9af185fb91448ca270e0ba4d208a97716df"},
        {50, "9e7248f20914913a73d80a70174c331b1d34f260535ac3631d770e656b5dd922", "00000000076e482e",
                "bf6fbe5b8bfd6303458e1d9d8a1fe9ffbe56fa2565fce4d05a92e516c35dd421",
                "e5b5a1fe012b2a443e75e31e7227a9a9cb572589eae56d3e54b20b9c058fe133"},
        {99, "de37e1824c86d35d154cf65a88de6d9286aec4f7f10c3fc9f0fa1bcc2687188d", "000000003917afab",
                "967f60c40cd4a400fdc9e506831ccb4e307a599309842570fab216ae031aa2b2",
                "cba9e2a6b65de188b9a6c323490a810d7e79b8877d4e1607ea6009453dc30b1d"},
        {29950, "ac7b55e801511b77e11d52e9599206101550144525b5679f2dab19386f23dcce", "005d409dbc23a62a",
                "d3b0a3d9a52c5b2c1b3f37d2c0e15762629f9b6ad254c1a5356eaa65cf098078",
                "8f2dc26a70d2b433c92f7e31cd30ede3ed752be08dfd4fc4d1aff2a3e8ec3be6"},
        {29999, "e43d7e0bdc8a4a3f6e291a5ed790b9fa1a0948a2b9e33c844888690847de19f5", "005db5fa4c2a3d03",
                "7f40b43c0e4a1ccaed033290b3b17d6f52040bc2b4b82e07b916e71c3c57e87b",
                "fe06f4db1ffc7c36247edce6a536df0662e888b5e75b3b0a955844e0010067a0"},
        {30000, "d34519f72c97cae8892c277776259db3320820cb5279a299d0ef1e155e5c6454", "005db8607994ff30",
                "2eedff493ed7f828190f97a2b96ef18f55e4b83840550dc572dd7e33f4a4ba71",
                "702bf1cc23bf6914747c4d456f118aac7cdfe6f32fa4a6f82d7829e42a3bbf7e"},
        {30049, "8b6ce5da0b06d18db7bd8492d9e5717f8b53e7e098d9fef7886d58a6e913ef64", "005e2e215a8ca2e7",
                "d3dd89e07c6d1d3285b6605b54125213d67d5b09008f763abbec64ba7dabdd68",
                "ee826633e426a1686991c9f3cb9dc7d76cef789c3470b98961e12becfc1f60e3"},
        {30050, "c2c46173481b9ced61123d2e293b42ede5a1b323210eb2a684df0874ffe09047", "005e30899481055e",
                "88d49d9394e867a4ac6297b2160f6b3d2f608424b15a2443c5ccab8053826c7d",
                "899ee7b5b6aab4f2c0d98172ca848f9d7b016812dc902f3ac1aa66d1466dc436"},
        {30099, "ea42197eb2ba79c63cb5e655b8b1f612c5f08aae1a49ff236795a3516d87bc71", "005ea6aef136f88b",
                "131a4e9286c1c3782098652e0842a486df221e0ed57b93a4289f9512fe791fb8",
                "39861b6c9021309b35e5540bbfb206f8f6aaf136d00e3dd2b2ef9c2a5058229a"},
        {59950, "49e15ba4bf501ce8fe8876101c808e24c69a859be15de554bf85dbc095491bd6", "02ebe0503bd7b1da",
                "fec7953c1a4c8e8524dc560578a36d7fe237fed4bd08732be688c1603f1e23f8",
                "1d90e21dcb65343ff2c1864740fd1cd0eae26df2c381cf988232a43c7bdc029f"},
        {59999, "f5c50ba5c0d6210ddb16250ec3efda178de857b2b1703d8d5403bd0f848e19cf", "02edb6275bd221e3",
                "d0a252808931f5a7690dff9e218104ec2f32c6d51673a17867fc1d347403de7a",
                "6a01b3735215e993900f5c4c151f5ae3b61ec993c646f6fc2cbf349115834c91"},
        {170915, "5b3e8dfa1aafd3924a51f33e2d672d8dae32fa528d8b1d378d6e4db0ec5d665d", "0000000044975727",
                "84f334b4c3ce7abe8539cfc4f811111e84d5b1c6ef79d2ecebecfd016288f47d",
                "905ab496603971928fbd0fdf9d63907bbc65b6e434f87f5db0a6d72238ddac93"},

};
}  // namespace
