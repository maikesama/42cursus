
#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t n)
{
	t_byte *ptr;

	ptr = b;
	while (n)
	{
		*ptr = (t_byte)c;
		ptr++;
		n--;
	}
	return (b);
}

char	*ft_memmove(char *dst, char *src, int len)
{
	const t_byte	*s;
	t_byte			*d;
	t_byte			*revd;
	const t_byte	*revs;

	s = src;
	revs = s + (len - 1);
	d = dst;
	revd = d + (len - 1);
	if (s < d)
	{
		while (len--)
		{
			*revd-- = *revs--;
		}
		return (dst);
	}
	while (len)
	{
		*d = *s;
		d++;
		s++;
		len--;
	}
	return (dst);
}

char	*freestrjoin(char **s1, char *s2)
{
	char	*ptr;
	unsigned int i;
	unsigned int n;

	i = 0;
	while (*(*s1 + i))
		i++;
	n = i;
	while (*(s2 + i - n))
		i++;
	if(!(ptr = ft_calloc(i + 1, sizeof(*ptr))))
		return (0);
	i = 0;
	n = 0;
	while (*(*s1 + i))
	{
		ptr[i] = *(*s1 + i);
		i++;
	}
	while (*(s2 + n))
		ptr[i++] = (*(s2 + n++));
	free(*s1);
	*s1 = ptr;
	return (1);
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr;

	if (!size)
	{
		ptr = malloc(size);
		return (ptr);
	}
	if (!(ptr = malloc(size * count)))
		return (0);
	ft_memset(ptr, '\0', size * count);
	return (ptr);
}
