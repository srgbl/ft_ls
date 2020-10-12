/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:57:11 by gloras-t          #+#    #+#             */
/*   Updated: 2020/10/13 00:21:43 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_ls_defines.h"

int		ft_printf(const char *restrict format, ...);

/*
** parse_args.c
*/
int		parse_args(int argc, char *argv[], t_list **paths, uint8_t *options);

/*
** utils.c
*/
int		sort_files_by_name_asc(t_list *a, t_list *b);
int		sort_files_by_time_asc(t_list *a, t_list *b);
int		sort_files_by_name_desc(t_list *a, t_list *b);
int		sort_files_by_time_desc(t_list *a, t_list *b);

/*
** path_utils.c
*/
int		verify_paths(t_list *paths, t_list **dirs, t_list **files,
		uint8_t options);
void	ft_lst_free_file(void *elem, size_t content_size);
int		print_error(int err, char *path);
void	map_to_file(t_stat buf, char *path, char *prefix, t_file *file);
int		is_dot_path(char *path);

/*
** sort_list.c
*/
void	sort_list(t_list **list, uint8_t options);

/*
** print_file.c
*/
void	print_file_info(t_file *file, uint8_t options);
int		print_files(t_list *files, uint8_t options);

/*
** print_dir.c
*/
t_list	*read_dir(t_file *dir, uint8_t options);
void	print_dirs(t_list *dirs, uint8_t options, int step);

#endif
