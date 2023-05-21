#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

void ft_check_integers(char **splited)
{
    char *arg;
    int i = 0;
    int j = 0;

    while (splited[i] != NULL)
    {
        arg = splited[i];
        if (arg != NULL)
        {
            if (arg[j] == '-' || arg[j] == '+')
            {
                j++;
            }
            while (arg[j] != '\0')
            {
                if (isdigit(arg[j]))
                {
                    j++;
                }
                else
                {
                    fprintf(stderr, "Error: Invalid integer\n");
                    return;
                }
            }
        }
        else
        {
            fprintf(stderr, "Error: Null pointer encountered\n");
            return;
        }
        i++;
    }
}

int main()
{
    char *strings[] = {"123", "-456", "789"};
    ft_check_integers(strings);
    return 0;
}
