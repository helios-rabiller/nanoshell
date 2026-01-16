CC = gcc
# CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -Wall -Wextra 
SRC = shell.c
TARGET = testshell


all: $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: all clean
