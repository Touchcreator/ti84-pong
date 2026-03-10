# ----------------------------
# Makefile Options
# ----------------------------

NAME = PONG
ICON = icon.png
DESCRIPTION = "Pong for TI-84 by Touchcreator"
COMPRESSED = NO
# ARCHIVED = NO
HAS_PRINTF = NO

RELEASE_MODE = DEBUG

CFLAGS = -Wall -Wextra
CXXFLAGS = -Wall -Wextra -Oz

CFLAGS += -Werror
ifeq ($(RELEASE_MODE),DEBUG)
	CFLAGS += -Werror -O0 -Oz
else
	CFLAGS += -Werror -Os
endif

# ----------------------------

include $(shell cedev-config --makefile)
