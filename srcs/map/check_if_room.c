











#include "../../includes/lem_in.h"

void		check_coordinates(char **tab, t_lemin *l)
{
	int	ret;

	ret = -1;
	if (tab[1][0] && tab[1][0] == '-' && tab[1][1])
		ret = ft_check_if_num(&tab[1][1]);
	else
		ret = ft_check_if_num(tab[1]);
	if (ret != 0)
	{
		ft_free_double_tab((void**)tab);
		free_check_if_room(l,
			"\033[091mError: One or more X coordinates are incorrect\
			\033[0m");
	}
	if (tab[2][0] && tab[2][0] == '-' && tab[2][1])
		ret = ft_check_if_num(&tab[2][1]);
	else
		ret = ft_check_if_num(tab[2]);
	if (ret != 0)
	{
		ft_free_double_tab((void**)tab);
		free_check_if_room(l,
			"\033[091mError: One or more Y coordinates are incorrect\
			\033[0m");
	}
}

static void	check_special_rooms(t_lemin *l)
{
	if (l->flag_start == 1)
	{
		l->room_start = l->room->id;
		l->flag_start = 0;
	}
	if (l->flag_end == 1)
	{
		l->room_end = l->room->id;
		l->flag_end = 0;
	}
}

static void	stock_room_name(t_lemin *l, char **tab)
{
	if (!l->begin)
	{
		l->room = (t_room*)malloc(sizeof(t_room));
		if (!l->room)
			free_check_if_room(l, "\033[091mMalloc error\033[0m");
		l->begin = l->room;
	}
	else
	{
		l->room->next = (t_room*)malloc(sizeof(t_room));
		if (!l->room->next)
			free_check_if_room(l, "\033[091mMalloc error\033[0m");
		l->room = l->room->next;
	}
	l->room->name = ft_strdup(tab[0]);
	l->room->id = l->id;
	l->id++;
	l->room->next = NULL;
	l->room->special = -1;
	check_special_rooms(l);
	l->nb_rooms++;
}

int			check_if_room(char *str, t_lemin *l)
{
	char	**tab;

	tab = NULL;
	check_begin_with_l(str, l);	/* l error */
	check_is_print(str, l);	/* invalid room error */
	tab = ft_strsplit(str, ' ');
	if (tab == NULL || tab[0] == NULL || tab[1] == NULL || tab[2] == NULL)
		free_check_if_room(l,
			"\033[091mError while retrieving a room\033[0m");
	check_coordinates(tab, l);	/* checks neg and if number */
	check_for_hyphen(tab, l);	/* room cant contain a dash */
	check_if_name_already_exists(tab, l);	/* self-explanatory */
	stock_room_name(l, tab);	/* enters data into l->room variables */
	ft_free_double_tab((void**)tab); /* free leaks */
	return (0);
}
