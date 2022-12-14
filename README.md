# Elliptic Curve Cryptography (ECC) benchmarks for MCU

Authors: Didier Donsez, Aymeric Brochier, Olivier Alphand.

Status : Draft

## Motivations

[c25519](https://api.riot-os.org/group__pkg__c25519.html) is the default RIOT package used for verifying [SUIT manifests](https://api.riot-os.org/group__sys__suit.html) for FUOTS ([Firmware Update Over The Space](https://github.com/thingsat/Cubedate)), for signing and verifying [XBeacons](https://gricad-gitlab.univ-grenoble-alpes.fr/thingsat/public/-/blob/master/cubesat_mission/messages/lorawan_xbeacon.h) in the [Thingsat cubesat mission](https://gricad-gitlab.univ-grenoble-alpes.fr/thingsat/public/-/tree/master/cubesat_mission).

This benchmarks suite measures the performance of various implementations of ECC algorithms for signing and verifying on various MCU boards. 

## Usual ECC algorithms

| Name | Private Key Size | Public Key Size | Signature Size | [Security Level](https://en.wikipedia.org/wiki/Security_level) |
|------|------------------|-----------------|----------------|----------------|
| [secp112r1](https://neuromancer.sk/std/secg/secp112r1) | 14 bytes | 28 bytes | 28 bytes | |
| [secp128r1](https://neuromancer.sk/std/secg/secp128r1) | 16 bytes | 32 bytes | 32 bytes | |
| [secp160r1](https://neuromancer.sk/std/secg/secp160r1) | 20 bytes | 40 bytes | 40 bytes | 80 bits|
| [secp192r1](https://neuromancer.sk/std/secg/secp192r1) | 24 bytes | 48 bytes | 48 bytes | |
| [secp224r1](https://neuromancer.sk/std/secg/secp224r1) | 28 bytes | 56 bytes | 56 bytes | 112 bits |
| [secp256r1](https://neuromancer.sk/std/secg/secp256r1) | 32 bytes | 64 bytes | 64 bytes | 128 bits |
| [secp256k1](https://neuromancer.sk/std/secg/secp256k1) | 32 bytes | 64 bytes | 64 bytes | 128 bits |
| [ed25519](https://neuromancer.sk/std/other/Ed25519)    | 32 bytes | 64 bytes | 64 bytes | 128 bits |

See https://neuromancer.sk/std/

Security equivalence can be found in Kerry Maletsky, RSA vs. ECC Comparison for Embedded Systems, Microchip, https://ww1.microchip.com/downloads/en/DeviceDoc/00003442A.pdf

![comparison](images/comparison.png)
![performance](images/performance.png)

[Common hash functions](https://en.wikipedia.org/wiki/SHA-1#Comparison_of_SHA_functions)

## Boards

| Board | MCU | Frequency and DMIPS | RAM | FlashRAM | Support |
|-------|-----|-----------------|-----|----------|---------|
| [Thingsat](https://gricad-gitlab.univ-grenoble-alpes.fr/thingsat/public/-/blob/master/cubesat_mission/README.md#board) | [STM32F405RG](https://www.st.com/en/microcontrollers-microprocessors/stm32f405rg.html) (Cortex M4) | 180 MHz, 210 DMIPS | 192 Kbytes | 1024  Kbytes | RIOT, FreeRTOS, STM32CubeMX |
| Nucleo F466RE | [STM32F446RE](https://www.st.com/resource/en/datasheet/stm32f446re.pdf) (Cortex M4) | 180 MHz, 225 DMIPS |  |   | Arduino, RIOT, MBed, FreeRTOS, STM32CubeMX  |
| Nucleo F103RB | [STM32F103RB](https://www.st.com/en/microcontrollers-microprocessors/stm32f103rb.html) (Cortex M3) | 72 MHz, 90 DMIPS |  |  | Arduino, RIOT, MBed, FreeRTOS, STM32CubeMX |
| Nucleo F446RE | [STM32F446RE](https://www.st.com/resource/en/datasheet/stm32f446re.pdf) (Cortex M4) | 180 MHz, 225 DMIPS |  |   | Arduino, RIOT, MBed, FreeRTOS, STM32CubeMX  |
| Nucleo F103RB | [STM32F103RB](https://www.st.com/en/microcontrollers-microprocessors/stm32f103rb.html) (Cortex M3) | 72 MHz, 90 DMIPS | | | Arduino, RIOT, MBed, FreeRTOS, STM32CubeMX |
| Nucleo L073RZ | [STM32L073RZ](https://www.st.com/en/microcontrollers-microprocessors/stm32l073rz.html) (Cortex M0+) |  32 MHz,  30.4 DMIPS | | | Arduino, RIOT, MBed, FreeRTOS, STM32CubeMX |
| Nucleo L053R8 | [STM32L053R8](https://www.st.com/en/microcontrollers-microprocessors/stm32l053r8.html) (Cortex M0+) |  32 MHz,  30.4 DMIPS | | | Arduino, RIOT, MBed, FreeRTOS, STM32CubeMX |
| STM32 F7 Discovery | [STM32F746NG](https://www.st.com/en/microcontrollers-microprocessors/stm32f746ng.html) (Cortex M7) |  216 MHz,  462 DMIPS | | | Arduino, RIOT, MBed, FreeRTOS, STM32CubeMX |
|ESP32-WROOM-32U | [ESP32 WROOM 32U](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32d_esp32-wroom-32u_datasheet_en.pdf) (dual-core Xtensa?? 32-bit LX6 MCU) | 40 MHz, 100 DMIPS | | | Arduino, RIOT, MBed, FreeRTOS, STM32CubeMX |

* DMIPS for Dhrystone 2.1 on STM32 MCU

### Supported by MBed

## Available implementations

### Implementations available in RIOT OS

Implementations are available as packages in [RIOT/pkg directory](https://github.com/RIOT-OS/RIOT/tree/master/pkg).
* [c25519](https://api.riot-os.org/group__pkg__c25519.html) on RIOT OS https://www.dlbeer.co.nz/oss/c25519.html
* [micro-ecc](https://doc.riot-os.org/group__pkg__micro__ecc.html) (uECC_secp160r1) on RIOT OS : https://github.com/kmackay/micro-ecc/blob/master/test/test_ecdsa.c
* monocypher https://monocypher.org/manual 
* qdsa https://www.cs.ru.nl/~jrenes  
* wolfcrypt https://github.com/wolfSSL/wolfssl

Hash functions in RIOT : https://api.riot-os.org/group__sys__hashes__unkeyed.html

### MBed


### Arduino

Highly-optimized ECC implementations for 8-bit AVR processors : WM-ECC, Nano-ECC, MIRACL, RELIC


## Results

* Signing and verifying time in micro-seconds per call

| Board | Algo | Implementation | Message size | Signing | Verifying |
|-------|------|----------------|--------------|---------|-----------|
| Nucleo F446RE | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 16 | 298718 | 692123 |
| Nucleo F446RE | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 32 | 298720 | 692124 |
| Nucleo F446RE | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 128 | 298968 | 692248 |
| Nucleo F446RE | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 1024 | 300692 | 693110 |
|||||||
| ThingSat | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 16 | 320036 | 741542 |
| ThingSat | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 32 | 320038 | 741543|
| ThingSat | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 128 | 320303  | 741675 |
| ThingSat | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 1024 | 322147 |  742596|
|||||||
| Nucleo F103RB | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 16 | 1284209 | 2935644 |
| Nucleo F103RB | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 32 | 1284219 | 2935649 |
| Nucleo F103RB | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 128 | 1284905 | 2935990 |
| Nucleo F103RB | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 1024 | 1289673 | 2938374 |

| Board | Algo | Implementation | Public Key Size	 | Signing | Verifying |
|-------|------|----------------|---------------------|--------|-----------|
| Nucleo F446RE | [secp160r1](https://neuromancer.sk/std/secg/secp160r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 40 | 19008 | 20003 |
| Nucleo F446RE | [secp192r1](https://neuromancer.sk/std/secg/secp192r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 48 | 17795 | 19080 |
| Nucleo F446RE | [secp224r1](https://neuromancer.sk/std/secg/secp224r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 56 | 24773 | 26335 |
| Nucleo F446RE | [secp256r1](https://neuromancer.sk/std/secg/secp256r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 64 | 47170 | 52012 |
| Nucleo F446RE | [secp256k1](https://neuromancer.sk/std/secg/secp256k1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 64 | 39790 | 40286 |
|||||||
| ThingSat | [secp160r1](https://neuromancer.sk/std/secg/secp160r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 40 | 20285 | 21362 |
| ThingSat| [secp192r1](https://neuromancer.sk/std/secg/secp192r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 48 | 18979 | 20320 |
| ThingSat | [secp224r1](https://neuromancer.sk/std/secg/secp224r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 56 | 26081 | 27787 |
| ThingSat | [secp256r1](https://neuromancer.sk/std/secg/secp256r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 64 | 49310 |54364  |
| ThingSat | [secp256k1](https://neuromancer.sk/std/secg/secp256k1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 64 | 41691  | 42105  |
|||||||
| Nucleo F103RB | [secp160r1](https://neuromancer.sk/std/secg/secp160r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 40 | 67316 | 72010 |
| Nucleo F103RB | [secp192r1](https://neuromancer.sk/std/secg/secp192r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 48 | 63340 | 69155 |
| Nucleo F103RB | [secp224r1](https://neuromancer.sk/std/secg/secp224r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 56 | 85427 | 93501 |
| Nucleo F103RB | [secp256r1](https://neuromancer.sk/std/secg/secp256r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 64 | 150669 | 167259 |
| Nucleo F103RB | [secp256k1](https://neuromancer.sk/std/secg/secp256k1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 64 | 146573 | 150771 |


## Running the benchmarks suite

### On RIOT


```bash
cd riot/pkg_c25519
gmake BOARD=thingsat-f4 -j 16 flash term
gmake BOARD=nucleo-f446re -j 16 flash term
gmake BOARD=nucleo-f401re -j 16 flash term
gmake BOARD=nucleo-f411re -j 16 flash term
gmake BOARD=nucleo-f103rb -j 16 flash term
gmake BOARD=nucleo-l073rz -j 16 flash term
gmake BOARD=nucleo-l152re -j 16 flash term
gmake BOARD=nucleo-l476rg -j 16 flash term
gmake BOARD=lora-e5-dev -j 16 flash term
gmake BOARD=esp32-wroom-32 -j 16 flash term
```

```bash
cd riot/pkg_micro-ecc
gmake BOARD=thingsat-f4 -j 16 flash term
gmake BOARD=nucleo-f446re -j 16 flash term
gmake BOARD=nucleo-f401re -j 16 flash term
gmake BOARD=nucleo-f411re -j 16 flash term
gmake BOARD=nucleo-f103rb -j 16 flash term
gmake BOARD=nucleo-l073rz -j 16 flash term
gmake BOARD=nucleo-l152re -j 16 flash term
gmake BOARD=nucleo-l476rg -j 16 flash term
gmake BOARD=lora-e5-dev -j 16 flash term
gmake BOARD=esp32-wroom-32 -j 16 flash term
```

### On MBed

TBD

### On Arduino

TBD

## Annexes

* Kerry Maletsky, RSA vs. ECC Comparison for Embedded Systems, Microchip, https://ww1.microchip.com/downloads/en/DeviceDoc/00003442A.pdf
* G Neven, N. P. Smart and B.Warinschi, Hash function requirements for Schnorr signatures, Jour-
nal of Mathematical Cryptology, vol .3, issue 1, pp. 69-87, 2009.
* Thommas Pornin, Truncated EdDSA/ECDSA Signatures, https://eprint.iacr.org/2022/938.pdf
* [Embench???: An Evolving Benchmark Suite for Embedded IoT Computers from an Academic-Industrial Cooperative: Towards the Long Overdue and Deserved Demise of Dhrystone](https://www.sigarch.org/embench-recruiting-for-the-long-overdue-and-deserved-demise-of-dhrystone-as-a-benchmark-for-embedded-computing/) : [source code](https://github.com/embench/embench-iot/)






