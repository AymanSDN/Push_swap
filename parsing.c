/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shifuuu <shifuuu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:22:28 by asaadane          #+#    #+#             */
/*   Updated: 2023/05/26 10:36:33 by shifuuu          ###   ########.fr       */
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
    int i = 0;
    int j;

    while (splited[i])
    {
        if (splited[i] == NULL)
        {
            write(2, "Error\n", 7);
            exit(1);
        }
        j = 0;
        while (splited[i][j] != '\0')
        {
            if(splited[i][j] == '-' || splited[i][j] == '+')
            {
                j++;
            }
            if (isdigit(splited[i][j]))
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
	while (i < size_a) {
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

char** splitarguments(char **av, t_size *size)
{
    char **splited;
	char **tokens;
	char* spacePos;
    int splitIndex;
    int i;
	int j;

	i = 1;
	int w = 1;
    static int word_count;
    while(av[w])
    {
        word_count += count_words(av[w]);
        w++;
    }
    size->A = word_count;
	splitIndex = 0;
    splited = (char**)malloc(sizeof(char*) * word_count);
    while (av[i])
    {
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
            while (tokens[j] != NULL)
            {
                splited[splitIndex] = strdup(tokens[j]);
                splitIndex++;
                j++;
            }
            while (j > 0) {
                free(tokens[j]);
                j--;
            }
            free(tokens);
        }
        i++;
    }
    return (splited);
}


int main (int ac, char **av)
{
    (void)ac;
	t_stack *stack = malloc(sizeof(t_stack));
	t_size *size = malloc(sizeof(t_size));
	int i;
	char **splited = NULL;
    
	splited = splitarguments(av, size);
	ft_check_integers(splited);
	size->B = 0;
	if (size->A <= 1)
        exit(0);
	stack->A = malloc(sizeof(int) * size->A);
	stack->B = malloc(sizeof(int) * size->A);
	i = 0;
	while(i < size->A)
	{
		if (strlen(splited[i]) > 12)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		stack->A[i] = ft_atoi(splited[i]);
		i++;
	}
	ft_check_duplicate(stack->A, size->A);
	if (ft_check_sorted(stack->A, size->A))
        exit(1);
	if (size->A <= 5)
	    ft_small_sort(stack, size);
	else if ( size->A <= 100)
		large_sort(stack, size, 5);
	else
		large_sort(stack, size, 10);
	free(stack->A);
	free(stack->B);
	return (0);
}

