/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:50:47 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 20:06:01 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			file(t_stc *stc, t_tree **tree)
{
	struct stat	st;
	int			bol;

	bol = lstat(stc->dir[stc->count], &st);
	while ((stc->dir[stc->count] && S_ISLNK(st.st_mode) && bol == 0) ||
			(stc->dir[stc->count] && S_ISREG(st.st_mode) && bol == 0))
	{
		add_node(tree, stc, stc->dir[stc->count], NULL);
		stc->count++;
		bol = lstat(stc->dir[stc->count], &st);
	}
	display(tree, stc, stc->dir[stc->count], 0);
	stc->len++;
	stc->count--;
}
