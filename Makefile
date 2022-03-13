NAME		= push_swap
B_NAME		= checker

CC			= gcc

FLAGS		= -Wall -Wextra -Werror

LIB			= ./libft/libft.a

INC			= -I ./libft

SRCS		= push_swap.c parsing.c \
			swap.c rotate.c rev_rotate.c push.c \
			fill_stack_a.c fill_stack_b.c \
			utils.c utils2.c sorting.c \
			moving_to_stack_a.c moving_to_stack_a2.c \
			processor.c final_sort.c \
			validation.c create_matrix.c

B_SRCS 		= checker.c fill_stack_a.c \
			swap_bonus.c rotate_bonus.c rev_rotate_bonus.c push_bonus.c \
			get_next_line.c get_next_line_utils.c \
			utils.c utils2.c \
			validation.c create_matrix.c

OBJS		= $(SRCS:.c=.o)
B_OBJS		= $(B_SRCS:.c=.o)

HEADER		= push_swap.h
B_HEADER	= checker.h

RM		= rm -rf

all:	$(NAME) $(B_NAME)

$(NAME):	$(OBJS)
		@make -s -C libft
		$(CC) $(FLAGS) -fsanitize=address -o $(NAME) $? $(LIB)

$(B_NAME):	$(B_OBJS)
		@make -s -C libft
		$(CC) $(FLAGS) -fsanitize=address -o $(B_NAME) $? $(LIB)

%.o:	%.c $(HEADER) $(B_HEADER)
		$(CC) $(FLAGS) $(INC) -c $< -o $@

# bonus:	%.c $(B_HEADER)
# 		$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
		@make -s $@ -C libft
		@$(RM) $(OBJS)
		@$(RM) $(B_OBJS)

fclean:	clean
		@make -s $@ -C libft
		@$(RM) $(NAME)
		@$(RM) $(B_NAME)

re:	fclean all

.PHONY:	all clean fclean re