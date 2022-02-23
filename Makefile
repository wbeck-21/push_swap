NAME	= push_swap

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

LIB		= ./libft/libft.a

INC		= -I ./libft

SRCS	= push_swap.c parsing.c swap.c rotate.c rev_rotate.c

OBJS	= $(SRCS:.c=.o)

HEADER	= push_swap.h

RM		= rm -rf

all:	$(NAME)

$(NAME):	$(OBJS)
		# rm -rf $(NAME)
		make -s -C libft
		$(CC) $(FLAGS) -fsanitize=address -o $(NAME) $? $(LIB)

%.o:	%.c
		$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re