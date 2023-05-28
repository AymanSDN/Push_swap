/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:03:29 by asaadane          #+#    #+#             */
/*   Updated: 2023/05/28 16:06:14 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack, t_size *size)
{
	int	i;
	int	position_a;

	if (!size->b)
		exit(1);
	i = 0;
	position_a = size->a;
	while (position_a >= 0)
	{
		stack->a[position_a + 1] = stack->a[position_a];
		position_a--;
	}
	size->a++;
	stack->a[0] = stack->b[0];
	while (i < size->b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	size->b--;
	write(1, "pa\n", 3);
}

void	sa(int *stack_a, int p)
{
	int	temp;

	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	if (p == 1)
		write(1, "sa\n", 3);
}

void	ra(int *stack_a, int size_a, int p)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_a[0];
	while (i < size_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i - 1] = temp;
	if (p == 1)
		write(1, "ra\n", 3);
}

void	rra(int *stack_a, int size_a, int p)
{
	int	i;
	int	temp;

	i = size_a - 1;
	temp = stack_a[i];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = temp;
	if (p == 1)
		write(1, "rra\n", 4);
}
