#include "push_swap.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int ft_count_stack(int *stack)
{
	int i = 0;
	while(stack[i])
	{
		i++;
	}
	return(i);
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == src)
		return (dst);
	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}

char	*ft_strdup( char *s)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s) + 1;
	ptr = malloc(sizeof(char) * len);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, len);
	return (ptr);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *str;
	size_t i;
	size_t j;
	size_t len1;
	size_t len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len1)
	{
		str[j++] = s1[i++];
	}
	i = 0;
	while (i < len2)
	{
		str[j++] = s2[i++];
	}
	str[j] = '\0';
	return (str);
}


char	*ft_substr(char *s, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

static void	*ft_free(int j, char **p)
{
	while (j > 0)
	{
		free(p[j]);
		j--;
	}
	free(p);
	return (NULL);
}

static	int	word_len(char *str, char c, int i)
{
	int	j;

	j = 0;
	while (str[i] != c && str[i])
	{
		j++;
		i++;
	}
	return (j);
}

static	size_t	word_counter(char const *str, char ch)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ch)
			i++;
		if (str[i])
			counter++;
		while (str[i] != ch && str[i])
			i++;
	}
	return (counter);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		wc;
	char	**split;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	wc = word_counter((char *)s, c);
	split = (char **)malloc((wc + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (j < wc && s[i])
	{
		while (s[i] == c && s[i])
				i++;
		split[j] = ft_substr((char *)s, i, word_len((char *)s, c, i));
		if (!split[j])
			return (ft_free(j, split));
		j++;
		i = i + word_len((char *)s, c, i);
	}
		split[j] = NULL;
	return (split);
}

int	ft_atoi(char *str)
{
	long int	result;
	int	negative;

	result = 0;
	negative = 1;
	if (!*str)
			{
		write(2, "must be only integers\n", 23);
		exit(1);
	}	
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		negative *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if (*str)
	{
		write(2, "must be only integers\n", 23);
		exit(1);
	}	
	result = result * negative;
	if (INT_MIN <= result && result <= INT_MAX)
	{
		return(result);
	}
	else
	{
		write(2, "Error1\n", 6);
		exit(1);
	}
}

