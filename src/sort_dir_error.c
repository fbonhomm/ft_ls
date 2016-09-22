/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortDirError.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:52:57 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 21:48:00 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			sort_dir_error(t_stc *stc)
{
	int			i;

	i = 0;
	stc->bol = 0;
	while (stc->dir[i + 1])
	{
		if ((opendir(stc->dir[i]) && !opendir(stc->dir[i + 1])) ||
			(!opendir(stc->dir[i]) && errno == ENOTDIR &&
				!opendir(stc->dir[i + 1]) && errno != ENOTDIR))
			switch_loop(stc, i);
		i++;
		if ((!stc->dir[i + 1]) && stc->bol == 1)
		{
			i = 0;
			stc->bol = 0;
		}
	}
}
