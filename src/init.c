/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:51:05 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 19:51:08 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_var(t_stc *stc)
{
	stc->count = 0;
	stc->index = 0;
	stc->total = 0;
	stc->not_arg = 0;
	stc->l = 0;
	stc->rc = 0;
	stc->a = 0;
	stc->r = 0;
	stc->t = 0;
	stc->g = 0;
}

void	init_len(t_stc *stc)
{
	stc->len_lien = 0;
	stc->len_root = 0;
	stc->len_group = 0;
	stc->len_size = 0;
	stc->len_day = 0;
	stc->len_min = 0;
	stc->len_maj = 0;
}

void	loop_arg(t_stc *stc)
{
	if (stc->arg[stc->count] == 'l')
		stc->l = 1;
	if (stc->arg[stc->count] == 'R')
		stc->rc = 1;
	if (stc->arg[stc->count] == 'a')
		stc->a = 1;
	if (stc->arg[stc->count] == 'r')
		stc->r = 1;
	if (stc->arg[stc->count] == 't')
		stc->t = 1;
	if (stc->arg[stc->count] == 'G')
		stc->g = 1;
	stc->count++;
}

char	*color(t_stc *stc, char *str, unsigned int mode)
{
	if ((stc->g) && (S_ISDIR(mode)) && (mode == 33279))
		return (str_color_folder_all_right(str));
	else if ((stc->g) && (S_ISDIR(mode)))
		return (str_color_folder(str));
	else if ((stc->g) && (S_ISLNK(mode)))
		return (str_color_link(str));
	else if ((stc->g))
		return (str_color_file(str));
	else
		return (ft_strdup(str));
}

char	*ft_path(t_stc *stc, char *dir, char *str)
{
	if (stc->rc)
		return (join_path(dir, str));
	else
		return (join_path(stc->dir[stc->count], str));
}
