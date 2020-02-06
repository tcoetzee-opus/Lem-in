











#include "../../includes/lem_in.h"

static bool	**ft_create_tab_bool(unsigned long x, unsigned long y)
{
	bool	**tab;
	int		i;
	int		j;

	tab = NULL;
	i = 0;
	j = 0;
	tab = (bool **)malloc(sizeof(bool *) * (y + 1));
	if (tab == NULL)
		return (NULL);
	while ((unsigned long)i < y)
	{
		tab[i] = (bool *)malloc(sizeof(bool) * x);
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

void		map_init_tab_pipes(t_lemin *l)
{
	l->pipes = ft_create_tab_bool((unsigned long)l->nb_rooms,
			(unsigned long)l->nb_rooms);
	if (l->pipes == NULL)
	{
		ft_free_double_tab((void**)l->eq);
		free_check_if_room(l,
				"\033[091mError during memory allocation\033[0m");
	}
	l->room = l->begin;
	l->pipes[l->nb_rooms] = NULL;
}

void		stock_pipes(char *str, t_lemin *l)
{
	char	**tab;

	tab = NULL;
	tab = ft_strsplit(str, '-');
	if (tab == NULL || tab[0] == NULL || tab[1] == NULL)
	{
		free_pipes(l,
				"\033[091mError: Poorly formatted pipes\033[0m");
	}
	if (ft_strcmp(tab[0], tab[1]) == 0)
	{
		ft_free_double_tab((void**)tab);
		free_pipes(l, "\033[091mError: A room is connected to itself\
				\033[0m");
	}
	if (ft_nb_occur_char_in_str(str, "-") > 1)
	{
		ft_free_double_tab((void**)tab);
		free_pipes(l,
				"\033[091mError: One or more pipes are badly formatted\
				\033[0m");
	}
	check_if_rooms_exists(l, tab);
	ft_free_double_tab((void**)tab);
	l->nb_pipes++;
}

int			map_pipes_and_stock(t_lemin *l)
{
	int	i;

	i = l->start;
	map_init_tab_pipes(l);
	while (l->f[i] != NULL)
	{
		if (ft_strcmp(l->f[i], "##start") == 0)
			free_pipes(l, "\033[091mError: Invalid starting room\033[0m");
		else if (ft_strcmp(l->f[i], "##end") == 0)
			free_pipes(l, "\033[091mError: Invalid end room\033[0m");
		else if (l->f[i][0] && l->f[i][0] == '#' &&							/* if theres a comment or nothing or comment */
				(!l->f[i][1] || (l->f[i][1] && l->f[i][1] != '#')))
			i++;
		else if (l->f[i][0] && l->f[i][0] == '#' &&
				l->f[i][1] && l->f[i][1] == '#')
			i++;
		else if (ft_nb_occur_char_in_str(l->f[i], " ") == 2 &&
				l->f[i][0] && l->f[i][0] != '#')
			free_pipes(l, "\033[091mError: Badly formatted map\033[0m");
		else if (l->f[i][0] && l->f[i][0] != '#' && ft_strstr(l->f[i], "-"))
			stock_pipes(l->f[i++], l);
		else
			return (1);
	}
	return (0);
}
