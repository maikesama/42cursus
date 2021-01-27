
#include "libft.h"

int		ft_counter_rows(char const *s, char c)
{
	int		accumulator;

	accumulator = 0;
	while (*s)
	{
		if (*s == c)
			accumulator++;
		s++;
	}
	return (accumulator);
}

int		ft_counter_rowslen(char const *s, char c)
{
	int		i;

	i = 0;
	while (ft_srcchar_bonus(s, c))
	{
		i++;
	}	
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;

	





}