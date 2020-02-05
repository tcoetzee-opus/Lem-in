











#include "includes/libft.h"

char	*ft_getwstring(wchar_t *str)
{
	size_t		j;
	char		*result;
	char		*temp;
	char		*temp2;

	result = NULL;
	j = 0;
	temp2 = NULL;
	while (str[j] != '\0')
	{
		temp2 = ft_getwchar(str[j]);
		temp = ft_strdup(temp2);
		free(temp2);
		if (result == NULL)
			result = ft_strdup(temp);
		else
		{
			temp2 = result;
			result = ft_strjoin(result, temp);
			free(temp2);
		}
		j++;
		free(temp);
	}
	return (result);
}
