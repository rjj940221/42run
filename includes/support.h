//
// Created by Robert JONES on 2016/11/28.
//

#ifndef INC_42RUN_SUPPORT_H
#define INC_42RUN_SUPPORT_H

# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <wchar.h>
# include <stdarg.h>
# include <inttypes.h>
# include <stdlib.h>
# include <stdio.h>


void ft_strdel(char **str);
int		check_file(char *file);
char	*ft_strjoin(char const *s1, char const *s2);


#endif //INC_42RUN_SUPPORT_H
