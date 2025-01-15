##
## EPITECH PROJECT, 2023
## MAKEFILES
## File description:
## COMPILE AND CREATE LIBRARY
##
SRC	=\
	digits_formatbis.c my_strcmp.c my_str_to_int.c\
	my_nbr_hexa.c my_nbr_hexasupp.c my_nbr_octal.c\
	my_putchar.c my_put_binary.c my_strncpy.c\
	my_put_nbr.c my_putstr.c hexal_format.c\
	my_arrondie.c my_strcat.c my_strcpy.c\
	my_float.c my_compute_speit.c my_strdup.c\
	my_strlen.c digits_formatbis.c\
	my_precise_float.c my_putmanynegchar0.c\
	expo_format.c my_putmanychar0.c\
	digits_format.c string_format.c my_printf.c count0.c\
	my_expotentiel.c my_expotentielsupp.c my_otherchoice.c\
	my_putmanynegchar.c my_putmanychar.c my_otherchoicesupp.c\
	digits_formatbisbis.c formattris.c my_spacefloat.c counter.c\
	my_spaceexpotentielsupp.c my_spaceexpotentiel.c my_spaceputmanychar.c\
	formatquadris.c formatquentis.c my_putallnbr.c\
	my_plusexpotentiel.c my_plusexpotentielsupp.c my_plusfloat.c\
	my_put_plusnbr.c my_spaceputallnbr.c my_str_to_word_array.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) *.o
	cp libmy.a ../../code
	rm *.o
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
