/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:22:28 by asaadane          #+#    #+#             */
/*   Updated: 2023/05/21 01:12:50 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int ft_check_integers(char **splited, int size_a)
{
	int i;
	int j;
	char *arg;

	i = 0;
	j = 0;

    while (*splited != NULL)
	{
        char *arg = *splited;
        while (*arg != '\0')
		{
				/* code */
			
            if (!ft_isdigit(*arg))
			{
				write(2, "Error\n", 7);
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
				write(2, "Error\n", 7);
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



char** splitArguments(int ac, char **av)
{
    char **splited;
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

        if (spacePos == NULL)
		{
            splited[splitedIndex] = strdup(arg);
            splitedIndex++;
        }
		else
		{

            char** tokens = ft_split(arg, ' ');
            j = 0;
            while (tokens[j] != NULL) {
                splited[splitedIndex] = strdup(tokens[j]);
                splitedIndex++;
                j++;
            }
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
	int *Temp;
	int i;
	int j;
	char **splited;
	char *arg;

	splited = splitArguments(ac, av);
	size.A = ft_count(splited);
	size.B = 0;
	if (size.A <= 1)
	{

        exit(1);
	}

	stack.A = malloc(sizeof(int) * size.A);
	stack.B = malloc(sizeof(int) * size.A);
	Temp = malloc(sizeof(int) * size.A);
	ft_check_integers(splited, size.A);
	i = 0;
	while(i < size.A)
	{
		if (strlen(splited[i]) > 12)
		{
			write(2, "Error\n", 7);
			exit(1);
		}
		stack.A[i] = ft_atoi(splited[i]);
		
		// printf("temp; %d\n", Temp[i]);
		i++;
	}
	ft_check_duplicate(stack.A, size.A);
	if (ft_check_sorted(stack.A, size.A))
        exit(1);
	i = 0;
	puts("	---before---");
	while(i < size.A)
	{
		printf("stack_A[%d]: %d	|  stack_B[%d]: %d\n", i, stack.A[i], i, stack.B[i]);
		i++;
	}
	puts("------------------");
	// copy_stack(stack, Temp, size);
	if (size.A <= 5)
		ft_small_sort(&stack, &size);
	// else if ( size.A <= 100)
	// 	// ft_sort_100(&stack, &size);
	// else
	// 	puts("hi");
	// 	ft_sort_500();
	puts("------------------");
	puts("	---After---");
	i = 0;
	while(i < size.A)
	{
		printf("stack_A[%d]: %d	|  stack_B[%d]: %d\n", i, stack.A[i], i, stack.B[i]);
		i++;
	}

	return 0;
}
