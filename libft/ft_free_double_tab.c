











#include "includes/libft.h"

void	ft_free_double_tab(void **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
}
