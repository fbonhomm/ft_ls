/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addNode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:49:21 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 20:12:18 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		len_padding(t_tree *node, t_stc *stc)
{
	if (ft_strlen(node->lien) > (size_t)stc->len_lien)
		stc->len_lien = ft_strlen(node->lien);
	if (ft_strlen(node->name_root) > (size_t)stc->len_root)
		stc->len_root = ft_strlen(node->name_root);
	if (ft_strlen(node->name_group) > (size_t)stc->len_group)
		stc->len_group = ft_strlen(node->name_group);
	if (ft_strlen(node->day) > (size_t)stc->len_day)
		stc->len_day = ft_strlen(node->day);
	if (node->size)
	{
		if (ft_strlen(node->size) > (size_t)stc->len_size)
			stc->len_size = ft_strlen(node->size);
	}
	else
	{
		if (ft_strlen(node->min) > (size_t)stc->len_min)
			stc->len_min = ft_strlen(node->min);
		if (ft_strlen(node->maj) > (size_t)stc->len_maj)
			stc->len_maj = ft_strlen(node->maj);
	}
}

t_tree		*init_node(t_stc *stc, char *dir, char *name)
{
	t_tree	*node;

	node = (t_tree*)malloc(sizeof(t_tree));
	if (stc->l)
		node_opt_l(node, stc, dir, name);
	else
		node_not_l(node, stc, dir, name);
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int			valid_sort(t_stc *stc, t_tree *tmp, t_tree *node)
{
	if ((!stc->r) && (!stc->t) &&
			(ft_sort_str(node->name_bis, tmp->name_bis)) == 1)
		return (1);
	if ((stc->r) && (!stc->t) &&
			(ft_sort_str(node->name_bis, tmp->name_bis)) == 2)
		return (1);
	if (((!stc->r) && (stc->t) &&
	((sort_time(node->times, tmp->times)) == 2)) ||
		((!stc->r) && (stc->t) && ((sort_time(node->times, tmp->times)) == 0)
			&& (ft_sort_str(node->name_bis, tmp->name_bis)) == 1))
		return (1);
	if (((stc->r) && (stc->t) &&
	((sort_time(node->times, tmp->times)) == 1)) ||
		((stc->r) && (stc->t) && ((sort_time(node->times, tmp->times)) == 0)
			&& (ft_sort_str(node->name_bis, tmp->name_bis)) == 2))
		return (1);
	return (0);
}

void		loop_node(t_tree *node, t_tree **tmp, t_stc *stc)
{
	t_tree	*tmp_node;

	tmp_node = *tmp;
	if ((valid_sort(stc, *tmp, node)) == 1)
	{
		*tmp = (*tmp)->right;
		if (!*tmp)
			tmp_node->right = node;
	}
	else
	{
		*tmp = (*tmp)->left;
		if (!*tmp)
			tmp_node->left = node;
	}
}

void		add_node(t_tree **tree, t_stc *stc, char *dir, char *name)
{
	t_tree	*node;
	t_tree	*tmp;

	tmp = *tree;
	node = init_node(stc, dir, name);
	if (tmp)
	{
		while (tmp)
			loop_node(node, &tmp, stc);
	}
	else
		*tree = node;
}
