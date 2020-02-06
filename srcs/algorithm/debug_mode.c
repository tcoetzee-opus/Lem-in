/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <tcoetzee@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:51:43 by tcoetzee          #+#    #+#             */
/*   Updated: 2020/02/05 17:15:26 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	print_debug(t_lemin *l)
{
	print_resume(l);
	print_equivalence_tab(l);
	ft_print_tab_pipes(l);
	print_possible_paths(l);
	resolve(l);
	print_result(l);
	ft_putendl("\033[94m---------- Result ----------\n\033[0m");
}
