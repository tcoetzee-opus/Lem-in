











#include "../../includes/lem_in.h"
/* 	FUNCTION			| DESC						| FILE				|
	init_ants 			  Initializing ant struct	  map/init.c
	handle_arguments 	  Handles flags				  map/init.c
	read_map			  Extracts Info from file	  map/map.c
	remove_useless_paths  
	*/
int	main(int argc, char **argv)
{
	t_lemin	l;

	init_ants(&l);						//
	handle_arguments(argc, argv, &l);	//
	read_map(&l);						//
	remove_useless_paths(&l);
	if (l.debug == 1)
		print_debug(&l);
	else
		resolve(&l);
	ft_putendl(l.string_file);
	create_ant_result(&l);
	get_ants(&l);
	free_at_end(&l);
	free_result(&l);
	return (0);
}
