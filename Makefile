NAME = libasm.a
ASM = nasm
ASMFLAGS = -f elf64

CC = gcc
CFLAGS = -Wall -Wextra -Werror -no-pie

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ) Makefile
	ar rcs $(NAME) $(OBJ)
	@echo "Librería creada: $(NAME)"

%.o: %.s
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Archivos objeto eliminados."

fclean: clean
	@rm -f $(NAME)
	@echo "Librería eliminada."
re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) -o test_program main.c $(NAME)
	@echo "Programa de prueba compilado."

.PHONY: all clean fclean re test

#gcc main.c ft_strlen.o ft_strcpy.o ft_strcmp.o ft_write.o ft_read.o ft_strdup.o -o main -no-pie
