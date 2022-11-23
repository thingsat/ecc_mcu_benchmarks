

# unkeyed cryptographic hash algorithms
Authors: Didier Donsez, Aymeric Brochier, Olivier Alphand.

Status : Draft

This benchmarks suite measures the performance of various implementations of unkeyed cryptographic hash algorithms in [RIOT-OS](https://github.com/RIOT-OS/RIOT/) on multiple platforms

## Boards

| Board | MCU | Frequency and DMIPS | RAM | FlashRAM | Support |
|-------|-----|-----------------|-----|----------|---------|
| [Thingsat](https://gricad-gitlab.univ-grenoble-alpes.fr/thingsat/public/-/blob/master/cubesat_mission/README.md#board) | [STM32F405RG](https://www.st.com/en/microcontrollers-microprocessors/stm32f405rg.html) (Cortex M4) | 180 MHz, 210 DMIPS | 192 Kbytes | 1024  Kbytes | RIOT, FreeRTOS, STM32CubeMX |
| Nucleo F466RE | [STM32F446RE](https://www.st.com/resource/en/datasheet/stm32f446re.pdf) (Cortex M4) | 180 MHz, 225 DMIPS |  |   | Arduino, RIOT, MBed, FreeRTOS, STM32CubeMX  |
| Nucleo F103RB | [STM32F103RB](https://www.st.com/en/microcontrollers-microprocessors/stm32f103rb.html) (Cortex M3) | 72 MHz, 90 DMIPS |  |  | Arduino, RIOT, MBed, FreeRTOS, STM32CubeMX |
| Nucleo L073RZ | [STM32L073RZ](https://www.st.com/en/microcontrollers-microprocessors/stm32l073rz.html) (Cortex M0+) |  32 MHz,  30.4 DMIPS | | | Arduino, RIOT, MBed, FreeRTOS, STM32CubeMX |
| Nucleo L053R8 | [STM32L053R8](https://www.st.com/en/microcontrollers-microprocessors/stm32l053r8.html) (Cortex M0+) |  32 MHz,  30.4 DMIPS | | | Arduino, RIOT, MBed, FreeRTOS, STM32CubeMX |
This benchmarks suite measures the performance of various implementations of unkeyed cryptographic hash algorithms in [RIOT-OS](https://github.com/RIOT-OS/RIOT/).
## Usual unkeyed cryptographic  algorithms
|Algo|digest size|
|----|---------|
|sha224|28|
|sha256|32|
|sha3_256|32|
|sha3_384|48|
|sha3_512|64|
|sha1|20|
|md5|16|

### Implementations available in RIOT OS

Implementations are available internaly in [RIOT](https://github.com/RIOT-OS/RIOT/tree/master/sys/hashes).

see also [Common hash functions](https://en.wikipedia.org/wiki/SHA-1#Comparison_of_SHA_functions)

## Results :
Board|Algo|data_size (bytes)|time(micro-seconds)|
|----|----|-----------------|-------------------|
|nucleo-f446re|sha224|16|42.5|
|nucleo-f446re|sha224|32|42.6|
|nucleo-f446re|sha224|64|77.3|
|nucleo-f446re|sha224|128|109.9|
|nucleo-f446re|sha224|256|175.1|
|nucleo-f446re|sha224|512|305.6|
|nucleo-f446re|sha224|1024|566.6|
|
|nucleo-f103rb|sha224|16|144.8|
|nucleo-f103rb|sha224|32|144.7|
|nucleo-f103rb|sha224|64|258.4|
|nucleo-f103rb|sha224|128|363.6|
|nucleo-f103rb|sha224|256|574.2|
|nucleo-f103rb|sha224|512|995.3|
|nucleo-f103rb|sha224|1024|1837.5|
|
|nucleo-l073rz|sha224|16|410.1|
|nucleo-l073rz|sha224|32|410.1|
|nucleo-l073rz|sha224|64|772.4|
|nucleo-l073rz|sha224|128|1113.5|
|nucleo-l073rz|sha224|256|1795.8|
|nucleo-l073rz|sha224|512|3160.4|
|nucleo-l073rz|sha224|1024|5889.6|
|
|nucleo-l053r8|sha224|16|409.9|
|nucleo-l053r8|sha224|32|409.9|
|nucleo-l053r8|sha224|64|772.2|
|nucleo-l053r8|sha224|128|1113.3|
|nucleo-l053r8|sha224|256|1795.5|
|nucleo-l053r8|sha224|512|3159.9|
|nucleo-l053r8|sha224|1024|5888.9|
|
|nucleo-f446re|sha256|16|42.2|
|nucleo-f446re|sha256|32|42.2|
|nucleo-f446re|sha256|64|77.1|
|nucleo-f446re|sha256|128|109.7|
|nucleo-f446re|sha256|256|175.0|
|nucleo-f446re|sha256|512|305.0|
|nucleo-f446re|sha256|1024|566.5|
|
|nucleo-f103rb|sha256|16|145.0|
|nucleo-f103rb|sha256|32|145.0|
|nucleo-f103rb|sha256|64|258.5|
|nucleo-f103rb|sha256|128|363.8|
|nucleo-f103rb|sha256|256|574.3|
|nucleo-f103rb|sha256|512|995.4|
|nucleo-f103rb|sha256|1024|1837.6|
|
|nucleo-l073rz|sha256|16|410.4|
|nucleo-l073rz|sha256|32|410.4|
|nucleo-l073rz|sha256|64|772.7|
|nucleo-l073rz|sha256|128|1113.9|
|nucleo-l073rz|sha256|256|1796.2|
|nucleo-l073rz|sha256|512|3160.8|
|nucleo-l073rz|sha256|1024|5889.9|
|
|nucleo-l053r8|sha256|16|410.3|
|nucleo-l053r8|sha256|32|410.2|
|nucleo-l053r8|sha256|64|772.5|
|nucleo-l053r8|sha256|128|1113.6|
|nucleo-l053r8|sha256|256|1795.9|
|nucleo-l053r8|sha256|512|3160.3|
|nucleo-l053r8|sha256|1024|5889.2|
|
|nucleo-f446re|sha3_256|16|1930.2|
|nucleo-f446re|sha3_256|32|1931.0|
|nucleo-f446re|sha3_256|64|1932.6|
|nucleo-f446re|sha3_256|128|1935.9|
|nucleo-f446re|sha3_256|256|3860.7|
|nucleo-f446re|sha3_256|512|7710.2|
|nucleo-f446re|sha3_256|1024|15409.2|
|
|nucleo-f103rb|sha3_256|16|6610.5|
|nucleo-f103rb|sha3_256|32|6613.4|
|nucleo-f103rb|sha3_256|64|6619.2|
|nucleo-f103rb|sha3_256|128|6630.8|
|nucleo-f103rb|sha3_256|256|13212.1|
|nucleo-f103rb|sha3_256|512|26374.6|
|nucleo-f103rb|sha3_256|1024|52699.7|
|
|nucleo-l073rz|sha3_256|16|18361.2|
|nucleo-l073rz|sha3_256|32|18368.7|
|nucleo-l073rz|sha3_256|64|18383.7|
|nucleo-l073rz|sha3_256|128|18413.7|
|nucleo-l073rz|sha3_256|256|36758.5|
|nucleo-l073rz|sha3_256|512|73448.2|
|nucleo-l073rz|sha3_256|1024|146827.4|
|
|nucleo-l053r8|sha3_256|16|17655.7|
|nucleo-l053r8|sha3_256|32|17663.2|
|nucleo-l053r8|sha3_256|64|17678.2|
|nucleo-l053r8|sha3_256|128|17708.3|
|nucleo-l053r8|sha3_256|256|35347.7|
|nucleo-l053r8|sha3_256|512|70626.6|
|nucleo-l053r8|sha3_256|1024|141184.4|
|
|nucleo-f446re|sha3_384|16|1930.9|
|nucleo-f446re|sha3_384|32|1931.6|
|nucleo-f446re|sha3_384|64|1933.2|
|nucleo-f446re|sha3_384|128|3854.8|
|nucleo-f446re|sha3_384|256|5779.6|
|nucleo-f446re|sha3_384|512|9629.1|
|nucleo-f446re|sha3_384|1024|19246.6|
|
|nucleo-f103rb|sha3_384|16|6612.5|
|nucleo-f103rb|sha3_384|32|6615.4|
|nucleo-f103rb|sha3_384|64|6621.2|
|nucleo-f103rb|sha3_384|128|13190.9|
|nucleo-f103rb|sha3_384|256|19772.2|
|nucleo-f103rb|sha3_384|512|32934.8|
|nucleo-f103rb|sha3_384|1024|65818.0|
|
|nucleo-l073rz|sha3_384|16|18366.2|
|nucleo-l073rz|sha3_384|32|18373.7|
|nucleo-l073rz|sha3_384|64|18388.7|
|nucleo-l073rz|sha3_384|128|36703.5|
|nucleo-l073rz|sha3_384|256|55048.3|
|nucleo-l073rz|sha3_384|512|91737.9|
|nucleo-l073rz|sha3_384|1024|183402.0|
|
|nucleo-l053r8|sha3_384|16|17660.7|
|nucleo-l053r8|sha3_384|32|17668.2|
|nucleo-l053r8|sha3_384|64|17683.3|
|nucleo-l053r8|sha3_384|128|35292.7|
|nucleo-l053r8|sha3_384|256|52932.1|
|nucleo-l053r8|sha3_384|512|88211.0|
|nucleo-l053r8|sha3_384|1024|176348.2|
|
|nucleo-f446re|sha3_512|16|1931.4|
|nucleo-f446re|sha3_512|32|1932.2|
|nucleo-f446re|sha3_512|64|1933.8|
|nucleo-f446re|sha3_512|128|3855.3|
|nucleo-f446re|sha3_512|256|7698.5|
|nucleo-f446re|sha3_512|512|15384.8|
|nucleo-f446re|sha3_512|1024|28839.0|
|
|nucleo-f103rb|sha3_512|16|6614.5|
|nucleo-f103rb|sha3_512|32|6617.5|
|nucleo-f103rb|sha3_512|64|6623.3|
|nucleo-f103rb|sha3_512|128|13193.0|
|nucleo-f103rb|sha3_512|256|26332.4|
|nucleo-f103rb|sha3_512|512|52611.3|
|nucleo-f103rb|sha3_512|1024|98610.9|
|
|nucleo-l073rz|sha3_512|16|18371.2|
|nucleo-l073rz|sha3_512|32|18378.7|
|nucleo-l073rz|sha3_512|64|18393.7|
|nucleo-l073rz|sha3_512|128|36708.5|
|nucleo-l073rz|sha3_512|256|73338.1|
|nucleo-l073rz|sha3_512|512|146597.3|
|nucleo-l073rz|sha3_512|1024|274830.9|
|
|nucleo-l053r8|sha3_512|16|17665.7|
|nucleo-l053r8|sha3_512|32|17673.3|
|nucleo-l053r8|sha3_512|64|17688.3|
|nucleo-l053r8|sha3_512|128|35297.7|
|nucleo-l053r8|sha3_512|256|70516.5|
|nucleo-l053r8|sha3_512|512|140954.3|
|nucleo-l053r8|sha3_512|1024|264250.3|
|
|nucleo-f446re|sha1|16|46.9|
|nucleo-f446re|sha1|32|47.2|
|nucleo-f446re|sha1|64|92.9|
|nucleo-f446re|sha1|128|139.4|
|nucleo-f446re|sha1|256|232.1|
|nucleo-f446re|sha1|512|417.7|
|nucleo-f446re|sha1|1024|788.8|
|
|nucleo-f103rb|sha1|16|160.0|
|nucleo-f103rb|sha1|32|160.9|
|nucleo-f103rb|sha1|64|316.5|
|nucleo-f103rb|sha1|128|474.0|
|nucleo-f103rb|sha1|256|788.7|
|nucleo-f103rb|sha1|512|1418.3|
|nucleo-f103rb|sha1|1024|2677.4|
|
|nucleo-l073rz|sha1|16|384.4|
|nucleo-l073rz|sha1|32|394.4|
|nucleo-l073rz|sha1|64|775.2|
|nucleo-l073rz|sha1|128|1175.9|
|nucleo-l073rz|sha1|256|1977.5|
|nucleo-l073rz|sha1|512|3580.5|
|nucleo-l073rz|sha1|1024|6786.7|
|
|nucleo-l053r8|sha1|16|382.5|
|nucleo-l053r8|sha1|32|392.4|
|nucleo-l053r8|sha1|64|771.3|
|nucleo-l053r8|sha1|128|1170.2|
|nucleo-l053r8|sha1|256|1968.0|
|nucleo-l053r8|sha1|512|3563.5|
|nucleo-l053r8|sha1|1024|6754.7|
|
|nucleo-f446re|md5|16|26.9|
|nucleo-f446re|md5|32|27.3|
|nucleo-f446re|md5|64|52.8|
|nucleo-f446re|md5|128|79.2|
|nucleo-f446re|md5|256|131.9|
|nucleo-f446re|md5|512|237.4|
|nucleo-f446re|md5|1024|448.3|
|
|nucleo-f103rb|md5|16|99.4|
|nucleo-f103rb|md5|32|100.3|
|nucleo-f103rb|md5|64|195.7|
|nucleo-f103rb|md5|128|292.8|
|nucleo-f103rb|md5|256|487.2|
|nucleo-f103rb|md5|512|875.9|
|nucleo-f103rb|md5|1024|1653.2|
|
|nucleo-l073rz|md5|16|230.7|
|nucleo-l073rz|md5|32|237.7|
|nucleo-l073rz|md5|64|463.3|
|nucleo-l073rz|md5|128|702.8|
|nucleo-l073rz|md5|256|1181.9|
|nucleo-l073rz|md5|512|2140.0|
|nucleo-l073rz|md5|1024|4056.4|
|
|nucleo-l053r8|md5|16|230.7|
|nucleo-l053r8|md5|32|237.7|
|nucleo-l053r8|md5|64|463.2|
|nucleo-l053r8|md5|128|702.7|
|nucleo-l053r8|md5|256|1181.8|
|nucleo-l053r8|md5|512|2140.0|
|nucleo-l053r8|md5|1024|4056.3|


## Running the benchmarks suite
### On RIOT

```bash
cd riot/unkeyed_hash
make BOARD=nucleo-XXXX -j16 flash term
```
