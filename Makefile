##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	main.c

NAME =	bsq

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -L./lib/my -lmy

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -c lib/my/*.c
	ar rc lib/my/libmy.a *.o
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(LDFLAGS)
	@echo "all done"
clean:
	rm *.o
	rm lib/my/libmy.a
	@echo "all clean"

fclean: clean
	rm -f $(NAME)

re:	$(NAME)