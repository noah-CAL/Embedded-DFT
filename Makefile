CC := gcc
CFLAGS := -Wall -Wextra -Werror -std=c99
LDLIBS := -lm

# Directories
SRC_DIR := src
TEST_DIR := tests
BUILD_DIR := build

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Test files
TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS := $(patsubst $(TEST_DIR)/%.c,$(BUILD_DIR)/%.o,$(TEST_SRCS))
TEST_EXECUTABLES := $(patsubst $(BUILD_DIR)/%.o,$(BUILD_DIR)/%,$(TEST_OBJS))

# Program executable
PROGRAM := program
PROGRAM_SRC := main.c
PROGRAM_OBJ := $(BUILD_DIR)/main.o

# Default target
all: $(PROGRAM) $(TEST_EXECUTABLES)

# Build rule for source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(LDLIBS) 

# Build rule for test files
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@ $(LDLIBS)

# Build and run test executables
$(BUILD_DIR)/%: $(BUILD_DIR)/%.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)
	@echo "Running $@"
	@./$@

# Build and run program executable
$(PROGRAM): $(PROGRAM_OBJ) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)
	@echo "Running $(PROGRAM)"
	@./$(PROGRAM)

# Run unit tests
test: $(TEST_EXECUTABLES)
	@for test_exec in $(TEST_EXECUTABLES); do \
		echo "Running $$test_exec"; \
		./$$test_exec; \
	done

# Clean build artifacts
clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) $(PROGRAM)

.PHONY: all test clean
