NAME	= push_swap

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

LIB		= ./libft/libft.a

INC		= -I ./libft

SRCS	= push_swap.c parsing.c swap.c rotate.c rev_rotate.c fill_stack.c utils.c moving_to_stack_a.c processor.c

OBJS	= $(SRCS:.c=.o)

HEADER	= push_swap.h

RM		= rm -rf

all:	$(NAME)

$(NAME):	$(OBJS)
		# rm -rf $(NAME)
		make -s -C libft
		$(CC) $(FLAGS) -o $(NAME) $? $(LIB)

%.o:	%.c
		$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re