/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:57:11 by gloras-t          #+#    #+#             */
/*   Updated: 2020/10/04 03:05:04 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <stdio.h>
# include <stdint.h>
# include <sys/stat.h>
# include <errno.h>
# include "libft.h"

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
# define USER           "USER"
# define OPT_LOWER_A    1
# define OPT_LOWER_L    2
# define OPT_LOWER_R    4
# define OPT_LOWER_T    8
# define OPT_UPPER_R    16
# define OPTIONS        "alrtR"

typedef struct	s_file
{
	char        *name;
	int     	type;
	int     	visibility;
	long    	last_modified;
	long		gid;
	long		uid;
	int     	n_links;
	int     	size;
}				t_file;

int		ft_printf(const char *restrict format, ...);

/*
** parse_args.c
*/
int		parse_args(int argc, char *argv[], t_list **paths, uint8_t *options);

/*
** utils.c
*/
int		print_all_file_in_dir(char *dir_name);
char	*get_env_by_name(char *envp[], char *name);
void	println(char *line);
void	print_file_name(t_list *list);

/*
** path_utils.c
*/
void	verify_paths(t_list *paths, t_list **dirs, t_list **files, uint8_t options);
void	ft_lst_free_file(void *elem, size_t content_size);
void	print_error(int err, char *path);
void	map_to_file(t_stat buf, char *path, t_file *file);

/*
** sort_list.c
*/
void	sort_list(t_list **list, int (*sort)(t_list*, t_list*));
int     sort_files(t_list *a, t_list *b);

/*
** print_dir.c
*/
t_list	*read_dir(t_list *dir, uint8_t options);

#endif
