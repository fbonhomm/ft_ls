/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeTree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:51:00 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 21:54:43 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		free_stc(t_stc *stc)
{
	stc->dir = ft_free_array(stc->dir);
	stc->arg = ft_free(stc->arg);
	if (stc->t)
		free(stc->times);
}

void		free_var(t_tree *tmp)
{
	tmp->hour = ft_free(tmp->hour);
	tmp->day = ft_free(tmp->day);
	tmp->month = ft_free(tmp->month);
	tmp->name_root = ft_free(tmp->name_root);
	tmp->name_group = ft_free(tmp->name_group);
	tmp->perm = ft_free(tmp->perm);
	tmp->name = ft_free(tmp->name);
	tmp->name_bis = ft_free(tmp->name_bis);
	tmp->dir = ft_free(tmp->dir);
	tmp->path_link = ft_free(tmp->path_link);
	tmp->size = ft_free(tmp->size);
	tmp->lien = ft_free(tmp->lien);
	tmp->min = ft_free(tmp->min);
	tmp->maj = ft_free(tmp->maj);
	tmp->year = ft_free(tmp->year);
}

void		free_tree(t_tree **tree)
{
	t_tree	*tmp;

	tmp = *tree;
	if (!tree)
		return ;
	if (tmp->left)
	{
		free_var(tmp);
		free_tree(&tmp->left);
	}
	if (tmp->right)
	{
		free_var(tmp);
		free_tree(&tmp->right);
	}
	free_var(tmp);
	free(tmp);
	*tree = NULL;
}
