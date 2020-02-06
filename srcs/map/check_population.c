











#include "../../includes/lem_in.h"

static void	case_ants_number_negative(t_lemin *l)
{
	if (l->nb_ants <= 0)
	{
		ft_free_double_tab((void**)l->f);
		ft_memdel((void**)&l->string_file);
		print_error(ft_putendl_fd,
			"\033[091mError: Please enter the correct number of ants\
			\033[0m", STDERR_FILENO, l);
	}
}

void		map_ants_number(t_lemin *l)
{
	while (l->f[l->start] && l->f[l->start][0] == '#')	/* If theres a comment increment */
		l->start++;
	if (ft_check_if_num(l->f[l->start]) == 1)	/* Check if it is a number */
	{
		ft_free_double_tab((void**)l->f);
		ft_memdel((void**)&l->string_file);
		print_error(ft_putendl_fd,
			"\033[091mError: Please enter the correct number of ants\
			\033[0m", STDERR_FILENO, l);
	}
	else if (ft_strlen(l->f[l->start]) > 10)	/* Gave to many ants for the anthill to handle */
	{
		ft_free_double_tab((void**)l->f);
		ft_memdel((void**)&l->string_file);
		print_error(ft_putendl_fd,
		"\033[091mError: There are too many ants in the anthill\
		\033[0m", STDERR_FILENO, l);
	}
	else
		l->nb_ants = ft_atoi(l->f[l->start]);
	case_ants_number_negative(l);	/* Stops when number negative / which means when int is too big aswell */
	l->start++;
}
