GCCPATH = ../gcc-arm-10.3-2021.07-x86_64-aarch64-none-elf/bin

COPS = -Wall -nostdlib -nostartfiles -ffreestanding -Iinclude -mgeneral-regs-only
ASMOPS = -Iinclude 

BUILD_DIR = build
SRC_DIR = src

C_FILES = $(wildcard $(SRC_DIR)/*.c)
ASM_FILES = $(wildcard $(SRC_DIR)/*.S)
H_FILES = $(wildcard $(SRC_DIR)/*.h)
OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_c.o)
OBJ_FILES += $(ASM_FILES:$(SRC_DIR)/%.S=$(BUILD_DIR)/%_s.o)

all : kernel8.img

clean :
		rm -rf $(BUILD_DIR) *.img 

$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c 
		mkdir -p $(@D)
		$(GCCPATH)/aarch64-none-elf-gcc $(COPS) -MMD -c $< -o $@

$(BUILD_DIR)/%_s.o: $(SRC_DIR)/%.S
		$(GCCPATH)/aarch64-none-elf-gcc $(ASMOPS) -MMD -c $< -o $@

kernel8.img: clean $(SRC_DIR)/linker.ld $(OBJ_FILES)
		$(GCCPATH)/aarch64-none-elf-ld -T $(SRC_DIR)/linker.ld -o $(BUILD_DIR)/kernel8.elf  $(OBJ_FILES)
		$(GCCPATH)/aarch64-none-elf-objcopy $(BUILD_DIR)/kernel8.elf -O binary kernel8.img
