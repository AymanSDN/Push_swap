/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:22:22 by asaadane          #+#    #+#             */
/*   Updated: 2023/05/22 01:57:15 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_count_stack(int *stack)
{
	int i = 0;
	while(stack[i])
	{
		i++;
	}
	return(i);
}

void pa(t_stack *stack, t_size *size)
{
	int i;
	int position_a;

	i = 0;
	position_a = size->A;
	while (position_a >= 0)
	{
		stack->A[position_a + 1] = stack->A[position_a];
		position_a--;
	}
	stack->A[0] = stack->B[0];
	while(i < size->B)
	{
		stack->B[i] = stack->B[i + 1];
		i++;
	}
	size->B--;
	size->A++;
	write(1, "pa\n", 3);
}

void pb(t_stack *stack, t_size *size)
{
	int i;
	int position_b;

	i = 0;
	position_b = size->B;
	size->B++;
	while (position_b >= 0)
	{
		stack->B[position_b] = stack->B[position_b - 1];
		position_b--;
	} 
	stack->B[0] = stack->A[0];
	while(i < size->A)
	{
		stack->A[i] = stack->A[i + 1];
		i++;
	}
	size->A--;
	write(1, "pb\n", 3);
}

void sa(int *stack_a, int p)
{
	int temp;

	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	if (p == 1)
		write(1, "sa\n", 3);
}

void sb(int *stack_b, int p)
{
	int temp;

	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	if (p == 1)
		write(1, "sb\n", 3);
}

void ss(int *stack_a, int *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	write(1, "ss\n", 3);
}

void ra(int *stack_a, int p)
{
	int i;
	int temp;

	i = 0;
	temp = stack_a[0];
	while (stack_a[i])
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i - 1] = temp;
	if (p == 1)
		write(1, "ra\n", 3);
}

void rb(int *stack_b, int p)
{
	int i;
	int temp;

	i = 0;
	temp = stack_b[0];
	while (stack_b[i])
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i - 1] = temp;
	if (p == 1)
		write(1, "rb\n", 3);
}

void rr(int *stack_a, int *stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}

void rra(int *stack_a, int size_a, int p)
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

void rrb(int *stack_b, int size_b, int p)
{
	int	i;
	int	temp;

	i = size_b - 1;
	temp = stack_b[i];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = temp;
	if (p == 1)
		write(1, "rrb\n", 4);
}

void rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	rra(stack_a, size_a, 0);
	rrb(stack_b, size_b, 0);
	write(1, "rrr\n", 4);
}
