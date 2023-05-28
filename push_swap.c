#include "push_swap.h"

int	check_sign(char *splited)
{
	int	i;

	i = 0;
    if (strlen(&splited[i]) > 12)
	{
		write(2, "Error3\n", 7);
		exit(1);
	}
	if (splited[i] == '-' || splited[i] == '+')
		i++;
	if (splited[i] == '\0')
		{
            write(2, "shifo zaml\n", ft_strlen("shifo zaml\n"));
            return (1);
        }
	while (splited[i] != '\0')
	{
		if (!ft_isdigit(splited[i]))
			{
                write(2, "shifo zaml\n", ft_strlen("shifo zaml\n"));
                return (1);
            }
		i++;
	}
    return (0);
}

void load_stacks(t_stack *stack, t_size *size, char **splited)
{
    int i;

    stack->A = (int *)malloc(sizeof(int) * (size->A + 1));
    if (!stack->A)
    {
        free_arguments(splited, size->A);
        exit (1);
    }
    size->B = 0;
    stack->B = (int *)malloc(sizeof(int) * (size->A + 1));
    if (!stack->B)
    {
        free(stack->A);
        free_arguments(splited, size->A);
        exit (1);
    }
    i = 0;
    while (i < size->A)
    {
        if (check_sign(splited[i]))
                exit(1);
        stack->A[i] = ft_atoi(splited[i]);
        i++;
    }
}
void ft_free_all(t_stack *stack, t_size *size, char **splited)
{
    free(stack->A);
    free(stack->B);
    free(stack);
    free(size);
    free_arguments(splited, size->A);

}
void sorting(t_stack *stack, t_size *size , char **splited)
{
    if (size->A <= 5)
	    ft_small_sort(stack, size);
	else if ( size->A <= 100)
		large_sort(stack, size, 5);
	else
		large_sort(stack, size, 11);
    ft_free_all(stack, size, splited);
}
int main(int ac, char **av)
{
    t_stack *stack = malloc(sizeof(t_stack));
	t_size *size = malloc(sizeof(t_size));
    char **splited;
    if (ac < 2)
        exit(1);
    count_argv(av, &size->A);
    splited = split_arguments(av, &size->A);
    if (size->A <= 1)
    {
        free_arguments(splited, size->A);
        write(2, "Error2\n", 7);
        exit (1);
    }
    load_stacks(stack, size, splited);
    ft_check_duplicate(stack->A, size->A);
    if (ft_check_sorted(stack->A, size->A))
    {
        write(2, "The input array is already sorted.\n", 36);
        ft_free_all(stack, size, splited);
        exit(1);
    }
    sorting(stack, size, splited);
    return 0;
}
