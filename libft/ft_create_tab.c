











#include "includes/libft.h"

int		**ft_create_tab(unsigned long x, unsigned long y)
{
	int		**tab;
	int		i;
	int		j;

	tab = NULL;
	i = 0;
	j = 0;
	tab = (int **)malloc(sizeof(int *) * (y + 1));
	if (tab == NULL)
		return (NULL);
	while ((unsigned long)i < y)
	{
		tab[i] = (int *)malloc(sizeof(int) * x);
		if (tab[i] == NULL)
		{
			ft_free_double_tab((void**)tab);
			return (NULL);
		}
		while ((unsigned long)j < x)
			tab[i][j++] = '\0';
		j = 0;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
