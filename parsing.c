/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shifuuu <shifuuu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:22:28 by asaadane          #+#    #+#             */
/*   Updated: 2023/05/22 00:39:12 by shifuuu          ###   ########.fr       */
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


void ft_check_integers(char **splited)
{
    char *arg;

    while (*splited != NULL)
    {
        arg = *splited;
        if (*arg == '-' || *arg == '+')
        {
            arg++;
        }
        while (*arg != '\0')
        {
            if (isdigit(*arg))
            {
                arg++;
            }
            else
            {
                write(2, "Error\n", 6);
                exit(1);
            }
        }
        splited++;
    }
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
	char **tokens;
	char* spacePos;
    int splitIndex;
    int i;
	int j;
	// int k;

	i = 1;
	splitIndex = 0;
    splited = (char**)malloc(sizeof(char*) * ac * 2);
    while (i < ac) {
        spacePos = strchr(av[i], ' ');

        if (spacePos == NULL)
		{
            splited[splitIndex] = strdup(av[i]);
            splitIndex++;
        }
		else
		{

            tokens = ft_split(av[i], ' ');
            j = 0;
            while (tokens[j] != NULL) {
                splited[splitIndex] = strdup(tokens[j]);
                splitIndex++;
                j++;
            }
            // k = 0;
            // while (k < j) {
            //     free(tokens[k]);
            //     k++;
            // }
            // free(tokens);
        }

        i++;
    }

    return (splited);
}

int main(int ac, char **av) {
	t_stack stack;
	t_size size;
	int i;
	char **splited;

	splited = splitArguments(ac, av);
	ft_check_integers(splited);
	size.A = ft_count(splited);
	size.B = 0;
	if (size.A <= 1)
	{
        exit(1);
	}
	stack.A = malloc(sizeof(int) * size.A);
	stack.B = malloc(sizeof(int) * size.A);
	i = 0;
	while(i < size.A)
	{
		// if (strlen(splited[i]) > 12)
		// {
		// 	write(2, "Error\n", 7);
		// 	exit(1);
		// }
		stack.A[i] = ft_atoi(splited[i]);
		i++;
	}
	ft_check_duplicate(stack.A, size.A);
	if (ft_check_sorted(stack.A, size.A))
        exit(1);
	if (size.A <= 5)
		ft_small_sort(&stack, &size);
	else if ( size.A <= 100)
		large_sort(&stack, &size, 5);
	// else
	// 	ft_sort_500();
		for(int i = 0; stack.Temp[i]; i++)
	{
		printf("stack_A[%d] = %d  |    Temp[%d] = %d \n", i, stack.A[i], i, stack.Temp[i]);
	}
	return 0;
}
