#include "push_swap.h"


int	ft_isdigit(int c)
{
	if(c >= '0' && c <= '9')
	{
		return (1);
	}
	return(0);
}

int ft_count(char **splited)
{
	int i;

	i = 0;
	while (splited[i])
	{
		i++;
	}
	return(i);	
}

void ft_check_duplicate(int *stack_a, int size_a)
{
	int i;
	int j;

	i = 0;
	while (i < size_a -1) {
		j =  i + 1;
		while (j < size_a) {
			if (stack_a[i] == stack_a[j])
			{
				printf("n1 = %d | n2 = %d\n", stack_a[i], stack_a[j]);
				write(2, "duplicate found !!\n", 20);
                exit(1);
			}
			j++;
		}
		i++;
	}
}

bool ft_check_sorted(int *stack_a, int size_a)
{
	int i;

	i = 0;
	while (i < size_a - 1)
	{
        if (stack_a[i] > stack_a[i + 1])
            return false;
		i++;
    }
    return true;
}


int count_words(char *arg)
{
    
    int count = 0;
    int in_word = 0;
    
    int i = 0;

    while (arg[i] != '\0')
    {
        if (arg[i] == '\0')
        {
            write(2, "Error4\n", 7);
            exit(1);
        }
        else if (arg[i] == ' ')
        {
            in_word = 0;
        }
        else if (!in_word) {
            count++;
            in_word = 1;
        }
        i++;
    }
    return count;
}
void count_argv(char **av, int *size_a)
{
    int i = 1;
    while(av[i] != NULL)
    {
        *size_a += count_words(av[i]);
        i++;
    }
}

char **split_arguments(char **av, int *size_a)
{
    char **splited;
    int spl_index = 0;
    char *arg;
    size_t i;
    size_t j;
    splited = (char **)malloc(sizeof(char *) * (*size_a + 1));
    if (!splited)
        exit(1);
    i = 1;
    while (av[i] != NULL)
    {
        arg = av[i];
        int word_start = 0;
        j = 0;
        while (j <= strlen(arg))
        {
            if (arg[j] == ' ' || arg[j] == '\0')
            {
                int word_len = j - word_start;
                if (word_len > 0)
                {
                    splited[spl_index] = (char *)malloc(sizeof(char) * (word_len + 1));
                    if (!splited[spl_index])
                    {
                        free(splited[spl_index]);
                        exit(1);
                    }
                    strncpy(splited[spl_index], arg + word_start, word_len);
                    splited[spl_index][word_len] = '\0';
                    spl_index++;
                }
                word_start = j + 1;
            }
            j++;
        }
        i++;
    }
    return splited;
}

void free_arguments(char **splited, int size_a)
{
    int i = 0;
    while (i < size_a)
    {
        free(splited[i]);
        i++;
    }
    free(splited);
}





