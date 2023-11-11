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

USEMODULE += xtimer
USEMODULE += fmt
USEMODULE += printf_float

USEPKG += libhydrogen
USEMODULE += embunit

include $(RIOTBASE)/Makefile.include
