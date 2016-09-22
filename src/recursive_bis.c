/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursiveB.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:52:40 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 22:19:37 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		node(t_tree **tree, t_stc *stc, char *name, char *dir)
{
	if ((name[0] != '.') || (name[0] == '.' && stc->a))
		add_node(tree, stc, dir, name);
	stc->i++;
}

int			condition(t_stc *stc, char *str)
{
	if ((ft_strcmp(str, ".") != 0) && (ft_strcmp(str, "..") != 0) &&
			(ft_strncmp(str, ".", 1) != 0) && !stc->a)
		return (0);
	if ((ft_strcmp(str, ".") != 0) && (ft_strcmp(str, "..") != 0) &&
			(ft_strncmp(str, ".", 1) != 0) && stc->a)
		return (0);
	if ((ft_strcmp(str, ".") != 0) && (ft_strcmp(str, "..") != 0) &&
			(ft_strncmp(str, ".", 1) == 0) && stc->a)
		return (0);
	return (1);
}
