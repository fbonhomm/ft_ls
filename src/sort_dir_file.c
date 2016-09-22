/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortDirFile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:53:02 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 20:24:22 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			switch_loop(t_stc *stc, int i)
{
	char		*tmp;

	tmp = ft_strdup(stc->dir[i]);
	stc->dir[i] = ft_free(stc->dir[i]);
	stc->dir[i] = ft_strdup(stc->dir[i + 1]);
	stc->dir[i + 1] = ft_free(stc->dir[i + 1]);
	stc->dir[i + 1] = ft_strdup(tmp);
	tmp = ft_free(tmp);
	stc->bol = 1;
}

void			sort_dir_file(t_stc *stc)
{
	struct stat	st;
	struct stat	st1;
	int			i;

	i = 0;
	stc->bol = 0;
	while (stc->dir[i + 1])
	{
		stat(stc->dir[i], &st);
		stat(stc->dir[i + 1], &st1);
		if (S_ISDIR(st.st_mode) && S_ISREG(st1.st_mode))
			switch_loop(stc, i);
		i++;
		if ((!stc->dir[i + 1]) && stc->bol == 1)
		{
			i = 0;
			stc->bol = 0;
		}
	}
}
