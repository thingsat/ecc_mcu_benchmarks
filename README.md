# Elliptic Curve Cryptography (ECC) benchmarks for MCU

Authors: Didier Donsez, Aymeric Brochier, Olivier Alphand.

Status : Draft

## Motivations

[c25519](https://api.riot-os.org/group__pkg__c25519.html) is the default RIOT package used for verifying [SUIT manifests](https://api.riot-os.org/group__sys__suit.html) for FUOTS ([Firmware Update Over The Space](https://github.com/thingsat/Cubedate)), for signing and verifying [XBeacons](https://gricad-gitlab.univ-grenoble-alpes.fr/thingsat/public/-/blob/master/cubesat_mission/messages/lorawan_xbeacon.h) in the [Thingsat cubesat mission](https://gricad-gitlab.univ-grenoble-alpes.fr/thingsat/public/-/tree/master/cubesat_mission).

This benchmarks suite measures the performance of various implementations of ECC algorithms for signing and verifying on various MCU boards. 

> For FlashRAM and RAM footprints, have a glance on the [SUIT paper](https://ieeexplore.ieee.org/stamp/stamp.jsp?arnumber=8725488) in tables 6 and 7.


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
| Nucleo F466RE | [STM32F446RE](https://www.st.com/resource/en/datasheet/stm32f446re.pdf) (Cortex M4) | 180 MHz, 225 DMIPS |  |   | [Arduino](https://github.com/stm32duino/Arduino_Core_STM32), RIOT, MBed, FreeRTOS, STM32CubeMX  |
| Nucleo F103RB | [STM32F103RB](https://www.st.com/en/microcontrollers-microprocessors/stm32f103rb.html) (Cortex M3) | 72 MHz, 90 DMIPS |  |  | [Arduino](https://github.com/stm32duino/Arduino_Core_STM32), RIOT, MBed, FreeRTOS, STM32CubeMX |
| [ST Nucleo F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html) | [STM32F446RE](https://www.st.com/resource/en/datasheet/stm32f446re.pdf) (Cortex M4) | 180 MHz, 225 DMIPS |  |   | [Arduino](https://github.com/stm32duino/Arduino_Core_STM32), RIOT, MBed, FreeRTOS, STM32CubeMX  |
| Nucleo F103RB | [STM32F103RB](https://www.st.com/en/microcontrollers-microprocessors/stm32f103rb.html) (Cortex M3) | 72 MHz, 90 DMIPS | | | [Arduino](https://github.com/stm32duino/Arduino_Core_STM32), RIOT, MBed, FreeRTOS, STM32CubeMX |
| Nucleo L073RZ | [STM32L073RZ](https://www.st.com/en/microcontrollers-microprocessors/stm32l073rz.html) (Cortex M0+) |  32 MHz,  30.4 DMIPS | | | [Arduino](https://github.com/stm32duino/Arduino_Core_STM32), RIOT, MBed, FreeRTOS, STM32CubeMX |
| Nucleo L053R8 | [STM32L053R8](https://www.st.com/en/microcontrollers-microprocessors/stm32l053r8.html) (Cortex M0+) |  32 MHz,  30.4 DMIPS | | | [Arduino](https://github.com/stm32duino/Arduino_Core_STM32), RIOT, MBed, FreeRTOS, STM32CubeMX |
| [STM32F746NG Discovery](https://www.st.com/en/evaluation-tools/32f746gdiscovery.html) | [STM32F746NG](https://www.st.com/en/microcontrollers-microprocessors/stm32f746ng.html) (Cortex M7) |  160 MHz,  240 DMIPS | 340 Kbytes of RAM, 128-Mbit SDRAM (64 Mbits accessible) | 1 Mbyte of Flash memory, 128-Mbit Quad-SPI Flash memory | [Arduino](https://github.com/stm32duino/Arduino_Core_STM32), RIOT, MBed, FreeRTOS, STM32CubeMX |
| [ST B-U585I-IOT02A](https://www.st.com/en/evaluation-tools/b-u585i-iot02a.html) | [STM32U585AI](https://www.st.com/en/microcontrollers-microprocessors/stm32u585ai.html) (Cortex M33) |  216 MHz,  462 DMIPS | 786 Kbytes of SRAM | 2 Mbytes of Flash memory, 512-Mbit Quad-SPI Flash memory, 64-Mbit Octo-SPI PSRAM, 256-Kbit I2C EEPROM | Arduino, RIOT, MBed, FreeRTOS, STM32CubeMX |
| [IMST iM880b](https://wireless-solutions.de/products/lora-solutions-by-imst/radio-modules/im880b-l/) | [STM32L151CB-A](https://www.st.com/en/microcontrollers-microprocessors/stm32l151cb-a.html) (Cortex M3) |  32 MHz, 1.25 DMIPS/MHz | 32 Kbytes of RAM| 256 Kbytes of Flash memory with ECC, 8 Kbytes of true EEPROM with ECC | [RIOT](https://github.com/RIOT-OS/RIOT/tree/master/boards/im880b) |
| [Wyres Base](https://github.com/CampusIoT/RIOT-wyres) | [STM32L151CC](https://www.st.com/en/microcontrollers-microprocessors/stm32l151cc.html) (Cortex M3) |  32 MHz, 1.25 DMIPS/MHz | 32 Kbytes of RAM| 256 Kbytes of Flash memory with ECC, 8 Kbytes of true EEPROM with ECC | [RIOT](https://github.com/CampusIoT/RIOT-wyres/tree/main/boards/wyres-base) |
|ESP32-WROOM-32U | [ESP32 WROOM 32U](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32d_esp32-wroom-32u_datasheet_en.pdf) (dual-core Xtensa® 32-bit LX6 MCU) | 40 MHz, 100 DMIPS | | | Arduino, RIOT, MBed, FreeRTOS, STM32CubeMX |


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
* [Curve25519 makes use of a special x-coordinate only form to achieve faster multiplication. Ed25519 uses Edwards curve for similar speedups, but includes a sign bit](https://crypto.stackexchange.com/questions/27866/why-curve25519-for-encryption-but-ed25519-for-signatures#:~:text=Curve25519%20makes%20use%20of%20a,one%20of%20encryption%20or%20signing.)


### [`c25519`](https://api.riot-os.org/group__pkg__c25519.html)

| Board | Algo | Implementation | Message size | Signing | Verifying |
|-------|------|----------------|--------------|---------|-----------|
| [ST Nucleo F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html) | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 16 | 298718 | 692123 |
| [ST Nucleo F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html) | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 32 | 298720 | 692124 |
| [ST Nucleo F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html) | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 128 | 298968 | 692248 |
| [ST Nucleo F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html) | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 1024 | 300692 | 693110 |
|||||||
| ThingSat STM32F405RG | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 16 | 320036 | 741542 |
| ThingSat STM32F405RG | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 32 | 320038 | 741543|
| ThingSat STM32F405RG | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 128 | 320303  | 741675 |
| ThingSat STM32F405RG | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 1024 | 322147 |  742596|
|||||||
| Nucleo F103RB | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 16 | 1284209 | 2935644 |
| Nucleo F103RB | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 32 | 1284219 | 2935649 |
| Nucleo F103RB | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 128 | 1284905 | 2935990 |
| Nucleo F103RB | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 1024 | 1289673 | 2938374 |
|||||||
| [ST B-U585I-IOT02A](https://www.st.com/en/evaluation-tools/b-u585i-iot02a.html) | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 16 | 376222 | 878826 |
| [ST B-U585I-IOT02A](https://www.st.com/en/evaluation-tools/b-u585i-iot02a.html) | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 32 | 376224 | 878827 |
| [ST B-U585I-IOT02A](https://www.st.com/en/evaluation-tools/b-u585i-iot02a.html) | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 128 | 376455 | 878942 |
| [ST B-U585I-IOT02A](https://www.st.com/en/evaluation-tools/b-u585i-iot02a.html) | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 1024 | 378066 | 879747 |
|||||||
| [Wyres Base](https://github.com/CampusIoT/RIOT-wyres) | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 16 | 2322980 | 5446012 |
| [Wyres Base](https://github.com/CampusIoT/RIOT-wyres) | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 32 | 2322997 | 5446020 |
| [Wyres Base](https://github.com/CampusIoT/RIOT-wyres) | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 128 | 2323757 | 5446711 |
| [Wyres Base](https://github.com/CampusIoT/RIOT-wyres) | ED25519 | [c25519](https://api.riot-os.org/group__pkg__c25519.html) | 1024 | 2324425 | 5446730 |



### [`libhydrogen`](https://api.riot-os.org/group__pkg__libhydrogen.html)

| Board | Algo | Implementation | Message size | Signing | Verifying |
|-------|------|----------------|--------------|---------|-----------|
| [ST Nucleo F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html) | Curve25519  | [libhydrogen](https://api.riot-os.org/group__pkg__libhydrogen.html) | 16 | 32108 | 53686 |
| [ST Nucleo F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html) | Curve25519  | [libhydrogen](https://api.riot-os.org/group__pkg__libhydrogen.html) | 32 | 32124 | 53701 |
| [ST Nucleo F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html) | Curve25519  | [libhydrogen](https://api.riot-os.org/group__pkg__libhydrogen.html) | 128 | 32219 | 53796 |
| [ST Nucleo F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html) | Curve25519  | [libhydrogen](https://api.riot-os.org/group__pkg__libhydrogen.html) | 1024 | 33106 | 54683 |
|||||||
| [STM32F746NG Discovery](https://www.st.com/en/evaluation-tools/32f746gdiscovery.html) | Curve25519  | [libhydrogen](https://api.riot-os.org/group__pkg__libhydrogen.html) | 16 | 67123 | 111692 |
| [STM32F746NG Discovery](https://www.st.com/en/evaluation-tools/32f746gdiscovery.html) | Curve25519  | [libhydrogen](https://api.riot-os.org/group__pkg__libhydrogen.html) | 32 | 67153 | 111723 |
| [STM32F746NG Discovery](https://www.st.com/en/evaluation-tools/32f746gdiscovery.html) | Curve25519  | [libhydrogen](https://api.riot-os.org/group__pkg__libhydrogen.html) | 128 | 67339 | 111909 |
| [STM32F746NG Discovery](https://www.st.com/en/evaluation-tools/32f746gdiscovery.html) | Curve25519  | [libhydrogen](https://api.riot-os.org/group__pkg__libhydrogen.html) | 1024 | 69069 | 113639 |
|||||||
| [ST B-U585I-IOT02A](https://www.st.com/en/evaluation-tools/b-u585i-iot02a.html) | Curve25519  | [libhydrogen](https://api.riot-os.org/group__pkg__libhydrogen.html) | 16 | 31451 | 52602 |
| [ST B-U585I-IOT02A](https://www.st.com/en/evaluation-tools/b-u585i-iot02a.html) | Curve25519  | [libhydrogen](https://api.riot-os.org/group__pkg__libhydrogen.html) | 32 | 31466 | 52617 |
| [ST B-U585I-IOT02A](https://www.st.com/en/evaluation-tools/b-u585i-iot02a.html) | Curve25519  | [libhydrogen](https://api.riot-os.org/group__pkg__libhydrogen.html) | 128 | 31557 | 52708 |
| [ST B-U585I-IOT02A](https://www.st.com/en/evaluation-tools/b-u585i-iot02a.html) | Curve25519  | [libhydrogen](https://api.riot-os.org/group__pkg__libhydrogen.html) | 1024 | 32402 | 53553 |
|||||||
| [Wyres Base](https://github.com/CampusIoT/RIOT-wyres) | Curve25519  | [libhydrogen](https://api.riot-os.org/group__pkg__libhydrogen.html) | 16 | 222623 | 373435 |
| [Wyres Base](https://github.com/CampusIoT/RIOT-wyres) | Curve25519  | [libhydrogen](https://api.riot-os.org/group__pkg__libhydrogen.html) | 32 | 222722 | 373531 |
| [Wyres Base](https://github.com/CampusIoT/RIOT-wyres) | Curve25519  | [libhydrogen](https://api.riot-os.org/group__pkg__libhydrogen.html) | 128 | 223303 | 374135 |
| [Wyres Base](https://github.com/CampusIoT/RIOT-wyres) | Curve25519  | [libhydrogen](https://api.riot-os.org/group__pkg__libhydrogen.html) | 1024 | 228785 | 379620 |



### [`micro-ecc`](https://doc.riot-os.org/group__pkg__micro__ecc.html)

| Board | Algo | Implementation | Public Key Size	 | Signing | Verifying |
|-------|------|----------------|---------------------|--------|-----------|
| [ST Nucleo F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html) | [secp160r1](https://neuromancer.sk/std/secg/secp160r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 40 | 19008 | 20003 |
| [ST Nucleo F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html) | [secp192r1](https://neuromancer.sk/std/secg/secp192r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 48 | 17795 | 19080 |
| [ST Nucleo F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html) | [secp224r1](https://neuromancer.sk/std/secg/secp224r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 56 | 24773 | 26335 |
| [ST Nucleo F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html) | [secp256r1](https://neuromancer.sk/std/secg/secp256r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 64 | 47170 | 52012 |
| [ST Nucleo F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html) | [secp256k1](https://neuromancer.sk/std/secg/secp256k1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 64 | 39790 | 40286 |
|||||||
| ThingSat STM32F405RG | [secp160r1](https://neuromancer.sk/std/secg/secp160r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 40 | 20285 | 21362 |
| ThingSat STM32F405RG| [secp192r1](https://neuromancer.sk/std/secg/secp192r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 48 | 18979 | 20320 |
| ThingSat STM32F405RG | [secp224r1](https://neuromancer.sk/std/secg/secp224r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 56 | 26081 | 27787 |
| ThingSat STM32F405RG | [secp256r1](https://neuromancer.sk/std/secg/secp256r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 64 | 49310 |54364  |
| ThingSat STM32F405RG | [secp256k1](https://neuromancer.sk/std/secg/secp256k1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 64 | 41691  | 42105  |
|||||||
| Nucleo F103RB | [secp160r1](https://neuromancer.sk/std/secg/secp160r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 40 | 67316 | 72010 |
| Nucleo F103RB | [secp192r1](https://neuromancer.sk/std/secg/secp192r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 48 | 63340 | 69155 |
| Nucleo F103RB | [secp224r1](https://neuromancer.sk/std/secg/secp224r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 56 | 85427 | 93501 |
| Nucleo F103RB | [secp256r1](https://neuromancer.sk/std/secg/secp256r1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 64 | 150669 | 167259 |
| Nucleo F103RB | [secp256k1](https://neuromancer.sk/std/secg/secp256k1) | [Micro ECC](https://doc.riot-os.org/group__pkg__micro__ecc.html) | 64 | 146573 | 150771 |


## Running the benchmarks suite

### On RIOT

For `wyres-base` board
```bash
mkdir -p ~/github/campusiot
git clone git@github.com:CampusIoT/RIOT-wyres.git ~/github/campusiot/RIOT-wyres
```

```bash
cd riot/pkg_c25519
gmake BOARD=thingsat-up4 -j 16 flash term
gmake BOARD=nucleo-f446re -j 16 flash term
gmake BOARD=nucleo-f401re -j 16 flash term
gmake BOARD=nucleo-f411re -j 16 flash term
gmake BOARD=nucleo-f103rb -j 16 flash term
gmake BOARD=nucleo-l073rz -j 16 flash term
gmake BOARD=nucleo-l152re -j 16 flash term
gmake BOARD=nucleo-l476rg -j 16 flash term
gmake BOARD=stm32f746g-disco -j 16 flash term
gmake BOARD=lora-e5-dev -j 16 flash term
gmake BOARD=esp32-wroom-32 -j 16 flash term
gmake BOARD=stm32f746g-disco -j 16 flash term
gmake BOARD=wyres-base -j 16 flash term
gmake BOARD=im880b -j 16 flash term
gmake BOARD=b-u585i-iot02a -j 16 flash term
```

```bash
cd riot/pkg_micro-ecc
gmake BOARD=thingsat-up4 -j 16 flash term
gmake BOARD=nucleo-f446re -j 16 flash term
gmake BOARD=nucleo-f401re -j 16 flash term
gmake BOARD=nucleo-f411re -j 16 flash term
gmake BOARD=nucleo-f103rb -j 16 flash term
gmake BOARD=nucleo-l073rz -j 16 flash term
gmake BOARD=nucleo-l152re -j 16 flash term
gmake BOARD=nucleo-l476rg -j 16 flash term
gmake BOARD=stm32f746g-disco -j 16 flash term
gmake BOARD=lora-e5-dev -j 16 flash term
gmake BOARD=esp32-wroom-32 -j 16 flash term
gmake BOARD=stm32f746g-disco -j 16 flash term
gmake BOARD=wyres-base -j 16 flash term
gmake BOARD=im880b -j 16 flash term
gmake BOARD=b-u585i-iot02a -j 16 flash term
```

```bash
cd riot/pkg_libhydrogen
gmake BOARD=thingsat-up4 -j 16 flash term
gmake BOARD=nucleo-f446re -j 16 flash term
gmake BOARD=nucleo-f401re -j 16 flash term
gmake BOARD=nucleo-f411re -j 16 flash term
gmake BOARD=nucleo-f103rb -j 16 flash term
gmake BOARD=nucleo-l073rz -j 16 flash term
gmake BOARD=nucleo-l152re -j 16 flash term
gmake BOARD=nucleo-l476rg -j 16 flash term
gmake BOARD=stm32f746g-disco -j 16 flash term
gmake BOARD=lora-e5-dev -j 16 flash term
gmake BOARD=esp32-wroom-32 -j 16 flash term
gmake BOARD=stm32f746g-disco -j 16 flash term
gmake BOARD=wyres-base -j 16 flash term
gmake BOARD=im880b -j 16 flash term
gmake BOARD=b-u585i-iot02a -j 16 flash term
```

### On MBed

TBD

### On Arduino

TBD

## Annexes
* [NIST Special Publication 800-57 Part 1 Revision 4 Recommendation for Key Management Part 1: General](https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-57pt1r4.pdf)
* Kerry Maletsky, RSA vs. ECC Comparison for Embedded Systems, Microchip, https://ww1.microchip.com/downloads/en/DeviceDoc/00003442A.pdf
* G Neven, N. P. Smart and B.Warinschi, Hash function requirements for Schnorr signatures, Jour-
nal of Mathematical Cryptology, vol .3, issue 1, pp. 69-87, 2009.
* Thommas Pornin, Truncated EdDSA/ECDSA Signatures, https://eprint.iacr.org/2022/938.pdf
* [Embench™: An Evolving Benchmark Suite for Embedded IoT Computers from an Academic-Industrial Cooperative: Towards the Long Overdue and Deserved Demise of Dhrystone](https://www.sigarch.org/embench-recruiting-for-the-long-overdue-and-deserved-demise-of-dhrystone-as-a-benchmark-for-embedded-computing/) : [source code](https://github.com/embench/embench-iot/)

## TODO
* [X] Add [Lib Hydrogen](https://github.com/jedisct1/libhydrogen/blob/master/hydrogen.h) in benchmark
* [ ] Add [liblithium](https://github.com/teslamotors/liblithium) in benchmark
* [ ] Add [monocypher](https://api.riot-os.org/group__pkg__monocypher.html) in benchmark
* [ ] Investigate why f4 faster than f7 ! 
[f7-is-slower-than-my-f4](https://community.st.com/s/question/0D53W00000BrUpUSAV/f7-is-slower-than-my-f4-f7-running-on-double-the-frequency)
[perf](https://electronics.stackexchange.com/questions/508828/which-microcontroller-for-a-program-with-many-floating-point-operations?noredirect=1#comment1303043_508828)




