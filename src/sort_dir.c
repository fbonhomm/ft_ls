/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortDir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:52:51 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 19:52:55 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ordre_crois(t_stc *stc, char *tmp, int j)
{
	if (((ft_sort_str(stc->dir[j], stc->dir[j + 1])) == 1))
	{
		tmp = ft_strdup(stc->dir[j]);
		stc->dir[j] = ft_free(stc->dir[j]);
		stc->dir[j] = ft_strdup(stc->dir[j + 1]);
		stc->dir[j + 1] = ft_free(stc->dir[j + 1]);
		stc->dir[j + 1] = ft_strdup(tmp);
		tmp = ft_free(tmp);
		stc->bol = 1;
	}
}

void				ordre_reverse(t_stc *stc, char *tmp, int j)
{
	if (((ft_sort_str(stc->dir[j], stc->dir[j + 1])) == 2))
	{
		tmp = ft_strdup(stc->dir[j]);
		stc->dir[j] = ft_free(stc->dir[j]);
		stc->dir[j] = ft_strdup(stc->dir[j + 1]);
		stc->dir[j + 1] = ft_free(stc->dir[j + 1]);
		stc->dir[j + 1] = ft_strdup(tmp);
		tmp = ft_free(tmp);
		stc->bol = 1;
	}
}

void				ordre_crois_time(t_stc *stc, char *tmp,
						unsigned long tmpi, int j)
{
	if (stc->times[j] < stc->times[j + 1])
	{
		tmp = ft_strdup(stc->dir[j]);
		stc->dir[j] = ft_free(stc->dir[j]);
		stc->dir[j] = ft_strdup(stc->dir[j + 1]);
		stc->dir[j + 1] = ft_free(stc->dir[j + 1]);
		stc->dir[j + 1] = ft_strdup(tmp);
		tmp = ft_free(tmp);
		tmpi = stc->times[j];
		stc->times[j] = stc->times[j + 1];
		stc->times[j + 1] = tmpi;
		stc->bol = 1;
	}
}

void				ordre_reverse_time(t_stc *stc, char *tmp,
						unsigned long tmpi, int j)
{
	if (stc->times[j] > stc->times[j + 1])
	{
		tmp = ft_strdup(stc->dir[j]);
		stc->dir[j] = ft_free(stc->dir[j]);
		stc->dir[j] = ft_strdup(stc->dir[j + 1]);
		stc->dir[j + 1] = ft_free(stc->dir[j + 1]);
		stc->dir[j + 1] = ft_strdup(tmp);
		tmp = ft_free(tmp);
		tmpi = stc->times[j];
		stc->times[j] = stc->times[j + 1];
		stc->times[j + 1] = tmpi;
		stc->bol = 1;
	}
}

void				sort_dir(t_stc *stc)
{
	int				j;
	char			*tmp;
	unsigned long	tmpi;

	j = 0;
	stc->bol = 0;
	tmp = NULL;
	tmpi = 0;
	while (stc->dir[j + 1])
	{
		if ((!stc->r) && (!stc->t))
			ordre_crois(stc, tmp, j);
		else if ((stc->r) && (!stc->t))
			ordre_reverse(stc, tmp, j);
		else if ((!stc->r) && (stc->t))
			ordre_crois_time(stc, tmp, tmpi, j);
		else if ((stc->r) && (stc->t))
			ordre_reverse_time(stc, tmp, tmpi, j);
		j++;
		if ((!stc->dir[j + 1]) && stc->bol == 1)
		{
			j = 0;
			stc->bol = 0;
		}
	}
}
