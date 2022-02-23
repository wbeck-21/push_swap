#ifndef     PUSH_SWAP_H
# define	PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack {
    int nbr;
    struct s_stack *next;
} t_stack;

#endif