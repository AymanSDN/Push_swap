#include "push_swap.h"

void ss(int *stack_a, int *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	write(1, "ss\n", 3);
}

void rr(t_stack *stack, t_size *size)
{
	ra(stack->A, size->A, 0);
	rb(stack->B, size->B, 0);
	write(1, "rr\n", 3);
}

void rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	rra(stack_a, size_a, 0);
	rrb(stack_b, size_b, 0);
	write(1, "rrr\n", 4);
}