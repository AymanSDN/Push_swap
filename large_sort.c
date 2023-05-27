#include "push_swap.h"


void stack_indexing(int *stack, int size_a)
{
    int i;
	int j;
	int temp;
	int *tmp_stack;
	// for (int i = 0; i < size_a; i++)
	// 	printf("[%d] ", stack[i]);
	// printf("\n---");
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
	// for (int i = 0; i < size_a; i++)
	// 	printf("[%d] ", stack[i]);
	// printf("\n");
	// exit(0);
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

int    get_largest_position(int *stack, int size, int largest)
{
    int i = 0;
    while (i < size)
    {
        if (stack[i] == largest)
            return (i);
        i++;
    }
    return (0);
}

void large_sort(t_stack *stack, t_size *size, int num)
{
	int chunk = (size->A / num) + (size->A % num);
	int scale_chunk = size->A / num;
	int half_chunk = scale_chunk / 2;
	int i = 0;
	int largest = 0;
	int largest_position = 0;
	stack_indexing(stack->A, size->A);
	while (i < chunk)
	{
		if (stack->A[0] <= chunk)
		{
			pb(stack, size);
			if (stack->B[0] > (chunk - half_chunk))
				rb(stack->B, size->B, 1);
			i++;
		}
		else
			ra(stack->A, size->A, 1);
		if (i == chunk && chunk < ((scale_chunk * num) + (size->A % num)))
		{
				chunk += scale_chunk;
		}
	}
	while (size->B)
	{
		largest = get_largest_number(stack->B, size->B);
		largest_position = get_largest_position(stack->B, size->B, largest);
		if (largest_position > size->B / 2)
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
	
}
