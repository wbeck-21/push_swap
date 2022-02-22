# include "push_swap.h"

int main(int argc, char **argv)
{
    char *res;
    int i;
    
    i = 1;
    if (argc > 1)
    {
        res = ft_calloc(1, 1);
        if (!res)
        {
            write(1, "Error!\n", 7);
            return 0;
        }

        while (i < argc)
        {
            res = ft_strjoin(res, argv[i]);
            printf("%s\n", argv[i]);
            i++;
        }
        printf("%s\n", res);
    }
    else
        write(1, "Error!\n", 7);
    return 0;
}