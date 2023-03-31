/*
 * Copyright (C) 2018 Silke Hofstra
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
 * @brief       Test the libhydrogen package
 *
 * @author      Silke Hofstra <silke@slxh.eu>
 *
 * @}
 */

#include <stdio.h>
#include <string.h>

#include "xtimer.h"

#include "embUnit.h"
#include "hydrogen.h"

#define MSG_SIZE	1024
static char context[] = "examples";
static uint8_t message[MSG_SIZE] = "0123456789abcdef";

/* This performs setup, but should never fail */
static void test_hydro_init(void)
{
    TEST_ASSERT(hydro_init() == 0);
}

/* Test public-key signatures */
static void test_hydro_signverify(uint8_t* message, size_t message_len)
{
    printf("%s\n",__FUNCTION__);
 
    hydro_sign_keypair key_pair;

    hydro_sign_keygen(&key_pair);

    uint8_t signature[hydro_sign_BYTES];

    uint32_t start, stop;

	start = xtimer_now_usec();
	for (uint32_t i = 0; i < BENCH_SIZE; ++i) {
	    /* Sign */
        hydro_sign_create(signature, message, message_len, context, key_pair.sk);
	}
    stop = xtimer_now_usec();
	printf("Sign: %u calls for %u bytes in %lu usec (%f usec per call)\n", BENCH_SIZE, message_len, stop-start, (stop-start)*1.0/BENCH_SIZE);

    int res;
	start = xtimer_now_usec();
	for (uint32_t i = 0; i < BENCH_SIZE; ++i) {
	    /* Verifying... */
        res = hydro_sign_verify(signature, message, message_len, context, key_pair.pk);
	}
    stop = xtimer_now_usec();
    TEST_ASSERT(res == 0);
    printf("Verify: %u calls for %u bytes in %lu usec (%f usec per call)\n", BENCH_SIZE, message_len, stop-start, (stop-start)*1.0/BENCH_SIZE);

    TEST_ASSERT(res == 0);
}

//use static variable message
static void test_hydro_signverify_bench(void)
{
	printf("%s\n",__FUNCTION__);
	size_t i = 0;
	for(i = 0; i < MSG_SIZE; i++){
		message[i] = (uint8_t)(i & 0xFF);
	}
    test_hydro_signverify(message, 16);
    test_hydro_signverify(message, 32);
    test_hydro_signverify(message, 128);
    test_hydro_signverify(message, 1024);
}
/* Test secret-key encryption */
static void test_hydro_secretbox_encryptdecrypt(void)
{
    printf("%s\n",__FUNCTION__);

    uint8_t key[hydro_secretbox_KEYBYTES];
    uint8_t ciphertext[hydro_secretbox_HEADERBYTES + sizeof message];

    hydro_secretbox_keygen(key);
    hydro_secretbox_encrypt(ciphertext, message, sizeof message, 0, context, key);

    char decrypted[sizeof message];
    int res = hydro_secretbox_decrypt(
        decrypted,
        ciphertext,
        hydro_secretbox_HEADERBYTES + sizeof message,
        0,
        context,
        key
        );

    TEST_ASSERT(res == 0);
}

Test *tests_libhydrogen(void)
{
    printf("%s\n",__FUNCTION__);

    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture(test_hydro_init),
        //new_TestFixture(test_hydro_signverify),
        new_TestFixture(test_hydro_signverify_bench),
        new_TestFixture(test_hydro_secretbox_encryptdecrypt),
    };
    EMB_UNIT_TESTCALLER(libhydrogen_tests, NULL, NULL, fixtures);
    return (Test *)&libhydrogen_tests;
}

int main(void)
{
    TESTS_START();
    TESTS_RUN(tests_libhydrogen());
    TESTS_END();
    return 0;
}
