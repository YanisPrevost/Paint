##
## EPITECH PROJECT, 2023
## MAKEFILES
## File description:
## COMPILE
##

COMPILATION	=	gcc *.c

NAME	=	my_paint

CSFML	=	-L. -lmy -lm -lcsfml-graphics \
-lcsfml-system -lcsfml-audio -lcsfml-window

all:
	$(COMPILATION) -o $(NAME) -I../includes $(CSFML)
	cp $(NAME) ../
	rm $(NAME)

fclean :
	rm -f $(NAME)

re: fclean all.c
