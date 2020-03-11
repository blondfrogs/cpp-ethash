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
                "f4ac202715ded4136e72887c39e63a4738331c57fd9eb79f6ec421c281aa8743",
                "b3bad9ca6f7c566cf0377d1f8cce29d6516a96562c122d924626281ec948ef02"},
        {49, "63155f732f2bf556967f906155b510c917e48e99685ead76ea83f4eca03ab12b", "0000000006ff2c47",
                "8f744dec9140938453c8a502a489861aedec7e98ce7e11b10a3b661940c38786",
                "ca0c365f1290ede4ee0d19cab08cd827030425ae8aba96b5248faafe732f1f80"},
        {50, "9e7248f20914913a73d80a70174c331b1d34f260535ac3631d770e656b5dd922", "00000000076e482e",
                "bd772e573609acead3b0f27d7935022ea0bf72f22ecf0980f0c21a74cc2fa3ef",
                "75439f6c6e153d3c798309f01ba37e7a284d172f50841c7b523e81c1b8247083"},
        {99, "de37e1824c86d35d154cf65a88de6d9286aec4f7f10c3fc9f0fa1bcc2687188d", "000000003917afab",
                "18a5d2f1eaa3df5a54f254c3f90bfa8e40c63913664175c93a9e5136f4dc7c5c",
                "2618185c024ad29fd75bc350da388cc0d47cdebbd6798400f17692a7ccf3314c"},
        {29950, "ac7b55e801511b77e11d52e9599206101550144525b5679f2dab19386f23dcce", "005d409dbc23a62a",
                "ba54a84121a31cfc36e7a54208d02b6a9d19229e8146215b3794e8d6b4adb7d1",
                "f8ea16e0b0664fc645a26d17778cf889563c6538a55927e03c55b17b6d49a40b"},
        {29999, "e43d7e0bdc8a4a3f6e291a5ed790b9fa1a0948a2b9e33c844888690847de19f5", "005db5fa4c2a3d03",
                "a1f8bd5569a20ffde37986854b510c9a6f049c24ff4b42476f0cd8be238a074f",
                "d420041934e40db477d4786fcebfc429c8af24eb6175c4f2b874e47f1cf3cc9b"},
        {30000, "d34519f72c97cae8892c277776259db3320820cb5279a299d0ef1e155e5c6454", "005db8607994ff30",
                "429bfeef392ba501041a5ad7b4666857d0fdec67e477803e57b156b7ad3b6ec8",
                "54ede6358d61c9911eb437e24bd2e7fed028878284a088b4e0f382f439b43c73"},
        {30049, "8b6ce5da0b06d18db7bd8492d9e5717f8b53e7e098d9fef7886d58a6e913ef64", "005e2e215a8ca2e7",
                "e648a324dc5a87f67e9455f001d7c65956dfb02ee43650e373c40559f9509633",
                "53989fb81a1cd013504ab6cb1a63500c1b50c0ad31ea8f4732fc9470907f1092"},
        {30050, "c2c46173481b9ced61123d2e293b42ede5a1b323210eb2a684df0874ffe09047", "005e30899481055e",
                "c7a9d30ccad81d4c9524761783b5fa59d54b63b64f953bccd122aa39db53726f",
                "d5849751f4bb57cdba8cd164d7f37965a3320171215f9839388ca5e60e1579a0"},
        {30099, "ea42197eb2ba79c63cb5e655b8b1f612c5f08aae1a49ff236795a3516d87bc71", "005ea6aef136f88b",
                "5a79e483701ebc31f54487e52a363e9dddac817884c7cf95acedb68ac977f2fd",
                "6d3b073d286209f3c09a71d31bac95897cb6341a4019716b659ea47c1ed86069"},
        {59950, "49e15ba4bf501ce8fe8876101c808e24c69a859be15de554bf85dbc095491bd6", "02ebe0503bd7b1da",
                "25e0cb80a0b75f9a169ee775abca1997c4f3ddb974d17eaff23baf1ac0b11013",
                "77071fd6cb96d6414f32aa418dfecda56d0bc90eb75abdd72f1a31af70044fd1"},
        {59999, "f5c50ba5c0d6210ddb16250ec3efda178de857b2b1703d8d5403bd0f848e19cf", "02edb6275bd221e3",
                "7d8cf44034867cb44855b5a477b2393e868ea594b4259ba301d7fe2b2e6bf732",
                "51a3de5ffdaee20afb2d1a309e9fa57976075a5346b90afd7183b4b9e03022b2"},
        {170915, "5b3e8dfa1aafd3924a51f33e2d672d8dae32fa528d8b1d378d6e4db0ec5d665d", "0000000044975727",
                "a77d4c69361a65c614b95697c62650b7f7f6c96188fde376c7cd3f0aa6b37f14",
                "4655303777e433a21c3f49c417ab9763fe48e8ff85852fbe85b417dbff2a4f1c"},

};
}  // namespace
