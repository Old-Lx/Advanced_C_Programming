# Variables #
SRC := ./src
DEBUG := ./debug
BIN_FOLDER := ${DEBUG}/bin
OUTPUT_NAME := main

# Compilation variables for C
C_FILES := $(wildcard ${SRC}/*.c) $(wildcard ${SRC}/allocators/*.c) $(wildcard ${SRC}/calculator/*.c)
C_OBJS := $(patsubst ${SRC}/%.c, ${DEBUG}/%.o, ${C_FILES})

.PHONY: all clean

all: $(BIN_FOLDER)/$(OUTPUT_NAME)

$(BIN_FOLDER)/$(OUTPUT_NAME): $(C_OBJS)
	@echo ${C_OBJS}
	@mkdir -p $(BIN_FOLDER)
	@gcc $^ -o $@

$(DEBUG)/%.o: $(SRC)/%.c
	@mkdir -p $(DEBUG) ${DEBUG}/allocators ${DEBUG}/calculator
	@gcc -g -Wall -Wextra -c $< -o $@

clean:
	sudo rm -fr ${DEBUG}