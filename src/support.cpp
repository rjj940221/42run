//
// Created by Robert JONES on 2016/11/28.
//

#include "../includes/support.h"

void ft_strdel(char **str)
{
    if (*str)
        free(*str);
    *str = NULL;
}

int		check_file(char *file)
{
    if (access(file, R_OK) == -1)
    {
        printf("The file '%s' cannot be read\n", file);
        return (FALSE);
    }
    return (TRUE);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    int		size;
    char	*re;
    int		i;

    size = strlen(s1) + strlen(s2) + 1;
    if (!(re = (char *)malloc((sizeof(char) * size))))
        return (NULL);
    i = 0;
    while (*s1 && i < size)
        re[i++] = *s1++;
    while (*s2 && i < size)
        re[i++] = *s2++;
    re[i] = '\0';
    return (re);
}