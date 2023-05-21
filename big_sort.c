/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:22:14 by asaadane          #+#    #+#             */
/*   Updated: 2023/05/21 00:38:55 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_100(t_stack *stack, t_size *size)
{
    while (size->A > 1)
    {
        small_to_top(stack->A, size->B);
        pb(stack, size);
    }
    while (size->B == 0)
    {
        pa(stack, size);
    }
}


// void copy_stack(t_stack stack, int *temp, t_size size)
// {
//     int i = 0;
//     while(i < size.A)
//     {
//         temp[i] = stack.A[i];
//         printf("%d", temp[i]);
//         i++;
//     }
// }

// t_list *create_new_node(int data, int position)
// {
//     t_list *new;

//     new = (t_list *)malloc(sizeof(t_list));
//     if(!new)
//         exit(1);
//     new->data = data;
//     new->position = position;
//     new->next = NULL;
//     return(new);
// }
// // void lstadd_front(t_list **list, t_list *new)
// // {
// //     new->next = *list;
// //     *list = new;
    
// // }

// void comare_ints()
// void set_position(t_stack stack, t_size size)
// {
//     int i = 0;
//     int j = 0;
//     t_list *list;
//     while (i < size.A)
//     {
//         if (!list)
//             create_new_node(stack.A[i], 0);
//         else
        
//             lst_add_back(list, create_new_node(stack.A[i], 0));
//         i++;
//     }
//     while(j <= i)
//     (
        
//     )
// }