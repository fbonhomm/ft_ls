/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printTreeL.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:52:27 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/03 00:01:15 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_display(int nb, ...)
{
	char	*str;
	char	statiq[1024];
	va_list ap;
	int		i;
	int		x;
	int		j;

	va_start(ap, nb);
	i = 0;
	x = 0;
	ft_bzero(statiq, 1024);
	while (i < nb)
	{
		j = 0;
		str = va_arg(ap, char*);
		while (str[j])
			statiq[x++] = str[j++];
		i++;
	}
	ft_putstr(statiq);
	va_end(ap);
}

void		print_l_link(t_tree *tree, t_stc *stc)
{

	print_display(19, tree->perm, stc->space_lien, tree->lien, " ",
		tree->name_root, stc->space_root, tree->name_group, stc->space_group,
			stc->space_maj, stc->space_min, stc->space_size, tree->size, " ",
				tree->month, stc->space_day, tree->day, " ",
					date(tree->year, tree->hour), " ");
	ft_print_str(4, tree->name, " -> ", tree->path_link, "\n");
}

void		print_l_min_maj(t_tree *tree, t_stc *stc)
{
	print_display(20, tree->perm, stc->space_lien, tree->lien, " ",
		tree->name_root, stc->space_root, tree->name_group, stc->space_group,
			stc->space_maj, tree->maj, ",", stc->space_min, tree->min, " ",
				tree->month, stc->space_day, tree->day, " ",
					date(tree->year, tree->hour), " ");
	ft_print_str(2, tree->name, "\n");
}

void		print_l_orgin(t_tree *tree, t_stc *stc)
{
	print_display(19, tree->perm, stc->space_lien, tree->lien, " ",
		tree->name_root, stc->space_root, tree->name_group, stc->space_group,
			stc->space_maj, stc->space_min, stc->space_size, tree->size, " ",
				tree->month, stc->space_day, tree->day, " ",
					date(tree->year, tree->hour), " ");
	ft_print_str(2, tree->name, "\n");
}
