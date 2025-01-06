# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

NAME        := pipex
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
INCLUDES    := -I includes -I libft
LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a

SRCS_DIR    := src
SRCS        := $(addprefix $(SRCS_DIR)/, pipex.c pipex_utils.c)
OBJS        := $(SRCS:.c=.o)

# **************************************************************************** #
#                                  TARGETS                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) file1 "cmd1" "cmd2" file2

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re valgrind
