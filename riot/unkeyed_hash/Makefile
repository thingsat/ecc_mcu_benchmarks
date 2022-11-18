include $(RIOTBASE)/tests/Makefile.tests_common

# -----------------------------
# Boards
# -----------------------------

EXTERNAL_BOARD_DIRS ?= ../../boards

# If no BOARD is found in the environment, use this default:
BOARD ?= thingsat-f4

BENCH_SIZE = 1000U

CFLAGS += -DBENCH_SIZE=$(BENCH_SIZE)

USEMODULE += embunit

USEMODULE += xtimer
USEMODULE += fmt
USEMODULE += printf_float

USEMODULE += hashes

include $(RIOTBASE)/Makefile.include