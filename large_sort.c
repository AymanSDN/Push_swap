#include "push_swap.h"

int *copy_stack(int *stack_a, int size_a)
{
	int i;
	int *temp;
	
	i = 0;

	temp = malloc(sizeof(int) * size_a);
	if (!temp)
	{
		free(temp);
		exit(1);
	}
	while (i < size_a)
	{
		temp[i] = stack_a[i];
		i++;
	}
	return(temp);
}

// int get_smallest(t_stack *stack, t_size *size)
// {
// 	int i;
// 	int smallest;

// 	i = 0;
// 	smallest = stack->B[0];
// 	while (i < size->B)
// 	{
// 		if (smallest > stack->B[i])
// 		{
// 			smallest = stack->B[i];
// 		}
// 		i++;
// 	}
// 	return (smallest);
// }
 int get_position(t_stack *stack, t_size *size, int top)
{
	int i = 0;

	while (i < size->A)
	{
		if (stack->Temp[i] == top)
			break;
		i++;
	}
	return i;
}


void sort_stack(int *stack, int size_a)
{
    int i;
	int j;
	int temp;
	int *tem;
	tem = malloc(sizeof(int)* size_a);
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
		tem[i] = temp;
        i++;
    }
	i = -1;
    while (++i < size_a)
		stack[i] = tem[i];
	free(tem);
}

// int chanks(t_stack *stack, t_size *size , int range, int mid_range, int count)
// {
// 	//int position;
// 	//position = get_position(stack, size, stack->A[0]);
// 	if (stack[i] <= stack->Temp[range])
// 	{
// 		if (position <= stack->Temp[range - mid_range])
// 		{
// 			pb(stack, size);
// 			count++;
// 		}
// 		else
// 		{
// 			pb(stack, size);
// 			rb(stack->B, size->B, 1);
// 			count++;
// 		}
// 	}
// 	else
// 	{
// 		ra(stack->A, size->A, 1);
// 	}
// 	// printf("%d\n", position);
// 	return (count);
// }

void large_sort(t_stack *stack, t_size *size, int num)
{
	int		i;
	int		count = 0;
	static int		range;
	int		mid_range;
	int		size_range;
	
	i = 0;
	range = (size->A / num) + (size->A % num);
	size_range = (size->A / num);
	mid_range = size_range / 2;
	sort_stack(stack->A, size->A);
	while (size->A)
	{
		if (stack->A[0] <= stack->A[range])
		{
			if (stack->A[0] <= stack->A[range - mid_range])
			{
				pb(stack, size);
				count++;
		for (int i = 0; i < size->B; i++)
			printf("\n%i\n",stack->B[i]);
		//exit(0);
		sleep(2);
		
			}
			else
			{
				pb(stack, size);
				rb(stack->B, size->B, 1);
				count++;
			}
		}
		if(count == range && range <= size->A)
			range+=mid_range;
		else
		{
			ra(stack->A, size->A, 1);
		}
	}
	free(stack->Temp);
}
	
// while (size->B > 0)
// 	{
// 		biggest = get_biggest(stack, size);
// 		position = get_biggest_position(stack, size, biggest);

// 		if (position > size->B / 2)
// 		{
// 			while (biggest != stack->B[0])
// 			{
// 				rrb(stack->B, size->B, 1);
// 			}
// 		}
// 		else
// 		{
// 			while (biggest != stack->B[0])
// 			{
// 				rb(stack->B, size->B, 1);
// 			}
// 		}
// 		pa(stack, size);
// 	}