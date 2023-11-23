# Nombre del compilador
CC = gcc

# Opciones de compilación
CFLAGS = -Wall -Wextra -Werror

# Nombre del archivo fuente y del archivo objeto
SRC = libft.c
OBJ = $(SRC:.c=.o)

# Nombre de la biblioteca estática
LIB = libft.a

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re
