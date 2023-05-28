#include "push_swap.h"

void pa(t_stack *stack, t_size *size)
{
	int i;
	int position_a;

	if(!size->B)
		exit(1);
	i = 0;
	position_a = size->A;
	while (position_a >= 0)
	{
		stack->A[position_a + 1] = stack->A[position_a];
		position_a--;
	} 
	size->A++;
	stack->A[0] = stack->B[0];
	while(i < size->B)
	{
		stack->B[i] = stack->B[i + 1];
		i++;
	}
	size->B--;
	write(1, "pa\n", 3);
}

void sa(int *stack_a, int p)
{
	int temp;

	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	if (p == 1)
		write(1, "sa\n", 3);
}

void ra(int *stack_a, int size_a, int p)
{
	int i;
	int temp;

	i = 0;
	temp = stack_a[0];
	while (i < size_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i - 1] = temp;
	if (p == 1)
		write(1, "ra\n", 3);
}


void rra(int *stack_a, int size_a, int p)
{
	int	i;
	int	temp;

	i = size_a - 1;
	temp = stack_a[i];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = temp;
	if (p == 1)
		write(1, "rra\n", 4);
}


// void pb(t_stack *stack, t_size *size)
// {
// 	int i;
// 	int position_b;

// 	if(!size->A)
// 		exit(1);
// 	i = 0;
// 	position_b = size->B;
// 	while (position_b >= 0)
// 	{
// 		stack->B[position_b + 1] = stack->B[position_b];
// 		position_b--;
// 	}
// 	size->B++;
// 	stack->B[0] = stack->A[0];
// 	while(i < size->A)
// 	{
// 		stack->A[i] = stack->A[i + 1];
// 		i++;
// 	}
// 	size->A--;
// 	write(1, "pb\n", 3);
// }

