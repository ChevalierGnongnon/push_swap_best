LIBFT = libft/libft.a

SOURCES = sources/algo_1.c \
			sources/algo_2.c \
			sources/checks.c \
			sources/commands_1.c \
			sources/commands_2.c \
			sources/counting.c \
			sources/do_rotates.c \
			sources/do_swap.c \
			sources/double_action.c \
			sources/main.c \
			sources/nodes.c \
			sources/small_sort.c \
			sources/utils_lists.c \
			sources/ft_atol.c \
			sources/utils_nodes.c 
			
OBJS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re