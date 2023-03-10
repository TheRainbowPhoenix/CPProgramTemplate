# Compiler options
# Feel free to edit this matching your configuration

ifndef SDK_DIR
$(error You need to define the SDK_DIR environment variable, and point it to the sdk/ folder)
endif

# If you're using sh4-elf instead, change this !!
PREFIX=sh4-elf

# Assembler, used for .s files
AS:=$(PREFIX)-as
AS_FLAGS:=

# C compiler
CC:=$(PREFIX)-gcc
CC_FLAGS:=-Os -mb -m4a-nofpu -mhitachi -ffreestanding -fno-strict-aliasing -fshort-wchar -Wall -Wextra -I $(SDK_DIR)/include/ \
	-I $(SDK_DIR)/newlib/sh-elf/include

# C++ compiler
CXX:=$(PREFIX)-g++
CXX_FLAGS:=-Os -mb -m4a-nofpu -mhitachi -ffreestanding -fno-strict-aliasing -fno-exceptions -fno-rtti -fshort-wchar -Wall -Wextra -O2 -I $(SDK_DIR)/include/ \
	-I $(SDK_DIR)/newlib/sh-elf/include

# C linker
LD:=$(PREFIX)-gcc
LD_FLAGS:=-nostartfiles -m4-nofpu -Wno-undef -nostdlib -L$(SDK_DIR)/newlib/sh-elf/lib/ -lm -lc

# ReadELF and OBJCopy cross
READELF:=$(PREFIX)-readelf
OBJCOPY:=$(PREFIX)-objcopy

APP_ELF:=$(DISTDIR)/$(APP_NAME).hhk
APP_BIN:=$(DISTDIR)/$(APP_NAME).bin