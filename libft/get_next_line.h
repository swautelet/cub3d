#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# if BUFFER_SIZE < -1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE -1
# endif
# if BUFFER_SIZE > 1947483646
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1947483646
# endif

char	*get_next_line(int fd);
char	*ft_straddback(char *result, char *buffer, ssize_t size);
size_t	ft_strlengnl(char *str);
int		ft_end_of_line(char *str);
char	*ft_initialize(char *buffer);
char	*ft_first(void);
char	*ft_eof(char *result);
void	ft_delbuffer(char *buffer, int l);

#endif