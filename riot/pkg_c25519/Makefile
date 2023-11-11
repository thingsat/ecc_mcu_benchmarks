# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= ${HOME}/github/RIOT-OS/RIOT

include $(RIOTBASE)/tests/Makefile.tests_common

# -----------------------------
# Boards
# -----------------------------

EXTERNAL_BOARD_DIRS ?= ${HOME}/github/thingsat/riot_modules/boards ${HOME}/github/campusiot/RIOT-wyres/boards

# If no BOARD is found in the environment, use this default:
BOARD ?= thingsat-up4

BENCH_SIZE = 10U

CFLAGS += -DBENCH_SIZE=$(BENCH_SIZE)

USEMODULE += embunit
USEMODULE += random
USEPKG += c25519

USEMODULE += xtimer
USEMODULE += fmt
USEMODULE += printf_float

include $(RIOTBASE)/Makefile.include

# c25519 takes up to 1.5K in stack, almost independent of the platform
ifneq (,$(filter b-u585i-iot02a,$(BOARD)))
  CFLAGS += -DTHREAD_STACKSIZE_MAIN=\(THREAD_STACKSIZE_DEFAULT+THREAD_EXTRA_STACKSIZE_PRINTF\)
else
ifneq (,$(filter cortex-%,$(CPU_CORE)))
  CFLAGS += -DTHREAD_STACKSIZE_MAIN=\(THREAD_STACKSIZE_DEFAULT+THREAD_EXTRA_STACKSIZE_PRINTF\)
else
ifneq (,$(filter atmega_common msp430_common,$(USEMODULE)))
  CFLAGS += -DTHREAD_STACKSIZE_MAIN=\(5*THREAD_STACKSIZE_DEFAULT+THREAD_EXTRA_STACKSIZE_PRINTF\)
else
  CFLAGS += -DTHREAD_STACKSIZE_MAIN=\(3*THREAD_STACKSIZE_DEFAULT+THREAD_EXTRA_STACKSIZE_PRINTF\)
endif
endif
endif
