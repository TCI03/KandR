CC=gcc
CFLAGS=-Wall -I./include

MAIN=main.c
BINDIR=./bin
SRC_DIR=./src
SRC_FILES:=$(wildcard $(SRC_DIR)/*.c)
INC_DIR=./include
INC_DIR=$(INC_DIR)/*.h
OBJ_DIR=./obj
OBJ_FILES=$(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TARGET=k-r

$(BINDIR)/$(TARGET): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) -lm -o $@
	@echo "Linking complete."

$(OBJ_FILES): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "[$(CC)] : "$<""

.PHONY: clean

clean:
	rm -fv $(BINDIR)/$(TARGET) $(OBJ_FILES)
