# include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc > 1)
        parsing(argc, argv);
    else
        write(1, "Error!\n", 7);
    return 0;
}