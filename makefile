# ----------------------------
# Makefile Options
# ----------------------------

NAME = PONG
ICON = icon.png
DESCRIPTION = "Pong for TI-84 by Touchcreator"
COMPRESSED = NO
# ARCHIVED = NO
HAS_PRINTF = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
