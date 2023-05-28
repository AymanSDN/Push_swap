/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:03:49 by asaadane          #+#    #+#             */
/*   Updated: 2023/05/28 21:16:01 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_argv(char **av, int *size_a)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		*size_a += count_words(av[i]);
		i++;
	}
}

void	free_arguments(char **splited, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

void	splited_elements(char **splited, t_spl *var)
{
	if (var->w_len > 0)
	{
		splited[var->spl_idx] = (char *)malloc(sizeof(char) * (var->w_len + 1));
		if (!splited[var->spl_idx])
		{
			free(splited[var->spl_idx]);
			exit(1);
		}
		ft_strncpy(splited[var->spl_idx], var->arg + var->w_srt, var->w_len);
		splited[var->spl_idx][var->w_len] = '\0';
		var->spl_idx++;
	}
}

void	spl_arg(char **av, char **splited)
{
	size_t		i;
	size_t		j;
	t_spl		*var;

	i = 0;
	var = malloc(sizeof(t_spl));
	var->spl_idx = 0;
	while (av[++i] != NULL)
	{
		var->arg = av[i];
		var->w_srt = 0;
		j = 0;
		while (j <= ft_strlen(var->arg))
		{
			if (var->arg[j] == ' ' || var->arg[j] == '\0')
			{
				var->w_len = j - var->w_srt;
				splited_elements(splited, var);
				var->w_srt = j + 1;
			}
			j++;
		}
	}
	free(var);
}

char	**split_arguments(int ac, char **av, int *size_a)
{
	char	**splited;
	int		i;

	i = 0;
	splited = (char **)malloc(sizeof(char *) * (*size_a + 1));
	if (!splited)
		exit(1);
	while (i < ac)
	{
		if (ft_strncmp(av[i], "", 1) == 0)
		{
			ft_put_error();
		}
		i++;
	}
	spl_arg(av, splited);
	return (splited);
}
