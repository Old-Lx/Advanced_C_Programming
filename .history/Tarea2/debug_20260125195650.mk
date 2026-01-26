# Variables #
SRC := ./Tarea2/src
DEBUG := ./Tarea2/debug
BIN_FOLDER := ${DEBUG}/bin

# Compilation variables for C
C_FILES := $(wildcard ${SRC}/*.c)
C_OBJS := $(patsubst ${SRC}/%.c, ${BUILD}/%.o, ${C_FILES})

# Compilation variables for asm #
NASM_FILES := $(wildcard ${SRC}/*.asm)
NASM_TARGETS := $(patsubst ${SRC}/%.asm, ${BUILD}/%.o, ${NASM_FILES})

.PHONY: all

all: $(C_OBJECTS) $(NASM_TARGETS)

$(OUTPUT_NAME): $(C_OBJECTS) $(NASM_TARGETS)
	mkdir -p $(OUTPUT_PATH)
	gcc -g3 -Og -Wall $^ -o $(OUTPUT_PATH)/$@

$(C_OBJECTS): $(C_DEPENDENCIES)
	mkdir -p $(DEBUG)
	gcc -g3 -Og -Wall -c $< -o $(DEBUG)/$@

$(NASM_TARGETS): $(NASM_DEPENDENCIES)
	mkdir -p $(DEBUG)
	nasm -felf64 -g -F dwarf $< -o $(DEBUG)/$@

clean:
	sudo rm -fr ${DEBUG}