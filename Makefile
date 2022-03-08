NAME	= push_swap

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

LIB		= ./libft/libft.a

INC		= -I ./libft

SRCS	= push_swap.c parsing.c \
		swap.c rotate.c rev_rotate.c push.c \
		fill_stack_a.c fill_stack_b.c \
		utils.c utils2.c sorting.c \
		moving_to_stack_a.c moving_to_stack_a2.c \
		processor.c final_sort.c 

OBJS	= $(SRCS:.c=.o)

HEADER	= push_swap.h

RM		= rm -rf

all:	$(NAME)

$(NAME):	$(OBJS)
		@$(RM) $(NAME)
		@make -s -C libft
		$(CC) $(FLAGS) -fsanitize=address -o $(NAME) $? $(LIB)

%.o:	%.c $(HEADER)
		$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
		@make -s $@ -C libft
		@$(RM) $(OBJS)

fclean:	clean
		@make -s $@ -C libft
		@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re