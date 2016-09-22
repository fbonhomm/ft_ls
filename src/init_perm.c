/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initPerm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:51:10 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/03 14:37:21 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		perm_type(char *str, struct stat st)
{
	if (S_ISLNK(st.st_mode))
		str[0] = 'l';
	else if (S_ISDIR(st.st_mode))
		str[0] = 'd';
	else if (S_ISCHR(st.st_mode))
		str[0] = 'c';
	else if (S_ISBLK(st.st_mode))
		str[0] = 'b';
	else if (S_ISFIFO(st.st_mode))
		str[0] = 'p';
	else if (S_ISSOCK(st.st_mode))
		str[0] = 's';
	else
		str[0] = '-';
}

void		perm_usr(char *str, struct stat st)
{
	str[1] = (st.st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (st.st_mode & S_IWUSR) ? 'w' : '-';
	str[3] = (st.st_mode & S_IXUSR) ? 'x' : '-';
	if (st.st_mode & S_ISUID)
		str[3] = (st.st_mode & 0100) ? 's' : 'S';
}

void		perm_grp(char *str, struct stat st)
{
	str[4] = (st.st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (st.st_mode & S_IWGRP) ? 'w' : '-';
	str[6] = (st.st_mode & S_IXGRP) ? 'x' : '-';
	if (st.st_mode & S_ISGID)
		str[6] = (st.st_mode & 0010) ? 's' : 'S';
}

void		perm_oth(char *str, struct stat st)
{
	str[7] = (st.st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (st.st_mode & S_IWOTH) ? 'w' : '-';
	str[9] = (st.st_mode & S_IXOTH) ? 'x' : '-';
	if (st.st_mode & S_ISVTX)
		str[9] = (st.st_mode & 0100) ? 't' : 'T';
}

char		*init_perm(struct stat st, char *path)
{
	char	*str;
	size_t	count;
	acl_t	acl;

	acl = NULL;
	str = (char*)malloc(sizeof(char) * 12);
	perm_type(str, st);
	perm_usr(str, st);
	perm_grp(str, st);
	perm_oth(str, st);
	count = listxattr(path, NULL, 256, XATTR_NOFOLLOW);
	if (count > 0 && count < 200)
		str[10] = '@';
	else if ((acl = acl_get_file(path, ACL_TYPE_EXTENDED)))
		str[10] = '+';
	else
		str[10] = '\0';
	str[11] = '\0';
	acl_free((void *)acl);
	return (str);
}
