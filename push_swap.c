/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:03:52 by asaadane          #+#    #+#             */
/*   Updated: 2023/05/28 21:20:13 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sign(char *splited)
{
	int	i;

	i = 0;
	if (ft_strlen(&splited[i]) > 12)
	{
		ft_put_error();
	}
	if (splited[i] == '-' || splited[i] == '+')
		i++;
	if (splited[i] == '\0')
	{
		ft_put_error();
	}
	while (splited[i] != '\0')
	{
		if (!ft_isdigit(splited[i]))
		{
			ft_put_error();
		}
		i++;
	}
}

void	load_stacks(t_stack *stack, t_size *size, char **splited)
{
	int	i;

	stack->a = (int *)malloc(sizeof(int) * (size->a + 1));
	if (!stack->a)
	{
		free_arguments(splited, size->a);
		exit (1);
	}
	size->b = 0;
	stack->b = (int *)malloc(sizeof(int) * (size->a + 1));
	if (!stack->b)
	{
		free(stack->a);
		free_arguments(splited, size->a);
		exit (1);
	}
	i = 0;
	while (i < size->a)
	{
		check_sign(splited[i]);
		stack->a[i] = ft_atoi(splited[i]);
		i++;
	}
}

void	ft_free_all(t_stack *stack, t_size *size, char **splited)
{
	free(stack->a);
	free(stack->b);
	free(stack);
	free(size);
	free_arguments(splited, size->a);
}

void	sorting(t_stack *stack, t_size *size, char **splited)
{
	if (size->a <= 5)
		ft_small_sort(stack, size);
	else if (size->a <= 100)
		large_sort(stack, size, 5);
	else
		large_sort(stack, size, 11);
	ft_free_all(stack, size, splited);
}

int	main(int ac, char **av)
{
	char	**splited;
	t_stack	*stack;
	t_size	*size;

	stack = malloc(sizeof(t_stack));
	size = malloc(sizeof(t_size));
	if (ac < 2)
		exit(1);
	count_argv(av, &size->a);
	splited = split_arguments(ac, av, &size->a);
	check_empty_arg(splited);
	load_stacks(stack, size, splited);
	if (size->a <= 1)
	{
		free_arguments(splited, size->a);
		exit (1);
	}
	ft_check_duplicate(stack->a, size->a);
	if (ft_check_sorted(stack->a, size->a))
	{
		ft_free_all(stack, size, splited);
		exit(1);
	}
	sorting(stack, size, splited);
	return (0);
}
