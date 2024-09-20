# $(RM) -f $(RES)/*.s

MAKEFILE_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
MAKEFILE_DIR := $(subst \,/,$(MAKEFILE_DIR))

ifneq ("$(wildcard $(MAKEFILE_DIR)bin/rescomp.jar)","")
    GDK := $(patsubst %/,%,$(MAKEFILE_DIR))
endif

include $(GDK)/common.mk

GENRES= tools/genres

SRC := game/src
RES := game/res
RC := game/res
INCLUDE := inc
OUT := out

SRC_C= $(wildcard *.c)
SRC_C+= $(wildcard $(SRC)/*.c)
SRC_C+= $(wildcard $(SRC)/*/*.c)
SRC_C+= $(wildcard $(SRC)/*/*/*.c)
SRC_C+= $(wildcard $(SRC)/*/*/*/*.c)
SRC_C:= $(filter-out $(SRC)/boot/rom_head.c,$(SRC_C))
ifeq ($(SRC_C),)
SRC_C=$(SRC)/main.c
endif
SRC_S= $(wildcard *.s)
SRC_S+= $(wildcard $(SRC)/*.s)
SRC_S+= $(wildcard $(SRC)/*/*.s)
SRC_S+= $(wildcard $(SRC)/*/*/*.s)
SRC_C+= $(wildcard $(SRC)/../../libs/*.c)
SRC_C+= $(wildcard $(SRC)/../libs/*.c)
SRC_S:= $(filter-out $(SRC)/boot/sega.s,$(SRC_S))
SRC_ASM= $(wildcard *.asm)
SRC_ASM+= $(wildcard $(SRC)/*.asm)
SRC_ASM+= $(wildcard $(SRC)/*/*.asm)
SRC_ASM+= $(wildcard $(SRC)/*/*/*.asm)
SRC_S80= $(wildcard *.s80)
SRC_S80+= $(wildcard $(SRC)/*.s80)
SRC_S80+= $(wildcard $(SRC)/*/*.s80)
SRC_S80+= $(wildcard $(SRC)/*/*/*.s80)

RES_C= $(wildcard $(RES)/*.c)
RES_S= $(wildcard $(RES)/*.s)
RES_RES= $(wildcard *.res)
RES_RC= $(wildcard *.rc)
RES_RES+= $(wildcard $(RES)/*.res)
RES_RC+= $(wildcard $(RC)/*.rc)

RES_RS= $(RES_RES:.res=.rs)
RES_RS+= $(RES_RC:.rc=.s)
RES_H= $(RES_RES:.res=.h)
RES_H+= $(RES_RC:.rc=.h)
RES_DEP= $(RES_RES:.res=.d)
RES_DEP+= $(RES_RC:.rc=.d)
RES_DEPS= $(addprefix $(OUT)/, $(RES_DEP))

OBJ= $(RES_RES:.res=.o)
OBJ+= $(RES_RC:.rc=.o)
OBJ+= $(RES_S:.s=.o)
OBJ+= $(RES_C:.c=.o)
OBJ+= $(SRC_S80:.s80=.o)
OBJ+= $(SRC_ASM:.asm=.o)
OBJ+= $(SRC_S:.s=.o)
OBJ+= $(SRC_C:.c=.o)
OBJS:= $(addprefix $(OUT)/, $(OBJ))

DEPS:= $(OBJS:.o=.d)

-include $(DEPS)

LST:= $(SRC_C:.c=.lst)
LSTS:= $(addprefix $(OUT)/, $(LST))

INCS:= -I$(INCLUDE) -I$(SRC) -I$(RES) -I$(INCLUDE_LIB) -I$(RES_LIB)
# DEFAULT_FLAGS= $(EXTRA_FLAGS) -DSGDK_GCC -m68000 -Wall -Wextra -Wno-shift-negative-value -Wno-main -Wno-unused-parameter -fno-builtin -ffunction-sections -fdata-sections -fms-extensions $(INCS) -B$(BIN)
DEFAULT_FLAGS= $(EXTRA_FLAGS) -DSGDK_GCC -m68000 -Wall -Wextra -Wno-shift-negative-value -Wno-main -Wno-unused-parameter -fno-builtin -ffunction-sections -fdata-sections -fms-extensions -fcommon $(INCS) -B$(BIN)
FLAGSZ80:= -i$(SRC) -i$(INCLUDE) -i$(RES) -i$(SRC_LIB) -i$(INCLUDE_LIB) -i$(INCLUDE_LIB)/snd

#release: FLAGS= $(DEFAULT_FLAGS) -Os -fomit-frame-pointer -fuse-linker-plugin -flto
# release: FLAGS= $(DEFAULT_FLAGS) -O3 -fuse-linker-plugin -fno-web -fno-gcse -fomit-frame-pointer -flto -flto=auto -ffat-lto-objects
release: FLAGS= $(DEFAULT_FLAGS) -O3 -fuse-linker-plugin -fno-web -fno-gcse -fomit-frame-pointer -flto -flto=auto -ffat-lto-objects      -Wno-missing-field-initializers -Wno-pointer-sign -Wno-implicit-function-declaration -Wno-stringop-overflow -Wno-incompatible-pointer-types -Wno-unused-but-set-variable -Wno-int-conversion -Wno-char-subscripts -Wno-unused-const-variable -Wno-unused-value -Wno-discarded-qualifiers -Wno-uninitialized -Wno-sizeof-pointer-div -Wno-unused-variable -Wno-ignored-qualifiers -Wno-unused-label
release: CFLAGS= $(FLAGS)
release: AFLAGS= $(FLAGS)
release: LIBMD= $(LIB)/libmd.a
release: pre-release $(OUT)/rom.bin $(OUT)/symbol.txt post-release
.PHONY: release

#release: $(info $$var is [${SRC_C}])

debug: FLAGS= $(DEFAULT_FLAGS) -O1 -DDEBUG=1
debug: CFLAGS= $(FLAGS) -ggdb
debug: AFLAGS= $(FLAGS)
debug: LIBMD= $(LIB)/libmd_debug.a
debug: $(OUT)/rom.bin $(OUT)/rom.out $(OUT)/symbol.txt
.PHONY: debug

asm: FLAGS= $(DEFAULT_FLAGS) -O3 -fuse-linker-plugin -fno-web -fno-gcse -fomit-frame-pointer -S
asm: CFLAGS= $(FLAGS)
asm: AFLAGS= $(FLAGS)
asm: LIBMD= $(LIB)/libmd.a
asm: $(LSTS)
.PHONY: asm

define MAIN_C_CONTENT
#include "genesis.h"

int main(bool hardReset){
    VDP_drawText("Hello SGDK!", 12, 12);
    while(TRUE) { SYS_doVBlankProcess(); }
    return 0;
}
endef

$(SRC)/main.c: export MAIN_C_CONTENT:=$(MAIN_C_CONTENT)
$(SRC)/main.c:
	$(MKDIR) -p $(dir $@)
	$(ECHO) "$${MAIN_C_CONTENT}" > $@

# include ext.mk if it exists (better to do it after release rule definition)
ifneq ("$(wildcard $(GDK)/ext.mk)","")
    include $(GDK)/ext.mk
endif

all: release
default: release

Default: release
Debug: debug
Release: release
Asm: asm

cleantmp:
	$(RM) -f $(RES_RS)
.PHONY: cleantmp

cleandep:
	$(RM) -f $(DEPS)
.PHONY: cleandep

cleanlst:
	$(RM) -f $(LSTS)
.PHONY: cleanlst

cleanres: cleantmp
	$(RM) -f $(RES_H) $(RES_DEP) $(RES_DEPS)
.PHONY: cleanres

cleanobj:
	$(RM) -f $(OBJS) $(OUT)/sega.o $(OUT)/rom_head.bin $(OUT)/rom_head.o $(OUT)/rom.out
.PHONY: cleanobj

clean: cleanobj cleanres cleanlst cleandep
	$(RM) -f $(OUT)/out.lst $(OUT)/cmd_ $(OUT)/symbol.txt $(OUT)/rom.nm $(OUT)/rom.wch $(OUT)/rom.bin
.PHONY: clean

cleanrelease: clean
.PHONY: cleanrelease

cleandebug: clean
.PHONY: cleandebug

cleanasm: cleanlst
.PHONY: cleanasm

cleandefault: clean
cleanDefault: clean
.PHONY: cleandefault cleanDefault

cleanRelease: cleanrelease
cleanDebug: cleandebug
cleanAsm: cleanasm
.PHONY: cleanRelease cleanDebug cleanAsm

pre-release:
	-$(RM) -f $(RES)/*.s
	-$(RM) $(OUT)/rom.bin $(OUT)/rom.md

post-release:
	-$(CP) $(OUT)/rom.bin $(OUT)/rom.md
	-$(RM) -f $(RES)/*.s
	

$(OUT)/rom.bin: $(OUT)/rom.out
	$(OBJCPY) -O binary $(OUT)/rom.out $(OUT)/rom.bin
	$(SIZEBND) $(OUT)/rom.bin -sizealign 131072 -checksum

$(OUT)/symbol.txt: $(OUT)/rom.out
	$(NM) $(LTO_PLUGIN) -n $(OUT)/rom.out > $(OUT)/symbol.txt

$(OUT)/rom.out: $(OUT)/sega.o $(OUT)/cmd_ $(LIBMD)
	$(MKDIR) -p $(dir $@)
	$(CC) -m68000 -B$(BIN) -n -T $(GDK)/md.ld -nostdlib $(OUT)/sega.o @$(OUT)/cmd_ $(LIBMD) $(LIBGCC) -o $(OUT)/rom.out -Wl,--gc-sections -flto -flto=auto -ffat-lto-objects
	$(RM) $(OUT)/cmd_

$(OUT)/cmd_: $(OBJS)
	$(MKDIR) -p $(dir $@)
	$(ECHO) "$(OBJS)" > $(OUT)/cmd_

# NOTE: sega.s references rom_head.bin internally.
$(OUT)/sega.o: $(SRC)/boot/sega.s $(OUT)/rom_head.bin
	$(CC) -x assembler-with-cpp -Wa,--register-prefix-optional,--bitwise-or $(AFLAGS) -c $(SRC)/boot/sega.s -o $@

$(OUT)/rom_head.bin: $(OUT)/rom_head.o
	$(OBJCPY) -O binary $< $@

$(OUT)/rom_head.o: $(SRC)/boot/rom_head.c
	$(MKDIR) -p $(dir $@)
	$(CC) $(DEFAULT_FLAGS) -c $< -o $@

# SRC_LIB files are "order-only" deps, right of the pipe.  This means we will
# never overwrite the file in SRC, even if SRC_LIB is newer.

$(SRC)/boot/sega.s: | $(SRC_LIB)/boot/sega.s
	$(MKDIR) -p $(dir $@)
	$(CP) $| $@

$(SRC)/boot/rom_head.c: | $(SRC_LIB)/boot/rom_head.c
	$(MKDIR) -p $(dir $@)
	$(CP) $| $@

$(OUT)/%.lst: %.c
	$(MKDIR) -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)/%.o: %.c
	$(MKDIR) -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OUT)/%.o: %.s
	$(MKDIR) -p $(dir $@)
	-$(RM) $@
	$(CC) -x assembler-with-cpp -Wa,--register-prefix-optional,--bitwise-or $(AFLAGS) -MMD -c $< -o $@

$(OUT)/%.o: %.rs
	$(MKDIR) -p $(dir $@)
	$(CC) -x assembler-with-cpp -Wa,--register-prefix-optional,--bitwise-or $(AFLAGS) -c $*.rs -o $@
	$(CP) $*.d $(OUT)/$*.d
	$(RM) $*.d

%.rs: %.res
	$(RESCOMP) $*.res $*.rs -dep $(OUT)/$*.o

%.asm: %.rc
	$(GENRES) $< $@

%.s: %.asm
	$(MACCER) -o $@ $<

%.o80: %.s80
	$(ASMZ80) $(FLAGSZ80) $< $@ $(OUT)/out.lst

%.s: %.o80
	$(BINTOS) $<
