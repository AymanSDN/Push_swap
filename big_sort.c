#include "push_swap.h"


int *copy_stack(int *stack_a, int size_a) {
    int i;
    int *temp;
    
    i = 0;
    temp = malloc(sizeof(int) * size_a);
    while (i < size_a) {
        temp[i] = stack_a[i];
        i++;
    }
    return temp;
}

int get_biggest(t_stack *stack, t_size *size) {
    int i;
    int biggest;
    
    i = 0;
    biggest = stack->B[0];
    while (i < size->B) {
        if (biggest < stack->B[i]) {
            biggest = stack->B[i];
        }
        i++;
    }
    return biggest;
}

int get_biggest_position(t_stack *stack, t_size *size, int biggest) {
    int i = 0;
    
    while (i < size->B) {
        if (stack->B[i] == biggest)
            break;
        
        i++;
    }
    return i;
}

void sort_stack(int *stack, int num) {
    int i, j, temp;
    
    for (i = 0; i < num - 1; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (stack[j] > stack[j + 1]) {
                // Swap elements
                temp = stack[j];
                stack[j] = stack[j + 1];
                stack[j + 1] = temp;
            }
        }
    }
}

int chunks(t_stack *stack, t_size *size, int x1, int x2, int count) {
    if (stack->A[0] <= stack->Temp[x2]) {
        pb(stack, size);
        if (size->B >= 2)
            rb(stack->B, 1);
        count++;
    }
    if (stack->A[0] <= stack->Temp[x1]) {
        pb(stack, size);
        count++;
    } else {
        ra(stack->A, 1);
    }
    return count;
}

void large_sort(t_stack *stack, t_size *size, int num) {
    int i, x1, x2, biggest, position;
    
    i = 0;
    
    x1 = (size->A / num) + (size->A % num);
    x2 = x1 / 2;
    stack->Temp = copy_stack(stack->A, size->A);
    sort_stack(stack->Temp, size->A);
    while (size->A > 0) {
        i = chunks(stack, size, x1, x2, i);
        if (i >= x1) {
            stack->Temp = copy_stack(stack->A, size->A);
            sort_stack(stack->Temp, num);
            x1 = size->A / num;
            x2 = x1 / 2;
            i = 0;
        }
    }
    while (size->B > 0) {
        biggest = get_biggest(stack, size);
        position = get_biggest_position(stack, size, biggest);
        
        if (position > size->B / 2) {
            while (biggest != stack->B[0]) {
                rrb(stack->B, size->B, 1);
            }
        } else {
            while (biggest != stack->B[0]) {
                rb(stack->B, 1);
            }
        }
        pa(stack, size);
    }
}



// #include "push_swap.h"

// int *copy_stack(int *stack_a, int size_a)
// {
// 	int i;
// 	int *temp;
	
// 	i = 0;
// 	temp = malloc(sizeof(int) * size_a);
// 	while (stack_a[i])
// 	{
// 		temp[i] = stack_a[i];
// 		i++;
// 	}
// 	return(temp);
// }

// int get_biggest(t_stack *stack, t_size *size)
// {
// 	int i;
// 	int biggest;

// 	i = 0;
// 	biggest = stack->B[0];
// 	while (i < size->B)
// 	{
// 		if (biggest < stack->B[i])
// 		{
// 			biggest = stack->B[i];
// 		}
// 		i++;
// 	}
// 	return (biggest);
// }
//  int get_biggest_position(t_stack *stack, t_size *size, int biggest)
// {
// 	int i = 0;

// 	while (i < size->B)
// 	{
// 		if (stack->B[i] == biggest)
// 			break;

// 		i++;
// 	}
// 		return i;
// }


// void sort_stack(int *stack, int num)
// {
// 	int i;
// 	int temp;

// 	i = 0;
// 	while (i < num - 1)
// 	{
// 		int j = 0;
// 		while (j < num - i - 1)
// 		{
// 			if (stack[j] > stack[j + 1])
// 			{
// 				// Swap elements
// 				temp = stack[j];
// 				stack[j] = stack[j + 1];
// 				stack[j + 1] = temp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
// int chanks(t_stack *stack, t_size *size , int x1, int x2, int count)
// {
	
// 	if (stack->A[0] <= stack->Temp[x2])
// 	{
// 		pb(stack, size);
// 		if (size->B >= 2)
// 			rb(stack->B, 1);
// 		count++;
// 	}
// 	if (stack->A[0] <= stack->Temp[x1])
// 	{
// 		pb(stack, size);
// 		count++;
// 	}
// 	else
// 	{
// 		ra(stack->A, 1);
// 	}
// 	return (count);
// }

// void large_sort(t_stack *stack, t_size *size, int num)
// {
// 	int		i;
// 	int		x1;
// 	int		x2;
// 	int biggest;
// 	int position;
	
// 	i = 0;

// 	x1 = ((size->A / num) + (size->A % num));
// 	x2 = x1 / 2;
// 	stack->Temp = copy_stack(stack->A, size->A);
// 	sort_stack(stack->Temp, size->A);
// 	while (size->A)
// 	{
// 		i = chanks(stack, size, x1, x2, i);
// 		if (i >= x1)
// 		{
// 			stack->Temp = copy_stack(stack->A, size->A);
// 			sort_stack(stack->Temp, num);
// 			x1 = (size->A / num) ; 
// 			x2 = x1 / 2;
// 			i = 0;
// 		}
// 	}
// 	while (size->B > 0)
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
// 				rb(stack->B, 1);
// 			}
// 		}
// 		pa(stack, size);
// 	}
// }
