/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:57:11 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/26 17:07:50 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_ls_defines.h"

int		ft_printf(const char *restrict format, ...);

/*
** parse_args.c
*/
int		parse_options(char *arg, uint16_t *options);
void	parse_args(int argc, char *argv[], t_list **paths, uint16_t *options);

/*
** comparsion_1.c
*/
int		compare_by_name_asc(t_list *a, t_list *b);
int		compare_by_time_asc(t_list *a, t_list *b);
int		compare_by_name_desc(t_list *a, t_list *b);
int		compare_by_time_desc(t_list *a, t_list *b);

/*
** comparsion_2.c
*/
int		compare_by_size_asc(t_list *a, t_list *b);
int		compare_by_size_desc(t_list *a, t_list *b);

/*
** path_utils.c
*/
int		verify_paths(t_list *paths, t_list **dirs, t_list **files,
		uint16_t options);
void	ft_lst_free_file(void *elem, size_t content_size);
int		print_error(int err, char *path, int mode);
void	map_to_file(t_stat buf, char *path, char *prefix, t_file *file);
int		is_dot_path(char *path);

/*
** sort_list.c
*/
void	sort_list(t_list **list, uint16_t options);

/*
** print_file.c
*/
void	print_file_info(t_file *file, uint16_t options, int last);
int		print_files(t_list *files, uint16_t	options, int mode);

/*
** print_file_2.c
*/
void	print_file_size(t_file *file, uint16_t options);

/*
** print_dir.c
*/
t_list	*read_dir(t_file *dir);
void	print_dirs(t_list *dirs, uint16_t options, int step);

/*
** utils.c
*/
void	convert_file_mtime(t_file *file, char *time_str);
void	print_file_inode(t_file *file);
void	print_file_blocks(t_file *file);

#endif
