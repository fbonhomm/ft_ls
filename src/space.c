/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:53:31 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 21:06:43 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		init_space(t_stc *stc)
{
	stc->space_lien = (char*)malloc(sizeof(char) * (stc->len_lien + 1));
	stc->space_root = (char*)malloc(sizeof(char) * (stc->len_root + 1));
	stc->space_group = (char*)malloc(sizeof(char) * (stc->len_group + 1));
	stc->space_day = (char*)malloc(sizeof(char) * (stc->len_day + 1));
	stc->space_size = (char*)malloc(sizeof(char) * (stc->len_size + 1));
	stc->space_min = (char*)malloc(sizeof(char) * (stc->len_min + 1));
	stc->space_maj = (char*)malloc(sizeof(char) * (stc->len_maj + 1));
}

void		free_space(t_stc *stc)
{
	stc->space_lien = ft_free(stc->space_lien);
	stc->space_root = ft_free(stc->space_root);
	stc->space_group = ft_free(stc->space_group);
	stc->space_size = ft_free(stc->space_size);
	stc->space_day = ft_free(stc->space_day);
	stc->space_min = ft_free(stc->space_min);
	stc->space_maj = ft_free(stc->space_maj);
}

void		convert_space(char *space, int len, char *var, int ret)
{
	int		i;
	int		count;

	count = ((len + ret) - ft_strlen(var));
	i = 0;
	while (i <= count)
		space[i++] = ' ';
	space[i] = '\0';
}

void		min_maj(t_stc *stc)
{
	int		i;
	int		count;

	i = 0;
	count = stc->len_min;
	while (i < count)
		stc->space_min[i++] = ' ';
	stc->space_min[i] = '\0';
	i = 0;
	count = stc->len_maj;
	while (i <= count)
		stc->space_maj[i++] = ' ';
	stc->space_maj[i] = '\0';
}

void		space(t_stc *stc, t_tree *tree)
{
	init_space(stc);
	if (ft_strlen(tree->perm) == 11)
		convert_space(stc->space_lien, stc->len_lien, tree->lien, 0);
	else
		convert_space(stc->space_lien, stc->len_lien, tree->lien, 1);
	convert_space(stc->space_root, stc->len_root, tree->name_root, 1);
	convert_space(stc->space_group, stc->len_group, tree->name_group, 0);
	if (stc->len_day == 1)
		convert_space(stc->space_day, stc->len_day, tree->day, 1);
	else
		convert_space(stc->space_day, stc->len_day, tree->day, 0);
	if (tree->size)
		convert_space(stc->space_size, stc->len_size, tree->size, 0);
	if ((tree->size && stc->len_min != 0) || (tree->size && stc->len_maj != 0))
		min_maj(stc);
	if (!tree->size)
	{
		convert_space(stc->space_min, stc->len_min, tree->min, 0);
		convert_space(stc->space_maj, stc->len_maj, tree->maj, 0);
	}
}
