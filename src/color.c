/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:49:36 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 19:49:41 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*str_color_folder(char *s)
{
	return (ft_strjoin_mult(3, "\033[36m", s, "\033[0m"));
}

char		*str_color_folder_all_right(char *s)
{
	return (ft_strjoin_mult(3, "\033[43m", s, "\033[0m"));
}

char		*str_color_file(char *s)
{
	return (ft_strjoin_mult(3, "\033[31m", s, "\033[0m"));
}

char		*str_color_link(char *s)
{
	return (ft_strjoin_mult(3, "\033[35m", s, "\033[0m"));
}
