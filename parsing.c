#include "push_swap.h"


int	ft_isdigit(int c)
{
	if(c >= '0' && c <= '9')
	{
		return (1);
	}
	return(0);
}

int ft_count(char **splited)
{
	int i;

	i = 0;
	while (splited[i])
	{
		i++;
	}
	return(i);
	
}

void ft_check_integers(char **splited)
{
    int i = 0;
    int j;

    while (splited[i] != NULL)
    {
        j = 0;
        while (splited[i][j] != '\0')
        {
            if((splited[i][j] == '-' || splited[i][j] == '+') && !isdigit(splited[i][j + 1]))
            {
                write(2, "must be only integers\n", 23);
                exit(1);
            } 
            else if (isdigit(splited[i][j]) || (splited[i][j] == '-' || splited[i][j] == '+'))
            {
                j++;
            }
            else
            {
                write(2, "must be only integers\n", 23);
                exit(1);
            }
        }
        i++;
    }
}



void ft_check_duplicate(int *stack_a, int size_a)
{
	int i;
	int j;

	i = 0;
	while (i < size_a -1) {
		j =  i + 1;
		while (j < size_a) {
			if (stack_a[i] == stack_a[j])
			{
				printf("n1 = %d | n2 = %d\n", stack_a[i], stack_a[j]);
				write(2, "duplicate found !!\n", 20);
                exit(1);
			}
			j++;
		}
		i++;
	}
}

bool ft_check_sorted(int *stack_a, int size_a)
{
	int i;

	i = 0;
	while (i < size_a - 1)
	{
        if (stack_a[i] > stack_a[i + 1])
            return false;
		i++;
    }
    return true;
}


int count_words(char *arg)
{
    
    int count = 0;
    int in_word = 0;
    
    int i = 0;

    while (arg[i] != '\0')
    {
        if (arg[i] == '\0')
        {
            write(2, "Error\n", 7);
            exit(1);
        }
        else if (arg[i] == ' ')
        {
            in_word = 0;
        }
        else if (!in_word) {
            count++;
            in_word = 1;
        }
        i++;
    }
    return count;
}

char **split_arguments(char **av, int *size_A)
{
    char **splited;
    int spl_index = 0;
    char *arg;
    size_t i = 1;
    size_t j;

    while(av[i] != NULL)
    {
        *size_A += count_words(av[i]);
        i++;
    }

    splited = (char **)malloc(sizeof(char *) * (*size_A + 1));
    if (splited == NULL)
    {
        exit(1);
    }
    i = 1;
    while (av[i] != NULL)
    {
        arg = av[i];
        int word_start = 0;
        j = 0;
        while (j <= strlen(arg))
        {
            if (arg[j] == ' ' || arg[j] == '\0')
            {
                int word_len = j - word_start;
                if (word_len > 0)
                {
                    splited[spl_index] = (char *)malloc(sizeof(char) * (word_len + 1));
                    if (!splited[spl_index])
                    {
                        free(splited[spl_index]);
                        exit(1);
                    }
                    strncpy(splited[spl_index], arg + word_start, word_len);
                    splited[spl_index][word_len] = '\0';
                    spl_index++;
                }
                word_start = j + 1;
            }
            j++;
        }
        i++;
    }

    return splited;
}

void free_arguments(char **splited, int size_a)
{
    int i = 0;
    while (i < size_a)
    {
        free(splited[i]);
        i++;
    }
    free(splited);
}


int main(int ac, char **av)
{

    t_stack *stack = malloc(sizeof(t_stack));
	t_size *size = malloc(sizeof(t_size));
    char **splited;
    int i;
    if (ac < 2)
    {
        write(2, "No arguments provided.\n", 24);
        return 1;
    }
    splited = split_arguments(av, &size->A);
    ft_check_integers(splited);
    if (size->A <= 1)
    {
        free_arguments(splited, size->A);
        write(2, "Error\n", 7);
        exit (1);
    }
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
        free_arguments(splited, size->A);
        exit (1);
    }
    i = 0;
    while (i < size->A)
    {
        if (strlen(splited[i]) > 12)
		{
			write(2, "Error\n", 7);
			exit(1);
		}
        stack->A[i] = ft_atoi(splited[i]);
        i++;
    }
    ft_check_duplicate(stack->A, size->A);
    if (ft_check_sorted(stack->A, size->A))
    {
        write(2, "The input array is already sorted.\n", 36);
        free(stack->A);
        free(stack->B);
        free(stack);
        free(size);
        free_arguments(splited, size->A);
        exit(1);
    }
    if (size->A <= 5)
	    ft_small_sort(stack, size);
	else if ( size->A <= 100)
		large_sort(stack, size, 5);
	else
		large_sort(stack, size, 11);
    free(stack->A);
    free(stack->B);
    free(stack);
    free(size);
    free_arguments(splited, size->A);
    
    return 0;
}


