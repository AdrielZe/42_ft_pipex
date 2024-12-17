# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

NAME        := pipex
CC          := cc
# CFLAGS      := -Wall -Wextra -Werror
INCLUDES    := -I includes -I libft
LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a

SRCS_DIR    := src
SRCS        := $(addprefix $(SRCS_DIR)/, pipex.c pipex_utils.c) # Adicione mais arquivos aqui
OBJS        := $(SRCS:.c=.o)

# **************************************************************************** #
#                                  TARGETS                                     #
# **************************************************************************** #

all: $(NAME)

# Compila a libft e o executável principal
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)

# Compila a libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Regras de compilação para os arquivos .c
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Regra para rodar o Valgrind
valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) file1 "cmd1" "cmd2" file2

# Limpa os objetos e executáveis gerados
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re valgrind
