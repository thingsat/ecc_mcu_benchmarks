/* Copyright 2014, Kenneth MacKay. Licensed under the BSD 2-clause license. */

#include "uECC.h"

#include <stdio.h>
#include <string.h>
#include "xtimer.h"

int bench_ecc(void) {


	printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
	printf("This board features a(n) %s MCU.\n", RIOT_MCU);

    int i, c;
    uint8_t private[32] = {0};
    uint8_t public[64] = {0};
    uint8_t hash[64] = {0};
    uint8_t size_of_hash[5] = {40,48,56,64,64};
    uint8_t sig[64] = {0};

    const struct uECC_Curve_t * curves[5];
    int num_curves = 0;
#if uECC_SUPPORTS_secp160r1
	printf("Curve #%d : uECC_secp160r1\n", num_curves);
    curves[num_curves++] = uECC_secp160r1();
#endif
#if uECC_SUPPORTS_secp192r1
	printf("Curve #%d : uECC_secp192r1\n", num_curves);
    curves[num_curves++] = uECC_secp192r1();
#endif
#if uECC_SUPPORTS_secp224r1
	printf("Curve #%d : uECC_secp224r1\n", num_curves);
    curves[num_curves++] = uECC_secp224r1();
#endif
#if uECC_SUPPORTS_secp256r1
	printf("Curve #%d : uECC_secp256r1\n", num_curves);
    curves[num_curves++] = uECC_secp256r1();
#endif
#if uECC_SUPPORTS_secp256k1
	printf("Curve #%d : uECC_secp256k1\n", num_curves);
    curves[num_curves++] = uECC_secp256k1();
#endif

    uint32_t start, stop;
    uint32_t X = 256;
    uint32_t sign_sum,verify_sum;
    printf("Testing %lu signatures\n",X);
    for (c = 0; c < num_curves; ++c) {
        sign_sum = 0;
        verify_sum = 0;
        printf("Curve %u : Private key size: %d, Public key size: %d\n",
        			c,
        			uECC_curve_private_key_size(curves[c]),
					uECC_curve_public_key_size(curves[c])
        	);
        for (i = 0; i < 256; ++i) {

        	start = xtimer_now_usec();
            if (!uECC_make_key(public, private, curves[c])) {
                printf("uECC_make_key() failed\n");
                return 1;
            }
            stop = xtimer_now_usec();

            //printf("Curve %u : Make Key: %lu usec\n", c, stop-start);
            memcpy(hash, public, size_of_hash[c]);

        	start = xtimer_now_usec();
            if (!uECC_sign(private, hash, size_of_hash[c], sig, curves[c])) {
                printf("uECC_sign() failed\n");
                return 1;
            }
            stop = xtimer_now_usec();
            //printf("Curve %u : Sign: %lu usec\n", c, stop-start);
            sign_sum += stop-start;
        	start = xtimer_now_usec();
            if (!uECC_verify(public, hash, size_of_hash[c], sig, curves[c])) {
                printf("uECC_verify() failed\n");
                return 1;
            }
            stop = xtimer_now_usec();
            //printf("Curve %u : Verify: %lu usec\n", c, stop-start);
            verify_sum += stop-start;

        }
        printf("\n");
        printf("Curve %u : Sign: %lu usec\n", c, sign_sum/X);
        printf("Curve %u : Verify: %lu usec\n", c, verify_sum/X);
        printf("\n");
    }

    return 0;
}
