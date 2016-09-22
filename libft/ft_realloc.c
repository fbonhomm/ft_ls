/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 17:06:28 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 17:20:28 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *str, size_t size)
{
	char	*ret;

	if (str == NULL)
		return (malloc(size));
	if ((ret = (char *)(malloc(size))))
	{
		ft_strncpy(ret, (const char *)str, ft_strlen((char *)str));
		ft_free(str);
		return (ret);
	}
	return (NULL);
}
