/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notRecursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:52:14 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 22:02:37 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				loop_suite(t_stc *stc, t_tree **tree, DIR *rep,
						struct dirent *fichier)
{
	int				bol;
	struct stat		st;

	stc->i = 0;
	bol = lstat(stc->dir[stc->count], &st);
	rep = opendir(stc->dir[stc->count]);
	init_len(stc);
	if ((rep && S_ISDIR(st.st_mode) && !S_ISLNK(st.st_mode)) ||
	(rep && S_ISLNK(st.st_mode) && !stc->l))
	{
		while ((fichier = readdir(rep)))
			node(tree, stc, fichier->d_name, stc->dir[stc->count]);
		closedir(rep);
		if (tree[0])
			display(tree, stc, tree[0]->dir, stc->i);
		else
			display(tree, stc, stc->dir[stc->count], stc->i);
		stc->len++;
	}
	else if ((bol == 0 && !S_ISDIR(st.st_mode)) ||
			(bol == 0 && S_ISLNK(st.st_mode)))
		file(stc, tree);
	else
		error(stc->dir[stc->count], stc);
	stc->count++;
}

void				not_recursive(t_stc *stc)
{
	t_tree			**tree;
	struct dirent	*fichier;
	DIR				*rep;

	rep = NULL;
	fichier = NULL;
	while (stc->dir[stc->count])
	{
		tree = (t_tree**)malloc(sizeof(t_tree));
		tree[0] = NULL;
		loop_suite(stc, tree, rep, fichier);
		if (tree[0])
			free_tree(tree);
		free(tree);
	}
}
