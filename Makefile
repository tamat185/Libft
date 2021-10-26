NAME = libft.a

SRC = $(shell find . -name "*.c")

SRC_BONUS = $(shell find . -name "*_bonus.c")

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CFLAGS = -Wall -Werror -Wextra

COMPILE = gcc $(CFLAGS) -c

LIB = ar rcs $(NAME)

RM = rm -rf

all: $(NAME)

$(NAME): libft.h
	$(COMPILE) $(SRC)
	$(LIB) $(OBJ)

bonus:

	$(COMPILE) $(SRC)
	$(LIB) $(OBJ)

clean:
	$(RM) *.o
	$(RM) touch

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re