/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:50:31 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 19:50:36 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	other(t_stc *stc, int i)
{
	if (!stc->rc && !stc->l && (i < stc->count_dir))
		ft_putchar('\n');
	else if (!stc->rc && ((i + 1) < stc->count_dir))
		ft_putchar('\n');
	else if (!stc->l)
		ft_putstr("\n\n");
	else
		ft_putchar('\n');
}

void	display(t_tree **tree, t_stc *stc, char *str, int empty)
{
	if ((((stc->count_dir > 1)) && !stc->l && stc->count == 0 &&
		!stc->rc && empty != 0) || ((stc->count_dir > 1) && !stc->l &&
			stc->len == 0 && empty != 0))
		ft_print_str(2, str, ":\n");
	else if ((stc->len != 0 && empty != 0) ||
			(stc->count_dir > 1 && empty != 0))
		ft_print_str(3, "\n", str, ":\n");
	if (stc->l && tree[0] && empty != 0)
	{
		ft_putstr("total ");
		ft_putnbr(stc->total);
		ft_putchar('\n');
		stc->total = 0;
	}
	if (((empty != 2) && tree[0]) || (stc->a))
		print_tree(*tree, stc);
}
