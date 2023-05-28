#include "push_swap.h"

int get_smallest(int *stack, int size)
{
	int i = 0;
	
    int smallest = stack[0];
    while (i < size) {
        if (stack[i] < smallest)
		{
            smallest = stack[i];
			return (smallest);
        }
		i++;
    }
    return (0);
}
int get_smallest_position(int *stack, int size)
{
	int i = 0;
	
    int smallest = stack[0];
    while (i < size) {
        if (stack[i] < smallest)
		{
            smallest = stack[i];
			return (i);
        }
		i++;
    }
    return (0);
}

void small_to_top(int *stack, int size)
{
	int smallest = get_smallest(stack, size);
	int position = get_smallest_position(stack, size);

	while(position)
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