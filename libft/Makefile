# moulinette
CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_*.c

all: lib clean
# CAREFUL!

re: clean all
# CAREFUL!

objects:
	@$(CC) $(CFLAGS) $(SRC) -c

clean:
	@rm -rf *.o

lib: objects
	@ar -rcs libft.a *.o

test: lib clean
	@$(CC) $(CFLAGS) libft_driver.c libft.a -o test.out
	@./test.out
	@rm -f test.out