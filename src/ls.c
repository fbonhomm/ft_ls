/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:51:44 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 19:51:48 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	not_arg(t_stc *stc)
{
	stc->dir = (char**)malloc(sizeof(char*) * 2);
	stc->dir[0] = ft_strdup(".");
	stc->dir[1] = NULL;
	stc->count = 0;
}

int		nbr_arg(t_stc *stc)
{
	int	i;

	i = 0;
	while (stc->dir[i])
		i++;
	return (i);
}

void	ls(t_stc *stc, char **av)
{
	init_var(stc);
	stc->arg = copy_opt(av, stc);
	copy_dir(av, stc);
	while (stc->arg[stc->count])
		loop_arg(stc);
	if (stc->t)
		init_time_s(stc, av);
	sort_dir(stc);
	sort_dir_error(stc);
	sort_dir_file(stc);
	count_dir(stc);
	if (!stc->rc)
		not_recursive(stc);
	else
	{
		while (stc->dir[stc->count])
		{
			suite_with_r(stc, stc->dir[stc->count]);
			stc->count++;
		}
	}
	free_stc(stc);
}
