/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatDir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:50:55 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 19:50:57 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		count_dir(t_stc *stc)
{
	stc->count_dir = 0;
	while (stc->dir[stc->count_dir])
		stc->count_dir++;
	stc->count = 0;
	stc->len = 0;
}

char		*join_path(char *paths, char *name)
{
	int		i;

	i = 0;
	while (paths[i])
		i++;
	i--;
	if (paths[i] != '/')
		return (ft_strjoin_mult(3, paths, "/", name));
	else
		return (ft_strjoin(paths, name));
}

char		*read_link(char *path)
{
	char	*buf;

	buf = (char*)malloc(sizeof(char) * 1024);
	ft_bzero(buf, 1023);
	readlink(path, buf, 1023);
	return (buf);
}

char		*name(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[i])
		i++;
	i--;
	while ((str[i] != '/') && (i >= 0))
		i--;
	if (i != 0)
		i++;
	while (str[i])
	{
		tmp[j] = str[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}
