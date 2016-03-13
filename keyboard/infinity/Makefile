PROJECT = infinity

TMK_DIR = ../../tmk_core
MBED_DIR = $(TMK_DIR)/tool/mbed/mbed-sdk

#VPATH += $(MBED_DIR):$(TMK_DIR)
vpath %.s .:$(MBED_DIR):$(TMK_DIR)
vpath %.c .:$(MBED_DIR):$(TMK_DIR)
vpath %.cpp .:$(MBED_DIR):$(TMK_DIR)

OBJDIR = ./build

OBJECTS = \
	$(OBJDIR)/matrix.o \
	$(OBJDIR)/keymap_common.o \
	$(OBJDIR)/led.o \
	$(OBJDIR)/main.o

ifdef KEYMAP
    OBJECTS := $(OBJDIR)/keymap_$(KEYMAP).o $(OBJECTS)
else
    OBJECTS := $(OBJDIR)/keymap.o $(OBJECTS)
endif

CONFIG_H = config.h

INCLUDE_PATHS = -I.


# Build Options
# 2015-08-07, AA: Comment out to disable, not working yet also
# BOOTMAGIC_ENABLE = yes
#MOUSEKEY_ENABLE = yes
# 2015-08-07, AA: to enable media keys, not working yet
# EXTRAKEY_ENABLE = yes
# SLEEP_LED_ENABLE = yes


include mbed-infinity.mk
include $(TMK_DIR)/tool/mbed/mbed.mk
include $(TMK_DIR)/tool/mbed/common.mk
include $(TMK_DIR)/tool/mbed/gcc.mk

program: $(OBJDIR)/$(PROJECT).bin
	dfu-util -D $(OBJDIR)/$(PROJECT).bin

# 2016/03/05 22:51:48, AA: copied from above, just to have 
# the same target as the planck
dfu: $(OBJDIR)/$(PROJECT).bin
	dfu-util -D $(OBJDIR)/$(PROJECT).bin
