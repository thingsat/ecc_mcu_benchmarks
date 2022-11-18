/*
 * Copyright (C) 2022 Université Grenoble Alpes
 * 
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
 * @brief       speed bench unkeyed cryptographic hash algorithms from riot-os 
 *
 * @author      Aymeric Brochier <aymeric.brochier@univ-grenoble-alpes.fr>
 *
 * @}
 */

#include <stdio.h>
#include <string.h>

#include "hashes/sha1.h"
#include "hashes/md5.h"
#include "hashes/sha224.h"
#include "hashes/sha256.h"
#include "hashes/sha3.h"

#include "xtimer.h"

#define MAX_DATA_SIZE	            1024
#define NAME_MAX_SIZE               10
#define LEN_DATA_SIZE               7

#define ALGO_SIZE                   7
//specific case for sha_224 and sha_256
#define NB_ALGO_WITH_RETURN_VALUE   2

static uint8_t data[MAX_DATA_SIZE];
static uint32_t len_data[LEN_DATA_SIZE] = {16, 32, 64, 128, 256, 512, 1024};

static uint8_t algo_name[ALGO_SIZE][NAME_MAX_SIZE] = {
    "sha224\0",
    "sha256\0",
    "sha3_256\0",
    "sha3_384\0",
    "sha3_512\0",
    "sha1\0",
    "md5\0"
    };


static uint8_t digest_sha224[SHA224_DIGEST_LENGTH]      =    {0};
static uint8_t digest_sha256[SHA256_DIGEST_LENGTH]      =    {0};
static uint8_t digest_sha3_256[SHA3_256_DIGEST_LENGTH]  =    {0};
static uint8_t digest_sha3_384[SHA3_384_DIGEST_LENGTH]  =    {0};
static uint8_t digest_sha3_512[SHA3_512_DIGEST_LENGTH]  =    {0};
static uint8_t digest_sha1[SHA1_DIGEST_LENGTH]          =    {0};
static uint8_t digest_md5[MD5_DIGEST_LENGTH]            =    {0};

static uint8_t digest_size[ALGO_SIZE]={
    SHA224_DIGEST_LENGTH,
    SHA256_DIGEST_LENGTH,
    SHA3_256_DIGEST_LENGTH,
    SHA3_384_DIGEST_LENGTH,
    SHA3_512_DIGEST_LENGTH,
    SHA1_DIGEST_LENGTH,
    MD5_DIGEST_LENGTH
    };
static uint8_t* digest[ALGO_SIZE] = {
    digest_sha224,
    digest_sha256,
    digest_sha3_256,
    digest_sha3_384,
    digest_sha3_512,
    digest_sha1,
    digest_md5
    };

//two signature type for the hash functions
typedef struct hash_function_pointer hash_function_pointer;
struct hash_function_pointer{
    void (*fun)(void *digest, const void *data, size_t len);
    void * (*fun_with_return_value)(const void *data, size_t len, void *digest);

};

static void init_hash_function_pointer( hash_function_pointer *b,void (*f)(void *digest, const void *data, size_t len))
{
    b->fun = f;
}
static void init_hash_function_pointer_with_return_value( hash_function_pointer *b,void * (*f)(const void *, size_t,  void *))
{
    b->fun_with_return_value = f;
}

int main(void)
{
    uint32_t i = 0;
    uint8_t j = 0;
    uint32_t k = 0;

    hash_function_pointer _sha_224, _sha_256, _sha3_256, _sha3_384,_sha3_512, _sha1, _md5;
    hash_function_pointer *hash_functions[ALGO_SIZE]={
        &_sha_224,
        &_sha_256,
        &_sha3_256,
        &_sha3_384,
        &_sha3_512,
        &_sha1,
        &_md5};

    init_hash_function_pointer_with_return_value(&_sha_224,sha224);
    init_hash_function_pointer_with_return_value(&_sha_256,sha256);

    init_hash_function_pointer(&_sha3_256,sha3_256);
    init_hash_function_pointer(&_sha3_384,sha3_384);
    init_hash_function_pointer(&_sha3_512,sha3_512);

    init_hash_function_pointer(&_sha1,sha1);
    init_hash_function_pointer(&_md5,md5);

    
	printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
	printf("This board features a(n) %s MCU.\n", RIOT_MCU);
    printf("MD5 and SHA-1 are deprecated do not use on production for security purposes\n");

    uint32_t len = 0;
    uint32_t start, stop;
    uint32_t time_counter = 0;

	for(i = 0; i < MAX_DATA_SIZE; i++){
		data[i] = (uint8_t)(i & 0xFF);
	}
    
    for(i = 0; i < ALGO_SIZE; i++){
        printf("\nalgo is %s\n",algo_name[i]);
        printf("digest size is %u\n",digest_size[i]);
        for( j = 0; j < LEN_DATA_SIZE; j++){
            len = len_data[j];
            time_counter = 0;
            //printf("data size is = %lu\n",len);

            for (k = 0; k < BENCH_SIZE; k++) {
                if (i < NB_ALGO_WITH_RETURN_VALUE){
                    //special case because sha-224 and sha-256 
                    //have differente signatures 
                    start = xtimer_now_usec();
                    hash_functions[i]->fun_with_return_value(digest[i], len, data);
                    stop = xtimer_now_usec();
                }else{
                    start = xtimer_now_usec();
                    hash_functions[i]->fun(digest[i], data, len);
                    stop = xtimer_now_usec();
                }
                time_counter += stop - start;
            }
            printf("hash %s: %u calls for %lu bytes in %lu usec (%f usec per call)\n", algo_name[i], BENCH_SIZE, len, time_counter, (time_counter)*1.0/BENCH_SIZE);
        }
    }
    return 0;
}
