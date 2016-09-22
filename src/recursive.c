/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:52:34 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 19:52:38 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				loop_loop_recur(t_tree *tree, t_stc *stc, char *dir)
{
	char			*tmp;

	tmp = NULL;
	if (!tree)
		return ;
	if (tree->left)
		loop_loop_recur(tree->left, stc, dir);
	if ((S_ISDIR(tree->type)) && (!S_ISLNK(tree->type)))
	{
		if ((condition(stc, tree->name_bis)) == 0)
		{
			tmp = join_path(dir, tree->name_bis);
			suite_with_r(stc, tmp);
		}
	}
	if (tree->right)
		loop_loop_recur(tree->right, stc, dir);
	tmp = ft_free(tmp);
}

void				loop_recur(DIR *rep, t_tree **tree, t_stc *stc, char *dir)
{
	struct dirent	*fichier;

	stc->i = 0;
	while ((fichier = readdir(rep)))
		node(tree, stc, fichier->d_name, dir);
	closedir(rep);
	display(tree, stc, dir, stc->i);
	stc->len++;
	if ((stc->i != 2 && tree[0]) || stc->a)
	{
		loop_loop_recur(*tree, stc, dir);
		free_tree(tree);
	}
}

void				suite_with_r(t_stc *stc, char *dir)
{
	t_tree			**tree;
	DIR				*rep;
	struct stat		st;
	int				bol;

	rep = NULL;
	bol = lstat(stc->dir[stc->count], &st);
	tree = (t_tree**)malloc(sizeof(t_tree));
	tree[0] = NULL;
	init_len(stc);
	rep = opendir(dir);
	if ((rep && S_ISDIR(st.st_mode) && !S_ISLNK(st.st_mode)) ||
			(rep && S_ISLNK(st.st_mode) && !stc->l))
		loop_recur(rep, tree, stc, dir);
	else if ((bol == 0 && !S_ISDIR(st.st_mode)) ||
			(bol == 0 && S_ISLNK(st.st_mode)))
		file(stc, tree);
	else
		error(dir, stc);
	free(tree);
}
