##
## Makefile for libkaas in /home/antoine.casse/Desktop/lib
## 
## Made by Antoine Casse
## Login   <antoine.casse@epitech.net>
## 
## Started on  Tue Jan 24 16:31:33 2017 Antoine Casse
## Last update Fri May 26 12:58:46 2017 Capitaine CASSE
##

SRC	=	my_strlen.c	\
		gnl.c		\
		my_putchar.c	\
		my_putstr.c	\
		my_strcat.c	\
		my_puterr.c	\
		my_put_nbr.c	\
		my_getnbr.c	\
		my_strdup.c	\
		wordtab.c	\
		my_strcmp.c	\
		my_strncmp.c	\
		my_getnbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libkaas.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
