#include "push_swap.h"


void stack_indexing(int *stack, int size_a)
{
    int i;
	int j;
	int temp;
	int *tmp_stack;
	tmp_stack = malloc(sizeof(int)* size_a);
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

int get_largest_number(int *stack, int size)
{
	int i;
    int largest = stack[0];
	i = 1;
    while (i < size)
	{
        if (stack[i] > largest)
		{
            largest = stack[i];
        }
		i++;
    }

    return largest;
}

void large_sort(t_stack *stack, t_size *size, int num)
{
	int		i;
	int		count = 0;
	static int		range;
	int		mid_range;
	int		size_range;
	int largest;
	
	i = 0;
	range = (size->A / num) + (size->A % num);
	size_range = (size->A / num);
	mid_range = size_range / 2;
	stack_indexing(stack->A, size->A);
	for(int i = 0; i < 100; i++)
	{
		printf("stack A: %d | stack B %d\n", stack->A[i], stack->B[i]);
	}
	while (size->A)
	{
		if (stack->A[0] <= stack->A[range])
		{
			if (stack->A[0] <= stack->A[range - mid_range])
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
			ra(stack->A, size->A, 1);
		}
		if(count == size_range && range <= size->A)
		{
			range+=mid_range;
			count = 0;
		}
	}
	for(int i = 0; i < 100; i++)
	{
		printf("stack A: %d | stack B %d\n", stack->A[i], stack->B[i]);
	}
	while (size->B -1)
	{
		largest = get_largest_number(stack->B, size->B);

		if (largest > size->B / 2)
		{
			while (largest != stack->B[0])
			{
				rrb(stack->B, size->B, 1);
			}
		}
		else
		{
			while (largest != stack->B[0])
			{
				rb(stack->B, size->B, 1);
			}
		}
		pa(stack, size);
	}
	for(int i = 0; i < 100; i++)
	{
		printf("stack A: %d | stack B %d\n", stack->A[i], stack->B[i]);
	}
	exit(0);
}
	
