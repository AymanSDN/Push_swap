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


void sort_stack(int *stack, int size_a, int num)
{
    int i;
	int j;
	int temp;
	i = 1;
    while (i < num)
    {
        j = 1;
        while (j < size_a - i)
        {
            if (stack[j] > stack[j + 1])
            {
                temp = stack[j];
                stack[j] = stack[j + 1];
                stack[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

int chanks(t_stack *stack, t_size *size , int range, int mid_range, int count)
{
	int position;
	position = get_position(stack, size, stack->A[0]);
	
	printf("%d\n", position);exit(0);
	if (position <= stack->Temp[range])
	{
		puts("here2");
		if (position <= stack->Temp[range - mid_range])
		{
			pb(stack, size);
			count++;
		}
		else
		{
			pb(stack, size);
			rb(stack->B, size->B, 1);
			count++;
		}
	}
	else
	{
		puts("here2");
		ra(stack->A, size->A, 1);
	}
	return (count);
}

void large_sort(t_stack *stack, t_size *size, int num)
{
	int		i;
	static int		range;
	int		mid_range;
	int		size_range;
	int tmp;
	
	i = 0;
	range = (size->A / num) + (size->A % num);
	size_range = (size->A / num);
	mid_range = size_range / 2;
	tmp = size->A;
	stack->Temp = copy_stack(stack->A, size->A);
	size->A = tmp;
	printf("Before sorting: ");
	for(int i = 1; i <size->A; i++){printf("%d ", stack->A[i]);};
	sort_stack(stack->A, size->A, num);
	printf("\nAfter sorting: ");
	for(int i = 1; i <size->A; i++){printf("%d ", stack->A[i]);};
	
	while (size->A)
	{
		i = chanks(stack, size, range, mid_range, i);

		if (i >= range)
		{
			stack->Temp = copy_stack(stack->A, size->A);
			sort_stack(stack->Temp, size->A, num);
			range += size_range;
			i = 0;
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