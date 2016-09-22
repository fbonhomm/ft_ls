/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodeNotL.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:52:01 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 20:22:22 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			mise_a_null(t_tree *node)
{
	node->perm = NULL;
	node->name_root = NULL;
	node->name_group = NULL;
	node->month = NULL;
	node->day = NULL;
	node->hour = NULL;
	node->path_link = NULL;
	node->size = NULL;
	node->lien = NULL;
	node->min = NULL;
	node->maj = NULL;
	node->year = NULL;
}

void			init_var_node(t_tree *node, char *name, char *path, t_stc *stc)
{
	struct stat	st;

	lstat(path, &st);
	node->name = color(stc, name, st.st_mode);
	node->name_bis = ft_strdup(name);
	node->times = st.st_mtime;
	node->type = st.st_mode;
}

void			node_not_l(t_tree *node, t_stc *stc, char *dir, char *name)
{
	char		*path;

	if (name)
	{
		path = ft_path(stc, dir, name);
		if (stc->rc)
			node->dir = ft_strdup(path);
		else
			node->dir = ft_strdup(stc->dir[stc->count]);
		init_var_node(node, name, path, stc);
		path = ft_free(path);
	}
	else
	{
		node->dir = ft_strdup(stc->dir[stc->count]);
		init_var_node(node, stc->dir[stc->count], stc->dir[stc->count], stc);
	}
	mise_a_null(node);
}
