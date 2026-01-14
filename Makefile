CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

main: cell.c
	$(CC) $(CFLAGS) -o main cell.c

clean:
	del main.exe  # Windows
	# ou rm -f main  # Linux/WSL

run: main
	./main.exe

.PHONY: clean run