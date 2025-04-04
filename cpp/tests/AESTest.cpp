#include <gtest/gtest.h>
#include "../AES.h"
#include <iostream>

// FIPS 197, Appendix B key
const uint8_t example_key128[16] = {
    0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x9 , 0xcf, 0x4f, 0x3c
};

const uint8_t example_key192[24] = {
	0x8e, 0x73, 0xb0, 0xf7, 0xda, 0x0e, 0x64, 0x52, 0xc8, 0x10, 0xf3, 0x2b,
	0x80, 0x90, 0x79, 0xe5, 0x62, 0xf8, 0xea, 0xd2, 0x52, 0x2c, 0x6b, 0x7b
};

const uint8_t example_key256[32] = {
	0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
	0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4
};

// FIPS 197, Appendix B expanded subkeys
const uint8_t example_subkeys128[11][16] = {
    {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c},
    {0xA0, 0xFA, 0xFE, 0x17, 0x88, 0x54, 0x2c, 0xb1, 0x23, 0xa3, 0x39, 0x39, 0x2a, 0x6c, 0x76, 0x05},
    {0xF2, 0xC2, 0x95, 0xF2, 0x7a, 0x96, 0xb9, 0x43, 0x59, 0x35, 0x80, 0x7a, 0x73, 0x59, 0xf6, 0x7f},
    {0x3D, 0x80, 0x47, 0x7D, 0x47, 0x16, 0xFE, 0x3E, 0x1E, 0x23, 0x7E, 0x44, 0x6D, 0x7A, 0x88, 0x3B},
    {0xEF, 0x44, 0xA5, 0x41, 0xA8, 0x52, 0x5B, 0x7F, 0xB6, 0x71, 0x25, 0x3B, 0xDB, 0x0B, 0xAD, 0x00},
    {0xD4, 0xD1, 0xC6, 0xF8, 0x7C, 0x83, 0x9D, 0x87, 0xCA, 0xF2, 0xB8, 0xBC, 0x11, 0xF9, 0x15, 0xBC},
    {0x6D, 0x88, 0xA3, 0x7A, 0x11, 0x0B, 0x3E, 0xFD, 0xDB, 0xF9, 0x86, 0x41, 0xCA, 0x00, 0x93, 0xFD},
    {0x4E, 0x54, 0xF7, 0x0E, 0x5F, 0x5F, 0xC9, 0xF3, 0x84, 0xA6, 0x4F, 0xB2, 0x4E, 0xA6, 0xDC, 0x4F},
    {0xEA, 0xD2, 0x73, 0x21, 0xB5, 0x8D, 0xBA, 0xD2, 0x31, 0x2B, 0xF5, 0x60, 0x7F, 0x8D, 0x29, 0x2F},
    {0xAC, 0x77, 0x66, 0xF3, 0x19, 0xFA, 0xDC, 0x21, 0x28, 0xD1, 0x29, 0x41, 0x57, 0x5c, 0x00, 0x6E},
    {0xD0, 0x14, 0xF9, 0xA8, 0xC9, 0xEE, 0x25, 0x89, 0xE1, 0x3F, 0x0c, 0xC8, 0xB6, 0x63, 0x0C, 0xA6}
};

const uint8_t example_subkeys192[13][16] = { 
    {0x8e, 0x73, 0xb0, 0xf7, 0xda, 0x0e, 0x64, 0x52, 0xc8, 0x10, 0xf3, 0x2b, 0x80, 0x90, 0x79, 0xe5},
	{0x62, 0xf8, 0xea, 0xd2, 0x52, 0x2c, 0x6b, 0x7b, 0xfe, 0x0c, 0x91, 0xf7, 0x24, 0x02, 0xf5, 0xa5},
	{0xec, 0x12, 0x06, 0x8e, 0x6c, 0x82, 0x7f, 0x6b, 0x0e, 0x7a, 0x95, 0xb9, 0x5c, 0x56, 0xfe, 0xc2},
	{0x4d, 0xb7, 0xb4, 0xbd, 0x69, 0xb5, 0x41, 0x18, 0x85, 0xa7, 0x47, 0x96, 0xe9, 0x25, 0x38, 0xfd},
	{0xe7, 0x5f, 0xad, 0x44, 0xbb, 0x09, 0x53, 0x86, 0x48, 0x5a, 0xf0, 0x57, 0x21, 0xef, 0xb1, 0x4f},
	{0xa4, 0x48, 0xf6, 0xd9, 0x4d, 0x6d, 0xce, 0x24, 0xaa, 0x32, 0x63, 0x60, 0x11, 0x3b, 0x30, 0xe6},
	{0xa2, 0x5e, 0x7e, 0xd5, 0x83, 0xb1, 0xcf, 0x9a, 0x27, 0xf9, 0x39, 0x43, 0x6a, 0x94, 0xf7, 0x67},
	{0xc0, 0xa6, 0x94, 0x07, 0xd1, 0x9d, 0xa4, 0xe1, 0xec, 0x17, 0x86, 0xeb, 0x6f, 0xa6, 0x49, 0x71},
	{0x48, 0x5f, 0x70, 0x32, 0x22, 0xcb, 0x87, 0x55, 0xe2, 0x6d, 0x13, 0x52, 0x33, 0xf0, 0xb7, 0xb3},
	{0x40, 0xbe, 0xeb, 0x28, 0x2f, 0x18, 0xa2, 0x59, 0x67, 0x47, 0xd2, 0x6b, 0x45, 0x8c, 0x55, 0x3e},
	{0xa7, 0xe1, 0x46, 0x6c, 0x94, 0x11, 0xf1, 0xdf, 0x82, 0x1f, 0x75, 0x0a, 0xad, 0x07, 0xd7, 0x53},
	{0xca, 0x40, 0x05, 0x38, 0x8f, 0xcc, 0x50, 0x06, 0x28, 0x2d, 0x16, 0x6a, 0xbc, 0x3c, 0xe7, 0xb5},
	{0xe9, 0x8b, 0xa0, 0x6f, 0x44, 0x8c, 0x77, 0x3c, 0x8e, 0xcc, 0x72, 0x04, 0x01, 0x00, 0x22, 0x02}
};

const uint8_t example_subkeys256[15][16] = {
    {0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81},
	{0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4},
	{0x9b, 0xa3, 0x54, 0x11, 0x8e, 0x69, 0x25, 0xaf, 0xa5, 0x1a, 0x8b, 0x5f, 0x20, 0x67, 0xfc, 0xde},
	{0xa8, 0xb0, 0x9c, 0x1a, 0x93, 0xd1, 0x94, 0xcd, 0xbe, 0x49, 0x84, 0x6e, 0xb7, 0x5d, 0x5b, 0x9a},
	{0xd5, 0x9a, 0xec, 0xb8, 0x5b, 0xf3, 0xc9, 0x17, 0xfe, 0xe9, 0x42, 0x48, 0xde, 0x8e, 0xbe, 0x96},
	{0xb5, 0xa9, 0x32, 0x8a, 0x26, 0x78, 0xa6, 0x47, 0x98, 0x31, 0x22, 0x29, 0x2f, 0x6c, 0x79, 0xb3},
	{0x81, 0x2c, 0x81, 0xad, 0xda, 0xdf, 0x48, 0xba, 0x24, 0x36, 0x0a, 0xf2, 0xfa, 0xb8, 0xb4, 0x64},
	{0x98, 0xc5, 0xbf, 0xc9, 0xbe, 0xbd, 0x19, 0x8e, 0x26, 0x8c, 0x3b, 0xa7, 0x09, 0xe0, 0x42, 0x14},
	{0x68, 0x00, 0x7b, 0xac, 0xb2, 0xdf, 0x33, 0x16, 0x96, 0xe9, 0x39, 0xe4, 0x6c, 0x51, 0x8d, 0x80},
	{0xc8, 0x14, 0xe2, 0x04, 0x76, 0xa9, 0xfb, 0x8a, 0x50, 0x25, 0xc0, 0x2d, 0x59, 0xc5, 0x82, 0x39},
	{0xde, 0x13, 0x69, 0x67, 0x6c, 0xcc, 0x5a, 0x71, 0xfa, 0x25, 0x63, 0x95, 0x96, 0x74, 0xee, 0x15},
	{0x58, 0x86, 0xca, 0x5d, 0x2e, 0x2f, 0x31, 0xd7, 0x7e, 0x0a, 0xf1, 0xfa, 0x27, 0xcf, 0x73, 0xc3},
	{0x74, 0x9c, 0x47, 0xab, 0x18, 0x50, 0x1d, 0xda, 0xe2, 0x75, 0x7e, 0x4f, 0x74, 0x01, 0x90, 0x5a},
	{0xca, 0xfa, 0xaa, 0xe3, 0xe4, 0xd5, 0x9b, 0x34, 0x9a, 0xdf, 0x6a, 0xce, 0xbd, 0x10, 0x19, 0x0d},
	{0xfe, 0x48, 0x90, 0xd1, 0xe6, 0x18, 0x8d, 0x0b, 0x04, 0x6d, 0xf3, 0x44, 0x70, 0x6c, 0x63, 0x1e}
};

TEST(AESTest, KeyExpansion128) {
	AES<128> aes;
	aes.setKey(example_key128);
    for (int i = 0; i < 11; ++i)
        for (int j = 0; j < 16; ++j) {
            EXPECT_EQ(reinterpret_cast<uint8_t *>(aes.roundKeys + i)[j], example_subkeys128[i][j]) << "Vectors differ at index " << i << ',' << j;
        }
}

TEST(AESTest, KeyExpansion192) {
	AES<192> aes;
	aes.setKey(example_key192);
    for (int i = 0; i < 13; ++i)
        for (int j = 0; j < 16; ++j) {
            EXPECT_EQ(reinterpret_cast<uint8_t *>(aes.roundKeys + i)[j], example_subkeys192[i][j]) << "Vectors differ at index " << i << ',' << j;
        }
}

TEST(AESTest, KeyExpansion256) {
	AES<256> aes;
	aes.setKey(example_key256);
    for (int i = 0; i < 13; ++i)
        for (int j = 0; j < 16; ++j) {
            EXPECT_EQ(reinterpret_cast<uint8_t *>(aes.roundKeys + i)[j], example_subkeys256[i][j]) << "Vectors differ at index " << i << ',' << j;
        }
}

TEST(AESTest, EncryptBlock) {
	// FIPS 197, Appendix B input
	const uint8_t input[16] = {
		0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34
	};

	// Result
	uint8_t result[16] = { 0 };

	AES<128> aes;
	aes.setKey(example_key128);
	aes.encryptBlock(input, result);

	// FIPS 197, Appendix B output
	const uint8_t exp[16] = {
		0x39, 0x25, 0x84, 0x1D, 0x02, 0xDC, 0x09, 0xFB, 0xDC, 0x11, 0x85, 0x97, 0x19, 0x6A, 0x0B, 0x32
	};

    EXPECT_EQ(memcmp(result, exp, 16), 0);
}

TEST(AESTest, DecryptBlock) {
	// FIPS 197, Appendix B input
	const uint8_t input[16] = {
		0x39, 0x25, 0x84, 0x1D, 0x02, 0xDC, 0x09, 0xFB, 0xDC, 0x11, 0x85, 0x97, 0x19, 0x6A, 0x0B, 0x32
	};

	uint8_t result[16] = { 0 };

	AES<128> aes;
	aes.setKey(example_key128);
	aes.decryptBlock(input, result);

	// FIPS 197, Appendix B output
	const uint8_t exp[16] = {
		0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34
	};

	for (int i = 0; i < 16; ++i)
		EXPECT_EQ(result[i], exp[i]) << "Vectors differ at index " << i;
}

// NIST SP 800-38A, Appendix F.5.1
const uint8_t key[16] = {
	0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
};

const uint8_t iv[16] = {
	0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};

const uint8_t plaintext[4*16] = {
	0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
	0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
	0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
	0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10
};

const uint8_t ciphertext[4*16] = {
	0x87, 0x4d, 0x61, 0x91, 0xb6, 0x20, 0xe3, 0x26, 0x1b, 0xef, 0x68, 0x64, 0x99, 0x0d, 0xb6, 0xce,
	0x98, 0x06, 0xf6, 0x6b, 0x79, 0x70, 0xfd, 0xff, 0x86, 0x17, 0x18, 0x7b, 0xb9, 0xff, 0xfd, 0xff,
	0x5a, 0xe4, 0xdf, 0x3e, 0xdb, 0xd5, 0xd3, 0x5e, 0x5b, 0x4f, 0x09, 0x02, 0x0d, 0xb0, 0x3e, 0xab,
	0x1e, 0x03, 0x1d, 0xda, 0x2f, 0xbe, 0x03, 0xd1, 0x79, 0x21, 0x70, 0xa0, 0xf3, 0x00, 0x9c, 0xee
};


TEST(AESTest, EncryptCTR_AES128_Manual) {
	// NIST SP 800-38A, Appendix F.5.1
	const uint8_t output[4][16] = {
		{ 0xec, 0x8c, 0xdf, 0x73, 0x98, 0x60, 0x7c, 0xb0, 0xf2, 0xd2, 0x16, 0x75, 0xea, 0x9e, 0xa1, 0xe4 },
		{ 0x36, 0x2b, 0x7c, 0x3c, 0x67, 0x73, 0x51, 0x63, 0x18, 0xa0, 0x77, 0xd7, 0xfc, 0x50, 0x73, 0xae },
		{ 0x6a, 0x2c, 0xc3, 0x78, 0x78, 0x89, 0x37, 0x4f, 0xbe, 0xb4, 0xc8, 0x1b, 0x17, 0xba, 0x6c, 0x44 },
		{ 0xe8, 0x9c, 0x39, 0x9f, 0xf0, 0xf1, 0x98, 0xc6, 0xd4, 0x0a, 0x31, 0xdb, 0x15, 0x6c, 0xab, 0xfe },
	};

	AES<128> aes;
	aes.setKey(key);
	uint8_t counter[16];
	memcpy(counter, iv, 16);

	for (int i = 0; i < 4; ++i) {
		uint8_t result[16] = { 0 };
		aes.encryptBlock(counter, result);
		for (int j = 0; j < 16; ++j) {
			EXPECT_EQ(result[j], output[i][j]) << "Vectors differ at row " << i << " index " << j;
		}
		counterInc(counter);
	}
}

TEST(AESTest, EncryptCTR_AES128) {
	AES<128> aes;
	aes.setKey(key);

	// Block-aligned access
	uint8_t result[20] = { 0 };
	for (int i = 0; i < 4; ++i) {
		encryptCTR(aes, iv, plaintext + 16 * i, result, 16, 16 * i);
		for (int j = 0; j < 16; ++j) {
			EXPECT_EQ(result[j], ciphertext[16 * i + j]) << "Vectors differ at row " << i << " index " << j;
		}
	}

	// Unaligned access
	for (int ofs = 1; ofs < 24; ++ofs)
		for (int len = 0; len < 20; ++len) {
			encryptCTR(aes, iv, plaintext + ofs, result, len, ofs);
			for (int j = 0; j < len; ++j) {
				EXPECT_EQ(result[j], ciphertext[ofs + j]) << "Vectors differ at ofs " << ofs << " len " << len << " position " << j;
			}
		}
}

TEST(AESTest, DecryptCTR_AES128) {
	AES<128> aes;
	aes.setKey(key);

	// Block-aligned access
	uint8_t result[20] = { 0 };
	for (int i = 0; i < 4; ++i) {
		decryptCTR(aes, iv, ciphertext + 16 * i, result, 16, 16 * i);
		for (int j = 0; j < 16; ++j) {
			EXPECT_EQ(result[j], plaintext[16 * i + j]) << "Vectors differ at row " << i << " index " << j;
		}
	}

	// Unaligned access
	for (int ofs = 1; ofs < 24; ++ofs)
		for (int len = 0; len < 20; ++len) {
			decryptCTR(aes, iv, ciphertext + ofs, result, len, ofs);
			for (int j = 0; j < len; ++j) {
				EXPECT_EQ(result[j], plaintext[ofs + j]) << "Vectors differ at ofs " << ofs << " len " << len << " position " << j;
			}
		}
}
