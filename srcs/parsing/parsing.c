











#include "../../includes/lem_in.h"

static void	make_tab_equivalence(t_lemin *l)
{
	l->eq = (char **)malloc(sizeof(char*) * (unsigned long)(l->nb_rooms + 1));
	if (l->eq == NULL)
		free_check_if_room(l,
				"\033[091mError during memory allocation\033[0m");
	l->room = l->begin;
	while (l->room != NULL)
	{
		l->eq[l->room->id] = ft_strdup(l->room->name);
		l->room = l->room->next;
	}
	l->room = l->begin;
	l->eq[l->nb_rooms] = NULL;
}

void		read_map(t_lemin *l)
{
	handle_file(l);
	map_ants_number(l);
	if (map_room_and_stock(l) == 2)
		free_check_if_room(l,
				"\033[091mError: The map is badly formatted\033[0m");
	make_tab_equivalence(l);
	map_pipes_and_stock(l);
	check_end_and_start(l);
}
