/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:32:39 by asaadane          #+#    #+#             */
/*   Updated: 2023/05/28 20:54:26 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_empty_arg(char **splited)
{
	int		count;

	count = 0;
	while (splited[count])
	{
		count++;
	}
	if (count == 0)
		ft_put_error();
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (str1 == str2)
		return (0);
	while (i < n - 1 && str1 && str2 && str1[i] == str2[i])
	{
		i++;
		if (!str1[i] || !str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

void	ft_put_error(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

int	ft_atoi_tool(char *str)
{
	int	result;
	int	negative;

	result = 0;
	negative = 1;
	if (!str || !*str)
		ft_put_error();
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		negative *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str)
		ft_put_error();
	return (result * negative);
}

int	ft_atoi(char *str)
{
	long int	result;

	result = ft_atoi_tool(str);
	if (INT_MIN <= result && result <= INT_MAX)
		return (result);
	else
		ft_put_error();
	return (0);
}
