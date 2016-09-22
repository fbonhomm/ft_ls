/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodeOptL.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:52:08 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 20:29:02 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				uid_gid(t_tree *node, struct stat st, struct passwd *pass,
		struct group *gr)
{
	if (pass)
		node->name_root = ft_strdup(pass->pw_name);
	else
		node->name_root = ft_itoa(st.st_uid);
	if (gr)
		node->name_group = ft_strdup(gr->gr_name);
	else
		node->name_group = ft_itoa(st.st_gid);
}

void				mode_file(t_tree *n, struct stat st, dev_t dev, off_t len)
{
	n->min = NULL;
	n->maj = NULL;
	n->size = NULL;
	if (S_ISCHR(st.st_mode) || S_ISBLK(st.st_mode))
	{
		n->min = ft_itoa(minor(dev));
		n->maj = ft_itoa(major(dev));
	}
	else
		n->size = ft_itoa((int)len);
}

void				init_var_node_l(struct stat st, t_tree *node, t_stc *stc)
{
	struct passwd	*pass;
	struct group	*gr;

	pass = getpwuid(st.st_uid);
	gr = getgrgid(st.st_gid);
	node->lien = ft_itoa((int)st.st_nlink);
	uid_gid(node, st, pass, gr);
	mode_file(node, st, st.st_rdev, st.st_size);
	node->times = st.st_mtime;
	node->type = st.st_mode;
	stc->total += st.st_blocks;
	init_time(node, st);
	len_padding(node, stc);
}

void				init_var_node_l_bis(t_tree *node, t_stc *stc, char *name,
		char *path)
{
	struct stat		st;

	lstat(path, &st);
	node->name = color(stc, name, st.st_mode);
	node->name_bis = ft_strdup(name);
	node->perm = init_perm(st, path);
	if (S_ISLNK(st.st_mode))
		node->path_link = read_link(path);
	else
		node->path_link = NULL;
	init_var_node_l(st, node, stc);
}

void				node_opt_l(t_tree *node, t_stc *stc, char *dir, char *name)
{
	char			*path;

	if (name)
	{
		path = ft_path(stc, dir, name);
		if (stc->rc)
			node->dir = ft_strdup(path);
		else
			node->dir = ft_strdup(stc->dir[stc->count]);
		init_var_node_l_bis(node, stc, name, path);
		path = ft_free(path);
	}
	else
	{
		node->dir = ft_strdup(stc->dir[stc->count]);
		init_var_node_l_bis(node, stc, stc->dir[stc->count],
				stc->dir[stc->count]);
	}
}
