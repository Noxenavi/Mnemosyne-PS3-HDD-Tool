ifeq ($(strip $(PS3DEV)),)
$(error "Configure a variável de ambiente PS3DEV apontando para o toolchain PS3DEV")
endif

ifeq ($(strip $(PSL1GHT)),)
$(error "Configure a variável de ambiente PSL1GHT apontando para o PSL1GHT")
endif

include $(PSL1GHT)/host/ppu.mk

TARGET      := mnemosyne_hdd_tool
BUILD       := build
SOURCES     := source
INCLUDES    := include

CFLAGS      := -O2 -Wall -I$(INCLUDES)
CXXFLAGS    := $(CFLAGS)

LIBS        := -lrsx -lgcm_sys -lsysutil -lio -lrt

include $(PSL1GHT)/host/ppu_rules

all: $(TARGET).self

clean:
	@rm -rf $(BUILD) $(TARGET).elf $(TARGET).self $(TARGET).sfo *.sprx
