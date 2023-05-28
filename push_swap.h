/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:32:10 by asaadane          #+#    #+#             */
/*   Updated: 2023/05/28 19:42:44 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>
# include <stdbool.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
}t_stack;

typedef struct s_size
{
	int	a;
	int	b;
}t_size;

typedef struct s_spl
{
	int		spl_idx;
	int		w_srt;
	int		w_len;
	char	*arg;
}t_spl;

void	pa(t_stack *stack, t_size *size);
void	sa(int *stack_a, int p);
void	ra(int *stack_a, int size_a, int p);
void	rra(int *stack_a, int size_a, int p);
void	pb(t_stack *stack, t_size *size);
void	sb(int *stack_b, int p);
void	rb(int *stack_b, int size_b, int p);
void	rrb(int *stack_b, int size_b, int p);
void	ss(int *stack_a, int *stack_b);
void	rr(t_stack *stack, t_size *size);
void	rrr(int *stack_a, int *stack_b, int size_a, int size_b);
int		ft_isdigit(int c);
int		ft_count(char **splited);
void	ft_check_duplicate(int *stack_a, int size_a);
bool	ft_check_sorted(int *stack_a, int size_a);
int		count_words(char *arg);
void	count_argv(char **av, int *size_a);
char	**split_arguments(int ac, char **av, int *size_a);
void	free_arguments(char **splited, int size_a);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_count_stack(int *stack);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup( char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, size_t start, size_t len);
char	**ft_split(const char *s, char c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_atoi(char *str);
int		get_smallest(int *stack, int size);
int		get_largest(int *stack, int size);
int		get_number_position(int *stack, int size, int number);
void	small_to_top(int *stack, int size);
void	ft_sort_3(t_stack *stack, t_size *size);
void	ft_sort_4(t_stack *stack, t_size *size);
void	ft_small_sort(t_stack *stack, t_size *size);
void	stack_indexing(int *stack, int size_a);
void	a_to_b(t_stack *stack, t_size *size, int num);
void	b_to_a(t_stack *stack, t_size *size);
void	large_sort(t_stack *stack, t_size *size, int num);
void	load_stacks(t_stack *stack, t_size *size, char **splited);
void	ft_free_all(t_stack *stack, t_size *size, char **splited);
void	sorting(t_stack *stack, t_size *size, char **splited);
void	ft_put_error(void);

#endif