#include "push_swap.h"
#include <string.h>


int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int ft_check_integers(char **splited, int size_a)
{
	int i;
	int j;
	char *arg;

	i = 0;
	j = 0;

    while (*splited != NULL)
	{
        const char *arg = *splited;
        while (*arg != '\0') {
            if (!ft_isdigit(*arg))
			{
				write(2, "it must be only integers !!\n", 29);
                exit(1);
            }
            arg++;
        }
        splited++;
    }
    return 0;  
}

void ft_check_duplicate(int *stack_a, int size_a)
{
	int i;
	int j;

	i = 0;
	while (i < size_a) {
		j =  i + 1;
		while (j < size_a) {
			if (stack_a[i] == stack_a[j])
			{
				printf("stack_%d: %d\n", i, stack_a[i]);
				printf("stack_%d: %d\n", j, stack_a[j]);
				puts("duplicate found !!");
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

char** splitArguments(int ac, char **av)
{
    // Allocate memory to store split elements
    char** splited;
    int splitedIndex;
    int i;
	int j;
	int k;

	i = 1;
	splitedIndex = 0;
    splited = (char**)malloc(sizeof(char*) * ac * 2);
    while (i < ac) {
        char* arg = av[i];
        char* spacePos = strchr(arg, ' ');

        if (spacePos == NULL) {
            // No space found, store the argument as is
            splited[splitedIndex] = strdup(arg);
            splitedIndex++;
        } else {
            // Space found, split the argument using ft_split
            char** tokens = ft_split(arg, ' ');
            j = 0;
            while (tokens[j] != NULL) {
                splited[splitedIndex] = strdup(tokens[j]);
                splitedIndex++;
                j++;
            }
            // Free memory allocated by ft_split
            k = 0;
            while (k < j) {
                free(tokens[k]);
                k++;
            }
            free(tokens);
        }

        i++;
    }

    // *numSplited = splitedIndex;
    return splited;
}

int main(int ac, char **av) {
	t_stack stack;
	t_size size;
	int i;
	int j;
	char **splited;
	char *arg;

	if (ac < 2)
	{
		write(2,"Usage: ./push_swap <list of integers>\n", 39);
		exit(1);
	}
	splited = calloc(sizeof(char*), size.A);
	splited = splitArguments(ac, av);
	size.A = ft_count(splited);
	if (size.A == 1)
	{
	    write(2,"Usage: ./push_swap <list of integers>\n", 39);
	    exit(1);
	}

	stack.A = malloc(sizeof(int) * size.A);
	stack.B = malloc(sizeof(int) * size.A);
	ft_check_integers(splited, size.A);
	i = 0;
	while(i < size.A)
	{
		stack.A[i] = ft_atoi(splited[i]);
		i++;
	}
	ft_check_duplicate(stack.A, size.A);
	if (ft_check_sorted(stack.A, size.A))
	{
        write(2, "numbers is already sorted !!\n", 30);
		exit(1);
	}
	i = 0;
	puts("	---before---");
	while(i < size.A)
	{
		printf("stack_A[%d]: %d	|  stack_B[%d]: %d\n", i, stack.A[i], i, stack.B[i]);
		i++;
	}
	puts("------------------");
	ft_small_sort(stack, size);
	puts("------------------");
	i = 0;
	puts("	---After---");
	while(i < size.A)
	{
		printf("stack_A[%d]: %d	|  stack_B[%d]: %d\n", i, stack.A[i], i, stack.B[i]);
		i++;
	}
	return 0;
}
