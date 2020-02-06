











#include "../../includes/lem_in.h"



static void	free_all(t_lemin *l)
{
	ft_memdel((void**)&l->string_file);
	ft_free_double_tab((void**)l->f);
	ft_free_double_tab((void**)l->eq);
	ft_free_double_tab((void**)l->pipes);
	free_lst_name(l);
	print_error(&ft_putendl_fd,
			"\033[091mError during memory allocation\033[0m",
			STDERR_FILENO, l);
}

void		update_sum_tab(t_lemin *l)
{
	int	total;
	int	i;
	int	j;

	total = 0;
	i = 0;
	j = 0;
	while (i < l->nb_rooms)
	{
		while (j < l->nb_rooms)
			total += l->pipes[i][j++];	/* Amount of pipes */
		l->sum[i] = total;
		total = 0;
		j = 0;
		i++;
	}
}

void		create_sum_tab(t_lemin *l)
{
	l->sum = (int *)malloc(sizeof(int) * (unsigned int)(l->nb_rooms));	/* Allocating amount of rooms */	
	if (l->sum == NULL)
		free_all(l);
	else 
		update_sum_tab(l);	
												/* Free struct if NULL */
}

void		check_for_isolated_rooms(t_lemin *l)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < l->nb_rooms)
	{
		if (i != l->room_start && i != l->room_end && l->sum[i] == 1)
		{
			while (j < l->nb_rooms)
			{
				if (l->pipes[i][j] == 1)
				{
					l->pipes[i][j] = 0;
					l->pipes[j][i] = 0;
					l->sum[i]--;
					l->sum[j]--;
					check_for_isolated_rooms(l);
				}
				j++;
			}
		}
		j = 0;
		i++;
	}
}
