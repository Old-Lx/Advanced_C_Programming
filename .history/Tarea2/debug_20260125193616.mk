BUILD_PATH := ./Tarea2/debug
OUTPUT_PATH := ${BUILD_PATH}/bin
DEPENDENCY_PATH := ./Tarea2/src
OUTPUT_NAME := main

# Compilation variables for C #
C_FILES := main.c
# Este uso de las wildcards lo ví en una clase, mi implementación está en el Makefile de la tarea 1 #
C_DEPENDENCIES := $(C_FILES:%=$(DEPENDENCY_PATH)/%)
C_OBJECTS := $(C_FILES:%.c=$(DEPENDENCY_PATH)/%.o)

# Compilation variables for asm #
NASM_FILES := print.asm
NASM_DEPENDENCIES := $(NASM_FILES:%=$(DEPENDENCY_PATH)/%)
NASM_TARGETS := $(NASM_FILES:%.asm=$(DEPENDENCY_PATH)/%.o)

.PHONY: all

all: $(C_OBJECTS) $(NASM_TARGETS)

$(OUTPUT_NAME): $(C_OBJECTS) $(NASM_TARGETS)
	mkdir -p $(OUTPUT_PATH)
	gcc -g3 -Og -Wall $^ -o $(OUTPUT_PATH)/$@

$(C_OBJECTS): $(C_DEPENDENCIES)
	mkdir -p $(BUILD_PATH)
	gcc -g3 -Og -Wall -c $< -o $@

$(NASM_TARGETS): $(NASM_DEPENDENCIES)
	mkdir -p $(BUILD_PATH)
	nasm -felf64 -g -F dwarf $< -o $@

.PHONY: clean
	sudo rm -fr ${BUILD_PATH}