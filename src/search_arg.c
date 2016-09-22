/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchArg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:52:46 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 19:52:49 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		search_arg(char **tab, char *str)
{
	int i;
	int index;

	index = 0;
	i = 1;
	if (tab[i])
	{
		while (tab[i])
		{
			if (ft_strcmp(tab[i], str) == 0)
				index++;
			i++;
		}
	}
	return (index);
}
