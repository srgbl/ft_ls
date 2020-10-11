/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:57:11 by gloras-t          #+#    #+#             */
/*   Updated: 2020/10/04 01:33:18 by slindgre         ###   ########.fr       */
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
int		print_all_file_in_dir(char *dir_name);
char	*get_env_by_name(char *envp[], char *name);
void	println(char *line);
void	print_file_name(t_list *list);

/*
** path_utils.c
*/
void	verify_paths(t_list **paths, t_list **files, uint8_t options);
void	ft_lst_free_file(void *elem, size_t content_size);

/*
** sort_list.c
*/
void	sort_list(t_list **list, int (*sort)(t_list*, t_list*));
int		sort_paths(t_list *a, t_list *b);
int		sort_files(t_list *a, t_list *b);

/*
** print_utils.c
*/
void	print_file_info(t_file *file, uint8_t options);
void	print_files(t_list *files, uint8_t options);

#endif
