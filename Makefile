NAME	= push_swap

# B_NAME	= checker

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

LIB		= ./libft/libft.a

INC		= -I ./libft

SRCS	= push_swap.c parsing.c swap.c rotate.c rev_rotate.c fill_stack.c utils.c utils2.c moving_to_stack_a.c moving_to_stack_a2.c processor.c final_sort.c push.c

# B_SRCS	= push_swap.c parsing.c swap.c rotate.c rev_rotate.c fill_stack.c utils.c utils2.c moving_to_stack_a.c moving_to_stack_a2.c processor.c final_sort.c push.c

OBJS	= $(SRCS:.c=.o)

# B_OBJS	= $(B_SRCS:.c=.o)

HEADER	= push_swap.h

RM		= rm -rf

all:	$(NAME)

$(NAME):	$(OBJS)
		# rm -rf $(NAME)
		make -s -C libft
		$(CC) $(FLAGS) -fsanitize=address -o $(NAME) $? $(LIB)

# $(B_NAME): all

%.o:	%.c
		$(CC) $(FLAGS) $(INC) -c $< -o $@

bonus: $(B_NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re