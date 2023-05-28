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

int get_second_largest_number(int *stack, int size)
{
    int largest = stack[0];
    int second_largest = INT_MIN;
    int i = 1;

    while (i < size)
    {
        if (stack[i] > largest)
        {
            second_largest = largest;
            largest = stack[i];
        }
        else if (stack[i] > second_largest && stack[i] < largest)
        {
            second_largest = stack[i];
        }
        i++;
    }
    return second_largest;
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

int    get_largest_position(int *stack, int size, int number)
{
    int i = 0;
    while (i < size)
    {
        if (stack[i] == number)
            return (i);
        i++;
    }
    return (0);
}

void a_to_b(t_stack *stack, t_size *size, int num)
{
	int chunk = (size->A / num) + (size->A % num);
	int scale_chunk = size->A / num;
	int half_chunk = scale_chunk / 2;
	int i = 0;
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

}


void b_to_a(t_stack *stack, t_size *size)
{
	int largest = 0;
	int largest_position = 0;
	while (size->B)
	{
		largest = get_largest_number(stack->B, size->B);
		largest_position = get_largest_position(stack->B, size->B, largest);
		if (largest_position >= size->B / 2)
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

void large_sort(t_stack *stack, t_size *size, int num)
{

	stack_indexing(stack->A, size->A);
	a_to_b(stack, size, num);
	b_to_a(stack, size);
}
