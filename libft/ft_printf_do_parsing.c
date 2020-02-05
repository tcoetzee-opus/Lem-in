











#include "includes/libft.h"

int	do_map_flag(char *str, t_f **cr, int i)
{
	int		j;

	j = 0;
	if (is_flag(&str[i]))
	{
		while (is_flag(&str[i + j]))
			j++;
		(*cr)->flag = ft_strnew((size_t)j);
		j = 0;
		while (is_flag(&str[i]))
			(*cr)->flag[j++] = str[i++];
		return (j);
	}
	else
		(*cr)->flag = NULL;
	return (0);
}

int	do_map_width(char *str, t_f **cr, int i)
{
	int		j;

	j = 0;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i + j]))
			j++;
		(*cr)->width = ft_strnew((size_t)j);
		j = 0;
		while (ft_isdigit(str[i]))
			(*cr)->width[j++] = str[i++];
		return (j);
	}
	else
		(*cr)->width = NULL;
	return (0);
}

int	do_map_precision(char *str, t_f **cr, int i, int j)
{
	if (str[i] == '.')
	{
		i++;
		if (is_type(&str[i]))
		{
			(*cr)->precision = ft_strnew(1);
			(*cr)->precision[0] = '.';
			return (1);
		}
		else if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i + j]))
				j++;
			(*cr)->precision = ft_strnew((size_t)j);
			j = 0;
			while (ft_isdigit(str[i]))
				(*cr)->precision[j++] = str[i++];
			return (j + 1);
		}
	}
	else
		(*cr)->precision = NULL;
	return (0);
}

int	do_map_modifier(char *str, t_f **cr, int i)
{
	int		j;

	j = 0;
	if (is_modifier(&str[i]))
	{
		while (is_modifier(&str[i + j]))
			j++;
		(*cr)->modifier = ft_strnew((size_t)j);
		j = 0;
		while (is_modifier(&str[i]))
			(*cr)->modifier[j++] = str[i++];
		return (j);
	}
	else
		(*cr)->modifier = NULL;
	return (0);
}

int	do_map_type(char *str, t_f **cr, int i)
{
	(*cr)->type = ft_strnew(1);
	(*cr)->type[0] = str[i];
	return (1);
}
