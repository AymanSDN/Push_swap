/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:03:44 by asaadane          #+#    #+#             */
/*   Updated: 2023/05/28 18:35:38 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_indexing(int *stack, int size_a)
{
	int	i;
	int	j;
	int	temp;
	int	*tmp_stack;

	tmp_stack = malloc(sizeof(int) * size_a);
	i = 0;
	temp = 0;
	while (i < size_a)
	{
		j = 0;
		temp = 0;
		while (j < size_a)
		{
			if (stack[i] > stack[j])
				temp++;
			j++;
		}
		tmp_stack[i] = temp;
		i++;
	}
	i = -1;
	while (++i < size_a)
		stack[i] = tmp_stack[i];
	free(tmp_stack);
}

void	a_to_b(t_stack *stack, t_size *size, int num)
{
	int	i;
	int	chunk;
	int	scale_chunk;

	i = 0;
	chunk = (size->a / num) + (size->a % num);
	scale_chunk = size->a / num;
	while (i < chunk)
	{
		if (stack->a[0] <= chunk)
		{
			pb(stack, size);
			if (stack->b[0] > (chunk - (scale_chunk / 2)))
				rb(stack->b, size->b, 1);
			i++;
		}
		else
			ra(stack->a, size->a, 1);
		if (i == chunk && chunk < ((scale_chunk * num) + (size->a % num)))
		{
				chunk += scale_chunk;
		}
	}
}

void	b_to_a(t_stack *stack, t_size *size)
{
	int	largest;
	int	largest_position;

	while (size->b)
	{
		largest = get_largest(stack->b, size->b);
		largest_position = get_number_position(stack->b, size->b, largest);
		if (largest_position >= size->b / 2)
		{
			while (largest != stack->b[0])
			{
				rrb(stack->b, size->b, 1);
			}
		}
		else
		{
			while (largest != stack->b[0])
			{
				rb(stack->b, size->b, 1);
			}
		}
		pa(stack, size);
	}
}

void	large_sort(t_stack *stack, t_size *size, int num)
{
	stack_indexing(stack->a, size->a);
	a_to_b(stack, size, num);
	b_to_a(stack, size);
}
