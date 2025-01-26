# Colors
COLOR_RESET = \033[0m
COLOR_RED = \033[31m
COLOR_GREEN = \033[32m
COLOR_YELLOW = \033[33m

CC = arm-none-eabi-gcc
BIN := RTOSDemo.axf

BUILD_DIR := build

# Source Files
SOURCE_FILES += core/FreeRTOS/tasks.c
SOURCE_FILES += core/FreeRTOS/queue.c
SOURCE_FILES += core/FreeRTOS/list.c
SOURCE_FILES += core/scheduler/scheduler.c
SOURCE_FILES += core/scheduler/task_config.c
SOURCE_FILES += domains/Battery/Battery.c
SOURCE_FILES += core/drivers/hal/stm32f4xx_hal.c
SOURCE_FILES += core/drivers/hal/stm32f4xx_hal_gpio.c
SOURCE_FILES += core/drivers/hal/stm32f4xx_hal_rcc.c
SOURCE_FILES += core/FreeRTOS/portable/port.c
SOURCE_FILES += core/FreeRTOS/portable/heap_4.c
SOURCE_FILES += config/FreeRTOSHooks.c
SOURCE_FILES += core/drivers/hal/system_stm32f4xx.c
SOURCE_FILES += core/drivers/hal/startup_stm32f401xc.s
SOURCE_FILES += core/FreeRTOS/timers.c
SOURCE_FILES += main.c
SOURCE_FILES += core/drivers/hal/stm32f4xx_hal_cortex.c

# Include Paths
INCLUDE_DIRS += -Icore/FreeRTOS
INCLUDE_DIRS += -Icore/scheduler
INCLUDE_DIRS += -Icore/drivers
INCLUDE_DIRS += -Idomains/Battery
INCLUDE_DIRS += -Iconfig
INCLUDE_DIRS += -I/usr/local/Cellar/arm-none-eabi-gcc/14.2.0/arm-none-eabi/include
INCLUDE_DIRS += -Icore/drivers/hal
INCLUDE_DIRS += -Icore/drivers/hal/legacy
INCLUDE_DIRS += -Icore/FreeRTOS/include
INCLUDE_DIRS += -Icore/FreeRTOS/portable

# Compiler and Linker Flags
CFLAGS = -nostartfiles -mthumb -mcpu=cortex-m4 -Wall -Wextra -ggdb3 -O2 -fstrict-aliasing -Wstrict-aliasing
CFLAGS += $(INCLUDE_DIRS)
CFLAGS += -DSTM32F401xC
CFLAGS += -fno-use-cxa-atexit

LDFLAGS = -T config/linker_script.ld
LDFLAGS += -L/usr/local/Cellar/arm-none-eabi-gcc/14.2.0/lib/gcc/arm-none-eabi/14.2.0
LDFLAGS += -lc -lrdimon -Xlinker -Map=$(BUILD_DIR)/output.map
LDFLAGS += --specs=nosys.specs

# Assembly File Flags
ASFLAGS = $(CFLAGS)

OBJ_FILES := $(SOURCE_FILES:%.c=$(BUILD_DIR)/%.o)
OBJ_FILES += $(SOURCE_FILES:%.s=$(BUILD_DIR)/%.o)

.PHONY: all clean

# Default Target
all: $(BUILD_DIR)/$(BIN)

# Build Target
$(BUILD_DIR)/$(BIN): $(OBJ_FILES)
	@echo "$(COLOR_GREEN)Linking target...$(COLOR_RESET)"
	$(CC) -ffunction-sections -fdata-sections $(CFLAGS) $(LDFLAGS) $+ -o $(@)

# Object Files for C Source
$(BUILD_DIR)/%.o: %.c
	@echo "$(COLOR_YELLOW)Compiling $<...$(COLOR_RESET)"
	-mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Object Files for Assembly Source
$(BUILD_DIR)/%.o: %.s
	@echo "$(COLOR_YELLOW)Compiling Assembly $<...$(COLOR_RESET)"
	-mkdir -p $(@D)
	$(CC) $(ASFLAGS) -c $< -o $@

# Clean Target
clean:
	@echo "$(COLOR_RED)Cleaning build directory...$(COLOR_RESET)"
	-rm -rf $(BUILD_DIR)
