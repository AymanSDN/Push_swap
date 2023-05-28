/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:04:17 by asaadane          #+#    #+#             */
/*   Updated: 2023/05/28 18:26:31 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_largest(int *stack, int size)
{
	int	i;
	int	largest;

	i = 1;
	largest = stack[0];
	while (i < size)
	{
		if (stack[i] > largest)
		{
			largest = stack[i];
		}
		i++;
	}
	return (largest);
}

int	get_smallest(int *stack, int size)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = stack[0];
	while (i < size)
	{
		if (stack[i] < smallest)
		{
			smallest = stack[i];
			return (smallest);
		}
		i++;
	}
	return (0);
}

int	get_number_position(int *stack, int size, int number)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] == number)
			return (i);
		i++;
	}
	return (0);
}

void	small_to_top(int *stack, int size)
{
	int	smallest;
	int	position;

	smallest = get_smallest(stack, size);
	position = get_number_position(stack, size, smallest);
	while (position)
	{
		if (position > (size / 2))
		{
			while (smallest != stack[0])
			{
				rra(stack, size, 1);
			}
		}
		else
		{
			while (smallest != stack[0])
			{
				ra(stack, size, 1);
			}
		}
		position--;
	}
}
