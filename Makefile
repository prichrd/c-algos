CC=gcc
SRC_DIR=src
CFLAGS=-g -I $(SRC_DIR)

_OBJ=main.o containers/stack/stack.o
OBJ=$(patsubst %,$(SRC_DIR)/%,$(_OBJ))

$(TARGET):
	mkdir target

$(SRC_DIR)/%.o: $(TARGET) src/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o main $(OBJ)


.PHONY: clean
clean:
	rm -rf $(OBJ)