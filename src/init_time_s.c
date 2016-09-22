/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initTimeS.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:51:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 20:41:41 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			init_time_s(t_stc *stc, char **tab)
{
	struct stat	st;
	int			i;

	i = len_array(tab);
	stc->times = (unsigned long*)malloc(sizeof(unsigned long) * (i + 2));
	i = 0;
	while (stc->dir[i])
	{
		stat(stc->dir[i], &st);
		stc->times[i++] = st.st_mtime;
	}
}
