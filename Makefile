CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = shell.c forktest.c
TARGET = testshell

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run