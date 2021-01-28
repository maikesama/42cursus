CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_*.c
OBJ = *.o
DRV = libft_driver.c

all: lib clean

re: clean all

objects:
	@$(CC) $(CFLAGS) $(SRC) -c

clean:
	@rm -rf $(OBJ)

lib: objects
	@ar -rcs libft.a $(OBJ)

test: lib clean
	@$(CC) $(CFLAGS) $(DRV) libft.a -o test.out
	@./test.out
	@rm -f test.out

BSD = -lbsd
ltest: lib clean
	@$(CC) $(CFLAGS) $(DRV) $(BSD) libft.a -o test.out
	@./test.out
	@rm -f test.out

DBG = -g -fsanitize=address
memtest: lib clean
	@$(CC) $(CFLAGS) $(DRV) $(DBG) libft.a -o test.out
	@./test.out
	@rm -f test.out

lmemtest: lib clean
	@$(CC) $(CFLAGS) $(DRV) $(DBG) $(BSD) libft.a -o test.out ; ASAN_OPTIONS=detect_leaks=1
	@./test.out
	@rm -f test.out

valgrind: lib clean
	@$(CC) $(CFLAGS) -g $(DRV) $(BSD) libft.a -o test.out
	@valgrind --track-origins=yes -s ./test.out
	@rm -f test.out