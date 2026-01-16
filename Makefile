CC = gcc
CFLAGS = -Wall -Wextra -Werror 
#CFLAGS = -Wall -Wextra 
SRC = shell.c
TARGET = main


all: $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: all clean
