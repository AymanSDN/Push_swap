/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:22:41 by asaadane          #+#    #+#             */
/*   Updated: 2023/05/19 16:22:42 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void small_to_top(int *stack, int size)
{
	int i = 0;
	int position= 0;
	
	// printf("size: %d\n", size);
    int smallest = stack[0];
    while (i < size) {
        if (stack[i] < smallest)
		{
            smallest = stack[i];
			position = i;
        }
		i++;
    }
	while(position)
	{
		ra(stack, 1);
		position--;
	}
	// printf("Smallest number position: %d\n%d", smallest, position);
}
void ft_sort_3(t_stack *stack, t_size *size)
{
	// printf("==\n");
	//case 1
	if (stack->A[0] > stack->A[1] && stack->A[1] < stack->A[2] && stack->A[2] > stack->A[0])
		sa(stack->A, 1);
	//case 2
	else if (stack->A[0] > stack->A[1] && stack->A[1] > stack->A[2]  && stack->A[0] > stack->A[2])
	{
		sa(stack->A, 1);
		rra(stack->A, size->A, 1);
	}
	//case 3
	else if (stack->A[0] > stack->A[1] && stack->A[1] < stack->A[2] && stack->A[0] > stack->A[2])
		ra(stack->A, 1);
	//case 4
	else if (stack->A[0] < stack->A[1] && stack->A[1] > stack->A[2] && stack->A[0] < stack->A[2])
	{
		sa(stack->A, 1);
		ra(stack->A, 1);
	}
	//case 5
	else if (stack->A[0] < stack->A[1] && stack->A[1] > stack->A[2] && stack->A[0] > stack->A[2])
		rra(stack->A, size->A, 1);
}

void ft_sort_4(t_stack *stack, t_size *size)
{
	small_to_top(stack->A, size->A);
	pb(stack, size);
	ft_sort_3(stack, size);
	pa(stack, size);
}


void ft_small_sort(t_stack *stack, t_size *size)
{
	int i;
	if(size->A == 2)
		sa(stack->A, 1);
	else if(size->A == 3)
		ft_sort_3(stack, size);
	else if(size->A == 4)
		ft_sort_4(stack, size);
	else if (size->A == 5)
	{
		small_to_top(stack->A, size->A);
		pb(stack, size);
		ft_sort_4(stack, size);
		pa(stack, size);
	}
	
}
