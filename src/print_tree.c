/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printTree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:52:20 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 22:16:34 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*date(char *year, char *hour)
{
	if (!year)
		return (hour);
	else
		return (year);
}

void	print_l(t_tree *tree, t_stc *stc)
{
	space(stc, tree);
	if (tree->path_link)
		print_l_link(tree, stc);
	else if (!tree->size)
		print_l_min_maj(tree, stc);
	else
		print_l_orgin(tree, stc);
	free_space(stc);
}

void	print_tree(t_tree *tree, t_stc *stc)
{
	if (!tree)
		return ;
	if (tree->left)
		print_tree(tree->left, stc);
	if ((!stc->l) && (!stc->a))
	{
		if (tree->name_bis[0] != '.')
			ft_print_str(2, tree->name, "\n");
	}
	if ((stc->l) && (!stc->a))
	{
		if (tree->name_bis[0] != '.')
			print_l(tree, stc);
	}
	if ((!stc->l) && (stc->a))
		ft_print_str(2, tree->name, "\n");
	if ((stc->l) && (stc->a))
		print_l(tree, stc);
	if (tree->right)
		print_tree(tree->right, stc);
}
