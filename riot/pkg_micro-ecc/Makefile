include $(RIOTBASE)/tests/Makefile.tests_common

# -----------------------------
# Boards
# -----------------------------

EXTERNAL_BOARD_DIRS ?= ../../boards

# If no BOARD is found in the environment, use this default:
BOARD ?= thingsat-f4

USEMODULE += hashes
USEPKG += micro-ecc

CFLAGS += -DuECC_OPTIMIZATION_LEVEL=3

# When compiling for a Thumb-1 platform, you must use the -fomit-frame-pointer GCC option (this is enabled by default when compiling with -O1 or higher).
# When compiling for an ARM/Thumb-2 platform with uECC_OPTIMIZATION_LEVEL >= 3, you must use the -fomit-frame-pointer GCC option (this is enabled by default when compiling with -O1 or higher).

CFLAGS += -fomit-frame-pointer


USEMODULE += xtimer
USEMODULE += fmt
USEMODULE += printf_float

CFLAGS += -DuECC_SUPPORTS_secp160r1=1
CFLAGS += -DuECC_SUPPORTS_secp192r1=1
CFLAGS += -DuECC_SUPPORTS_secp224r1=1
CFLAGS += -DuECC_SUPPORTS_secp256r1=1
CFLAGS += -DuECC_SUPPORTS_secp256k1=1


include $(RIOTBASE)/Makefile.include

# Increase Stack size for AVR
ifneq (,$(filter avr8_common,$(USEMODULE)))
  CFLAGS += -DTHREAD_STACKSIZE_MAIN=THREAD_STACKSIZE_LARGE
endif
