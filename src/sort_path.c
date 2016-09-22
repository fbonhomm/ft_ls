/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortPath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:53:08 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 20:37:01 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				path_crois(char **path, int j, int *bol)
{
	char			*tmp;

	if (((ft_sort_str(path[j], path[j + 1])) == 1))
	{
		tmp = ft_strdup(path[j]);
		path[j] = ft_free(path[j]);
		path[j] = ft_strdup(path[j + 1]);
		path[j + 1] = ft_free(path[j + 1]);
		path[j + 1] = ft_strdup(tmp);
		tmp = ft_free(tmp);
		*bol = 1;
	}
}

void				path_reverse(char **path, int j, int *bol)
{
	char			*tmp;

	if (((ft_sort_str(path[j], path[j + 1])) == 2))
	{
		tmp = ft_strdup(path[j]);
		path[j] = ft_free(path[j]);
		path[j] = ft_strdup(path[j + 1]);
		path[j + 1] = ft_free(path[j + 1]);
		path[j + 1] = ft_strdup(tmp);
		tmp = ft_free(tmp);
		*bol = 1;
	}
}

void				path_crois_time(char **path, unsigned long *times, int j,
		int *bol)
{
	char			*tmp;
	unsigned long	tmpi;

	if (times[j] < times[j + 1])
	{
		tmp = ft_strdup(path[j]);
		path[j] = ft_free(path[j]);
		path[j] = ft_strdup(path[j + 1]);
		path[j + 1] = ft_free(path[j + 1]);
		path[j + 1] = ft_strdup(tmp);
		tmp = ft_free(tmp);
		tmpi = times[j];
		times[j] = times[j + 1];
		times[j + 1] = tmpi;
		*bol = 1;
	}
}

void				path_reverse_time(char **path, unsigned long *times, int j,
		int *bol)
{
	char			*tmp;
	unsigned long	tmpi;

	if (times[j] > times[j + 1])
	{
		tmp = ft_strdup(path[j]);
		path[j] = ft_free(path[j]);
		path[j] = ft_strdup(path[j + 1]);
		path[j + 1] = ft_free(path[j + 1]);
		path[j + 1] = ft_strdup(tmp);
		tmp = ft_free(tmp);
		tmpi = times[j];
		times[j] = times[j + 1];
		times[j + 1] = tmpi;
		*bol = 1;
	}
}

void				sort_path(char **path, unsigned long *times, t_stc *stc)
{
	int				j;
	int				bol;

	j = 0;
	bol = 0;
	while (path[j + 1])
	{
		if ((!stc->r) && (!stc->t))
			path_crois(path, j, &bol);
		else if ((stc->r) && (!stc->t))
			path_reverse(path, j, &bol);
		else if ((!stc->r) && (stc->t))
			path_crois_time(path, times, j, &bol);
		else if ((stc->r) && (stc->t))
			path_reverse_time(path, times, j, &bol);
		j++;
		if ((!path[j + 1]) && bol == 1)
		{
			j = 0;
			bol = 0;
		}
	}
}
