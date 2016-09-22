/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:50:40 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 19:50:44 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		error_arg(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_print_str(3, "\n", "usage: ls [-latrGR] [file ...]", "\n");
	exit(-1);
}

void		error(char *str, t_stc *stc)
{
	char	*tmp;

	tmp = name(str);
	if (((stc->rc && stc->len != 0) &&
		ft_strcmp(stc->dir[stc->count], str) != 0) || (stc->len != 0))
	{
		ft_print_str(3, "\n", str, ":\n");
		ft_print_str_endl(5, "ls: ", tmp, ": ", strerror(errno), "\n");
	}
	else if ((stc->rc && stc->len == 0) &&
		(ft_strcmp(stc->dir[stc->count], str) != 0))
	{
		ft_print_str(2, str, ":\n");
		ft_print_str_endl(5, "ls: ", tmp, ": ", strerror(errno), "\n");
	}
	else
		ft_print_str_endl(5, "ls: ", str, ": ", strerror(errno), "\n");
	tmp = ft_free(tmp);
}
