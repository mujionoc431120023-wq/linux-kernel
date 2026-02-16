# OS-Mini AI Linux Edition Makefile
CC = gcc
CFLAGS = -Wall -O2 -I../include
LDFLAGS =

# Source files (in current directory)
SRCS = main.c ai_hub.c codeagent.c
OBJS = $(SRCS:.c=.o)

# Target executable
TARGET = os-mini-ai

.PHONY: all clean run help

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run in interactive mode
run: $(TARGET)
	./$(TARGET)

# Run with command line arguments
cli: $(TARGET)
	./$(TARGET) --codeagent "algorithm"

# Examples
example-health: $(TARGET)
	./$(TARGET) --health "demam"

example-codeagent: $(TARGET)
	./$(TARGET) --codeagent "performance"

example-codegen: $(TARGET)
	./$(TARGET) --codegen c "linked list"

example-debug: $(TARGET)
	./$(TARGET) --debug "null pointer"

clean:
	rm -f $(OBJS) $(TARGET)

help:
	@echo "OS-Mini AI Linux Edition"
	@echo "========================="
	@echo "make              - Build the application"
	@echo "make run          - Run in interactive mode"
	@echo "make cli          - Run with CLI argument"
	@echo "make example-health   - Example: health AI"
	@echo "make example-codeagent - Example: codeagent analyze"
	@echo "make example-codegen   - Example: code generation"
	@echo "make example-debug    - Example: debug"
	@echo "make clean        - Clean build files"

