/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:51:53 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 19:51:57 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	t_stc	stc;

	if (argc >= 2 && (search_arg(argv, "--help") != 0))
	{
		ft_print_str(3, " Usage : [", argv[0],
			"] [option : [-l, -R, -a, -r, -t, -G]]\n");
		return (0);
	}
	ls(&stc, argv);
	return (0);
}
