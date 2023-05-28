/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:50:47 by asaadane          #+#    #+#             */
/*   Updated: 2023/05/28 19:36:57 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_count(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		i++;
	}
	return (i);
}

void	ft_check_duplicate(int *stack_a, int size_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_a - 1)
	{
		j = i + 1;
		while (j < size_a)
		{
			if (stack_a[i] == stack_a[j])
			{
				ft_put_error();
			}
			j++;
		}
		i++;
	}
}

bool	ft_check_sorted(int *stack_a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (false);
		i++;
	}
	return (true);
}

int	count_words(char *arg)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == ' ')
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		i++;
	}
	return (count);
}
