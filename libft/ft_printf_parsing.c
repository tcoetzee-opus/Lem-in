











#include "includes/libft.h"

static int	do_map2(char *str, t_f **cr, int i)
{
	int	j;

	j = 0;
	i++;
	i = i + (do_map_flag(str, &(*cr), i));
	i = i + (do_map_width(str, &(*cr), i));
	i = i + (do_map_precision(str, &(*cr), i, j));
	i = i + (do_map_modifier(str, &(*cr), i));
	i = i + (do_map_type(str, &(*cr), i));
	return (i);
}

void		do_map(char *str, int nb_arg, t_f **cr, va_list ap)
{
	int		i;
	t_f		*begin;

	i = 0;
	*cr = malloc(sizeof(t_f));
	begin = *cr;
	while (nb_arg > 0)
	{
		if (str[i] != '%')
			i++;
		if (str[i] == '%')
		{
			i = do_map2(str, cr, i);
			recup_argument(cr);
			put_result(cr, ap);
			if (nb_arg > 1)
			{
				(*cr)->next = malloc(sizeof(t_f));
				*cr = (*cr)->next;
			}
			nb_arg--;
		}
	}
	(*cr)->next = NULL;
	(*cr) = begin;
}
