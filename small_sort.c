/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:04:08 by asaadane          #+#    #+#             */
/*   Updated: 2023/05/28 21:18:52 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack *stack, t_size *size)
{
	int	a;
	int	b;
	int	c;

	a = stack->a[0];
	b = stack->a[1];
	c = stack->a[2];
	if (a > b && b < c && c > a)
		sa(stack->a, 1);
	else if (a > b && b > c && a > c)
	{
		sa(stack->a, 1);
		rra(stack->a, size->a, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack->a, size->a, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack->a, 1);
		ra(stack->a, size->a, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack->a, size->a, 1);
}

void	ft_sort_4(t_stack *stack, t_size *size)
{
	small_to_top(stack->a, size->a);
	pb(stack, size);
	ft_sort_3(stack, size);
	pa(stack, size);
}

void	ft_small_sort(t_stack *stack, t_size *size)
{
	if (size->a == 2)
		sa(stack->a, 1);
	else if (size->a == 3)
		ft_sort_3(stack, size);
	else if (size->a == 4)
		ft_sort_4(stack, size);
	else if (size->a == 5)
	{
		small_to_top(stack->a, size->a);
		pb(stack, size);
		ft_sort_4(stack, size);
		pa(stack, size);
	}
}

void	ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}
