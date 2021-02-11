#include <fcntl.h> //TEST open
#include <stdio.h> //TEST print
#include <stdlib.h>
#include <unistd.h>

int		get_next_line(int fd, char **line);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *str, size_t n);
void	*ft_memmove(void *dst, void *src, int len);
char	*freestrjoin(char **s1, char *s2);
int		ft_strlen(const char *str);