##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Finalstumper
##

CC	=	clang

SRC	=	src/main.c	\

NAME	=	calculator

all:	$(NAME)

$(NAME):
	clang -o $(NAME) $(SRC) -g3

clean:
	rm -f *~
	rm -f *#
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

unit_tests:	fclean $(NAME)
	clang -o hidenp_test src/my_strlen.c src/check_errors.c src/hidenp.c tests/test_hidenp.c --coverage -lcriterion

tests_run:	unit_tests
		./hidenp_test
