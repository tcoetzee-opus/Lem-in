











#include "includes/libft.h"

void	ft_print_tab_bool(bool **tab, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < x)
	{
		while (j < x)
		{
			ft_putnbr(tab[i][j++]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
