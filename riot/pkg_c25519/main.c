/*
 * Copyright (C) 2018 Freie Universität Berlin
 * Copyright (C) 2018 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     tests
 * @{
 *
 * @file
 * @brief       Tests c25519 package
 *
 * @author      Koen Zandberg <koen@bergzand.net>
 *
 * @}
 */

#include <stdio.h>
#include <string.h>

#include "edsign.h"
#include "ed25519.h"
#include "embUnit.h"
#include "random.h"
#include "xtimer.h"

static uint8_t message[] = "0123456789abcdef";

static uint8_t sign_sk[EDSIGN_SECRET_KEY_SIZE];
static uint8_t sign_pk[EDSIGN_PUBLIC_KEY_SIZE];
static uint8_t signature[EDSIGN_SIGNATURE_SIZE];

static void setUp(void)
{
    /* Initialize */
    random_init(0);
}

// https://superuser.com/questions/1700544/extracting-a-public-key-from-an-ed25519-private-key-with-openssl
// 55a989ff76aec94f51ddee6380a5aee74ae91da69985a3093804a7121c107b71
static uint8_t priv[EDSIGN_SECRET_KEY_SIZE] = {
		0x55, 0xa9, 0x89, 0xff,
		0x76, 0xae, 0xc9, 0x4f,
		0x51, 0xdd, 0xee, 0x63,
		0x80, 0xa5, 0xae, 0xe7,
		0x4a, 0xe9, 0x1d, 0xa6,
		0x99, 0x85, 0xa3, 0x09,
		0x38, 0x04, 0xa7, 0x12,
		0x1c, 0x10, 0x7b, 0x71
};

// 0618C713A00E6B7DEAD891A5564F4E8C8091A764BA77D9D4261D17AFA3D47A0A
static uint8_t pub[EDSIGN_PUBLIC_KEY_SIZE] = {
		0x06, 0x18, 0xc7, 0x13,
		0xa0, 0x0e, 0x6b, 0x7d,
		0xea, 0xd8, 0x91, 0xa5,
		0x56, 0x4f, 0x4e, 0x8c,
		0x80, 0x91, 0xa7, 0x64,
		0xba, 0x77, 0xd9, 0xd4,
		0x26, 0x1d, 0x17, 0xaf,
		0xa3, 0xd4, 0x7a, 0x0a
};

// Online Generate/Sign/Verify https://cyphr.me/ed25519_applet/ed.html


// https://cryptography.io/en/latest/hazmat/primitives/asymmetric/ed25519/

/*
SEQUENCE (3 elem)
  INTEGER 0
  SEQUENCE (1 elem)
    OBJECT IDENTIFIER 1.3.101.112 curveEd25519 (EdDSA 25519 signature algorithm)
  OCTET STRING (34 byte) 0420A46A02C64470FB9C0C03C06E0674CA081BACBB53F2A8A682C6C23EF78CBB7A8A
    OCTET STRING (32 byte) A46A02C64470FB9C0C03C06E0674CA081BACBB53F2A8A682C6C23EF78CBB7A8A
*/

// A46A02C64470FB9C0C03C06E0674CA081BACBB53F2A8A682C6C23EF78CBB7A8A
// D0D1CD73A2F485D3E6F2CC927EDAB9BF2766D51D670DCF0642AA8D5CC87450A5
static uint8_t priv2[EDSIGN_SECRET_KEY_SIZE] = {
		0xA4, 0x6A, 0x02, 0xC6, 0x44, 0x70, 0xFB, 0x9C,
		0x0C, 0x03, 0xC0, 0x6E, 0x06, 0x74, 0xCA, 0x08,
		0x1B, 0xAC, 0xBB, 0x53, 0xF2, 0xA8, 0xA6, 0x82,
		0xC6, 0xC2, 0x3E, 0xF7, 0x8C, 0xBB, 0x7A, 0x8A
};


static uint8_t pub_from_priv[EDSIGN_PUBLIC_KEY_SIZE];


// echo $HEXSTR  | xxd -r -p | xxd -i -c 8
// DD82B72B362625A7C9930577E23170207E66B16277D720D053721623699A37BC
static uint8_t priv3[EDSIGN_SECRET_KEY_SIZE] = {
		  0xdd, 0x82, 0xb7, 0x2b, 0x36, 0x26, 0x25, 0xa7,
		  0xc9, 0x93, 0x05, 0x77, 0xe2, 0x31, 0x70, 0x20,
		  0x7e, 0x66, 0xb1, 0x62, 0x77, 0xd7, 0x20, 0xd0,
		  0x53, 0x72, 0x16, 0x23, 0x69, 0x9a, 0x37, 0xbc
};

// 760FB04B9B0EEE33E70A8BBD033020497A21B11456E623BF48949FC71665E785
static uint8_t pub3[EDSIGN_PUBLIC_KEY_SIZE] = {
		  0x76, 0x0f, 0xb0, 0x4b, 0x9b, 0x0e, 0xee, 0x33,
		  0xe7, 0x0a, 0x8b, 0xbd, 0x03, 0x30, 0x20, 0x49,
		  0x7a, 0x21, 0xb1, 0x14, 0x56, 0xe6, 0x23, 0xbf,
		  0x48, 0x94, 0x9f, 0xc7, 0x16, 0x65, 0xe7, 0x85
};

// echo $HEXSTR  | xxd -r -p | xxd -i -c 8
// 7143CE58828A9720B577F27819B1C0F41E3AC05FA0BCD8B3A1F8E02A58BD298B
static uint8_t priv4[EDSIGN_SECRET_KEY_SIZE] = {
		  0x71, 0x43, 0xce, 0x58, 0x82, 0x8a, 0x97, 0x20,
		  0xb5, 0x77, 0xf2, 0x78, 0x19, 0xb1, 0xc0, 0xf4,
		  0x1e, 0x3a, 0xc0, 0x5f, 0xa0, 0xbc, 0xd8, 0xb3,
		  0xa1, 0xf8, 0xe0, 0x2a, 0x58, 0xbd, 0x29, 0x8b
};

// 4477066BF555482A14EE98869539031CEA83B79C08567F879163F7C538625A19
static uint8_t pub4[EDSIGN_PUBLIC_KEY_SIZE] = {
		  0x44, 0x77, 0x06, 0x6b, 0xf5, 0x55, 0x48, 0x2a,
		  0x14, 0xee, 0x98, 0x86, 0x95, 0x39, 0x03, 0x1c,
		  0xea, 0x83, 0xb7, 0x9c, 0x08, 0x56, 0x7f, 0x87,
		  0x91, 0x63, 0xf7, 0xc5, 0x38, 0x62, 0x5a, 0x19
};


static void test_c25519_signverify(void)
{
	printf("%s\n",__FUNCTION__);
    int res;
    /* Creating keypair ... */
    random_bytes(sign_sk, sizeof(sign_sk));
    ed25519_prepare(sign_sk);
    edsign_sec_to_pub(sign_pk, sign_sk);

    /* Sign */
    edsign_sign(signature, sign_pk, sign_sk, message, sizeof(message));

    /* Verifying... */
    res = edsign_verify(signature, sign_pk, message, sizeof(message));
    TEST_ASSERT(res);
}

static void test_c25519_verifynegative(void)
{
	printf("%s\n",__FUNCTION__);
    int res;

    /* changing message */
    message[0] = 'A';

    /* Verifying... */
    res = edsign_verify(signature, sign_pk, message, sizeof(message));
    TEST_ASSERT_EQUAL_INT(0, res);
}



static void test_c25519_signverify_1(void)
{
	printf("%s\n",__FUNCTION__);
    int res;
    ed25519_prepare(priv);
    edsign_sec_to_pub(pub_from_priv, priv);

    /* */
    TEST_ASSERT(memcmp(pub_from_priv, pub, EDSIGN_PUBLIC_KEY_SIZE));

    /* Sign */
    edsign_sign(signature, pub_from_priv, priv, message, sizeof(message));

    /* Verifying... */
    res = edsign_verify(signature, pub_from_priv, message, sizeof(message));
    TEST_ASSERT(res);
}

static void test_c25519_signverify_2(void)
{
	printf("%s\n",__FUNCTION__);
    int res;
    ed25519_prepare(priv2);
    edsign_sec_to_pub(pub_from_priv, priv2);

    /* */
    //TEST_ASSERT(memcmp(pub_from_priv, pub, EDSIGN_PUBLIC_KEY_SIZE));

    /* Sign */
    edsign_sign(signature, pub_from_priv, priv2, message, sizeof(message));

    /* Verifying... */
    res = edsign_verify(signature, pub_from_priv, message, sizeof(message));
    TEST_ASSERT(res);
}

static void test_c25519_signverify_3(void)
{
	printf("%s\n",__FUNCTION__);
    int res;
    ed25519_prepare(priv3);
    edsign_sec_to_pub(pub_from_priv, priv3);

    /* */
    TEST_ASSERT(memcmp(pub_from_priv, pub3, EDSIGN_PUBLIC_KEY_SIZE));

    /* Sign */
    edsign_sign(signature, pub_from_priv, priv3, message, sizeof(message));

    /* Verifying... */
    res = edsign_verify(signature, pub_from_priv, message, sizeof(message));
    TEST_ASSERT(res);
}

static void test_c25519_signverify_4(void)
{
	printf("%s\n",__FUNCTION__);
    int res;
    ed25519_prepare(priv4);
    edsign_sec_to_pub(pub_from_priv, priv4);

    /* */
    TEST_ASSERT(memcmp(pub_from_priv, pub4, EDSIGN_PUBLIC_KEY_SIZE));

    /* Sign */
    edsign_sign(signature, pub_from_priv, priv4, message, sizeof(message));

    /* Verifying... */
    res = edsign_verify(signature, pub_from_priv, message, sizeof(message));
    TEST_ASSERT(res);
}

#ifndef BENCH_SIZE
#define BENCH_SIZE 10U
#endif


static void _test_c25519_signverify_bench(uint8_t* message, size_t message_len)
{
	printf("%s\n",__FUNCTION__);
    int res;
    ed25519_prepare(priv4);
    edsign_sec_to_pub(pub_from_priv, priv4);

    /* */
    TEST_ASSERT(memcmp(pub_from_priv, pub4, EDSIGN_PUBLIC_KEY_SIZE));


    uint32_t start, stop;

	start = xtimer_now_usec();
	for (uint32_t i = 0; i < BENCH_SIZE; ++i) {
	    /* Sign */
	    edsign_sign(signature, pub_from_priv, priv4, message, message_len);
	}
    stop = xtimer_now_usec();

	printf("Sign: %u calls for %u bytes in %lu usec (%f usec per call)\n", BENCH_SIZE, message_len, stop-start, (stop-start)*1.0/BENCH_SIZE);

	start = xtimer_now_usec();
	for (uint32_t i = 0; i < BENCH_SIZE; ++i) {
	    /* Verifying... */
	    res = edsign_verify(signature, pub_from_priv, message, message_len);
	}
    stop = xtimer_now_usec();

	printf("Verify: %u calls for %u bytes in %lu usec (%f usec per call)\n", BENCH_SIZE, message_len, stop-start, (stop-start)*1.0/BENCH_SIZE);

    /* Verifying... */
    res = edsign_verify(signature, pub_from_priv, message, sizeof(message));
    TEST_ASSERT(res);
}

#define MSG_SIZE	1024

static void test_c25519_signverify_bench(void)
{
	printf("%s\n",__FUNCTION__);

	size_t i=0;
	uint8_t message[MSG_SIZE];
	for(i=0;i<MSG_SIZE;i++){
		message[i] = (uint8_t)(i & 0xFF);
	}

	_test_c25519_signverify_bench(message, 16);
	_test_c25519_signverify_bench(message, 32);
	_test_c25519_signverify_bench(message, 48);
	_test_c25519_signverify_bench(message, 64);
	_test_c25519_signverify_bench(message, 128);
	_test_c25519_signverify_bench(message, 256);
	_test_c25519_signverify_bench(message, 512);
	_test_c25519_signverify_bench(message, MSG_SIZE);
}

Test *tests_c25519(void)
{
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture(test_c25519_signverify),
		new_TestFixture(test_c25519_signverify_1),
		new_TestFixture(test_c25519_signverify_2),
		new_TestFixture(test_c25519_signverify_3),
		new_TestFixture(test_c25519_signverify_4),
		new_TestFixture(test_c25519_signverify_bench),
        new_TestFixture(test_c25519_verifynegative)
    };

    EMB_UNIT_TESTCALLER(c25519_tests, setUp, NULL, fixtures);
    return (Test*)&c25519_tests;
}

int main(void)
{

	printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
	printf("This board features a(n) %s MCU.\n", RIOT_MCU);

    TESTS_START();
    TESTS_RUN(tests_c25519());
    TESTS_END();

    return 0;
}
