CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

main: shell.c
	$(CC) $(CFLAGS) -o main shell.c

clean:
	del main.exe  # Windows
	# ou rm -f main  # Linux/WSL

run: main
	./main.exe

.PHONY: clean run