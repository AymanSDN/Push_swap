#include "push_swap.h"

void pb(t_stack *stack, t_size *size)
{
	int i;
	int position_b;

	if(!size->A)
		exit(1);
	i = 0;
	position_b = size->B;
	while (position_b >= 0)
	{
		stack->B[position_b + 1] = stack->B[position_b];
		position_b--;
	}
	size->B++;
	stack->B[0] = stack->A[0];
	while(i < size->A)
	{
		stack->A[i] = stack->A[i + 1];
		i++;
	}
	size->A--;
	write(1, "pb\n", 3);
}

void sb(int *stack_b, int p)
{
	int temp;

	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	if (p == 1)
		write(1, "sb\n", 3);
}

void rb(int *stack_b, int size_b, int p)
{
	int i;
	int temp;

	i = 0;
	temp = stack_b[0];
	while (i < size_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i - 1] = temp;
	if (p == 1)
		write(1, "rb\n", 3);
}

void rrb(int *stack_b, int size_b, int p)
{
	int	i;
	int	temp;

	i = size_b - 1;
	temp = stack_b[i];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = temp;
	if (p == 1)
		write(1, "rrb\n", 4);
}