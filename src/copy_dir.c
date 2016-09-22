/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyDir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:50:19 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 19:50:23 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			len_array(char **str)
{
	int		x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

void		copy_dir(char **tab, t_stc *stc)
{
	int		i;
	int		j;
	int		bol;

	i = 1;
	j = 0;
	bol = 0;
	stc->dir = (char**)malloc(sizeof(char*) * (len_array(tab) + 1));
	while (tab[i])
	{
		if (((ft_strncmp(tab[i], "-l", 2) != 0) &&
	(ft_strncmp(tab[i], "-R", 2) != 0) && (ft_strncmp(tab[i], "-r", 2) != 0) &&
	(ft_strncmp(tab[i], "-a", 2) != 0) && (ft_strncmp(tab[i], "-t", 2) != 0) &&
	(ft_strncmp(tab[i], "-G", 2) != 0) && (ft_strncmp(tab[i], "-1", 2) != 0) &&
	(ft_strncmp(tab[i], "--", 2) != 0)) || (bol == 1))
			stc->dir[j++] = ft_strdup(tab[i]);
		if (ft_strcmp(tab[i], "--") == 0 || ft_strcmp(tab[i], "-") == 0)
			bol = 1;
		i++;
	}
	stc->dir[j] = NULL;
	stc->count = 0;
	if (!stc->dir[0])
		not_arg(stc);
}
