/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initTime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:51:17 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 21:38:04 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			six_month(time_t present, time_t file)
{
	if ((file > (present - 15778476)) && (file < (present + 15778476)))
		return (0);
	return (1);
}

void		init_time(t_tree *node, struct stat st)
{
	char	*str;
	char	**tab;
	time_t	present;

	present = time(NULL);
	node->year = NULL;
	str = ctime(&st.st_mtime);
	tab = ft_split_mult(str, 2, ' ', '\n');
	node->month = ft_strdup(tab[1]);
	node->day = ft_strdup(tab[2]);
	if ((six_month(present, st.st_mtime)) == 0)
	{
		node->hour = (char*)malloc(sizeof(char) * 6);
		ft_strncpy(node->hour, tab[3], 5);
	}
	else
	{
		node->hour = NULL;
		node->year = ft_strjoin(" ", tab[4]);
	}
	tab = ft_free_array(tab);
}
