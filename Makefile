CC=gcc
SRC_DIR=src
TEST_DIR=test
TARGET_DIR=target
CFLAGS=-g -I $(SRC_DIR)

_OBJ=containers/node.o \
		 containers/stack.o \
		 containers/singly_linked_list.o \
		 containers/doubly_linked_list.o
OBJ=$(patsubst %,$(SRC_DIR)/%,$(_OBJ))

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS) -I $(TEST_DIR)

$(TARGET_DIR)/test: $(OBJ) $(TEST_DIR)/main.o
	$(CC) -o $@ $(OBJ) $(TEST_DIR)/main.o

.PHONY: test
test: $(TARGET_DIR)/test
	@$(TARGET_DIR)/test

.PHONY: leaks
leaks: $(TARGET_DIR)/test
	leaks -atExit -- $(TARGET_DIR)/test

.PHONY: clean
clean:
	@rm -rf $(OBJ)
	@rm -rf test/*.o
