# Variables #
SRC := ./Tarea2/src
BUILD := ./Tarea2/build
BIN_FOLDER := ${BUILD}/bin
DEBUG := ./Tarea2/debug
# Algunos wildcard deben usarse antes de los prerrequisitos porque pueden ocasionar problemas, por ejemplo: #
C_FILES := $(wildcard ${SRC}/*.c)
# usaré un comando patsubst que permite buscar y reemplazar patrones #
OBJS := $(patsubst ${SRC}/%.c, ${BUILD}/%.o, ${C_FILES})
# En este caso va a generar todos los nombres de archivos, está mejor explicado en https://www.gnu.org/software/make/manual/html_node/Text-Functions.html#Text-Functions #
# Esta variable permitirá generar un binario diferente para cada archivo C #
BINS := $(patsubst ${SRC}/%.c, ${BIN_FOLDER}/%, ${C_FILES})

# Para que no se borren los .o #
.PRECIOUS: ${OBJS}
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
	gcc -g3 -Og -Wall -c $< -o $(BUILD_PATH)/$@

$(NASM_TARGETS): $(NASM_DEPENDENCIES)
	mkdir -p $(BUILD_PATH)
	nasm -felf64 -g -F dwarf $< -o $(BUILD_PATH)/$@

clean:
	sudo rm -fr ${BUILD_PATH}