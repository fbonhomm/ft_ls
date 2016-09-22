/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyOpt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:50:25 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 22:08:27 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			count_arg(char **av)
{
	int		i;
	int		j;
	int		c;

	j = 0;
	c = 0;
	while (av[j])
	{
		if (av[j][0] == '-')
		{
			i = 1;
			while (av[j][i])
			{
				c++;
				i++;
			}
		}
		j++;
	}
	return (c);
}

int			valid_arg(char c)
{
	if ((c == 'l') || (c == 'R') || (c == 'a') || (c == 'r') || (c == 't')
			|| (c == 'G') || (c == '1'))
		return (1);
	else
		return (0);
}

void		cast_arg(char **av, char *str, t_stc *stc)
{
	int		i;
	int		j;

	j = 1;
	stc->count = 0;
	while (av[j])
	{
		if (ft_strcmp(av[j], "--") == 0)
			break ;
		if (av[j][0] == '-')
		{
			i = 1;
			while (av[j][i])
			{
				if (valid_arg(av[j][i]) == 1)
					str[stc->count++] = av[j][i++];
				else
					error_arg(av[j][i]);
			}
		}
		j++;
	}
}

char		*copy_opt(char **av, t_stc *stc)
{
	char	*str;

	stc->count = 0;
	str = (char*)malloc(sizeof(char) * (count_arg(av) + 1));
	if (av[1] && av[1][0] == '-')
		cast_arg(av, str, stc);
	str[stc->count] = '\0';
	stc->count = 0;
	return (str);
}
