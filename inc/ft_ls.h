/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 23:02:31 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 23:02:35 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <dirent.h>
# include <ctype.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <string.h>
# include <sys/xattr.h>
# include <time.h>
# include <sys/acl.h>

typedef struct		s_stc
{
	char			*arg;
	char			**dir;
	char			*space_lien;
	char			*space_root;
	char			*space_group;
	char			*space_size;
	char			*space_min;
	char			*space_maj;
	char			*space_day;
	unsigned long	*times;
	unsigned long	total;
	int				index;
	int				count;
	int				count_dir;
	int				not_arg;
	int				len;
	int				bol;
	int				len_lien;
	int				len_root;
	int				len_group;
	int				len_size;
	int				len_day;
	int				len_min;
	int				len_maj;
	int				l;
	int				rc;
	int				a;
	int				r;
	int				t;
	int				g;
	int				i;
}					t_stc;

typedef	struct		s_tree
{
	char			*name;
	char			*name_bis;
	char			*dir;
	char			*perm;
	char			*lien;
	char			*name_root;
	char			*name_group;
	char			*size;
	char			*min;
	char			*maj;
	char			*month;
	char			*day;
	char			*hour;
	char			*year;
	char			*path_link;
	int				len;
	mode_t			type;
	unsigned long	times;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

void				error(char *str, t_stc *stc);
void				error_arg(char c);
int					search_arg(char **tab, char *str);
int					sort_time(unsigned long s1, unsigned long s2);
void				sort_dir(t_stc *stc);
void				sort_path(char **path, unsigned long *times, t_stc *stc);
void				sort_dir_file(t_stc *stc);
void				sort_dir_error(t_stc *stc);
char				*init_perm(struct stat st, char *path);
void				init_time(t_tree *node, struct stat st);
void				init_time_s(t_stc *stc, char **tab);
void				init_var(t_stc *stc);
void				init_len(t_stc *stc);
void				display(t_tree **tree, t_stc *stc, char *str, int empty);
void				print_tree(t_tree *tree, t_stc *stc);
void				print_l_orgin(t_tree *tree, t_stc *stc);
void				print_l_min_maj(t_tree *tree, t_stc *stc);
void				print_l_link(t_tree *tree, t_stc *stc);
void				free_stc(t_stc *stc);
void				free_tree(t_tree **tree);
void				free_space(t_stc *stc);
char				*str_color_folder(char *s);
char				*str_color_file(char *s);
char				*str_color_link(char *s);
char				*str_color_folder_all_right(char *s);
char				*color(t_stc *stc, char *str, unsigned int mode);
void				node_not_l(t_tree *node, t_stc *stc, char *dir, char *name);
void				node_opt_l(t_tree *node, t_stc *stc, char *dir, char *name);
void				len_padding(t_tree *node, t_stc *stc);
void				space(t_stc *stc, t_tree *tree);
void				switch_loop(t_stc *stc, int i);
void				node(t_tree **tree, t_stc *stc, char *name, char *dir);
void				not_recursive(t_stc *stc);
void				loop_suite(t_stc *stc, t_tree **tree, DIR *rep,
						struct dirent *fichier);
int					six_month(time_t present, time_t file);
char				*date(char *year, char *hour);
void				file(t_stc *stc, t_tree **tree);
char				*read_link(char *path);
char				*name(char *str);
char				*ft_path(t_stc *stc, char *dir, char *str);
int					condition(t_stc *stc, char *str);
void				count_dir(t_stc *stc);
void				loop_arg(t_stc *stc);
char				*join_path(char *path, char *name);
void				add_node(t_tree **tree, t_stc *stc, char *dir, char *name);
void				ls(t_stc *stc, char **av);
void				copy_dir(char **tab, t_stc *stc);
void				not_arg(t_stc *stc);
void				open_dir_and_node(t_stc *stc, t_tree **tree);
char				*copy_opt(char **av, t_stc *stc);
int					len_dir(char **av, t_stc *stc);
int					len_array(char **str);
void				suite_with_r(t_stc *stc, char *dir);

#endif
