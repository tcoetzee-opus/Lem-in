











#include "includes/libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int result;

	if (!s1 || !s2)
		return (0);
	result = ft_strcmp(s1, s2);
	if (result == 0)
		return (1);
	else
		return (0);
}
