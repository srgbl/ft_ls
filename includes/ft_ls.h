/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:57:11 by gloras-t          #+#    #+#             */
/*   Updated: 2020/07/04 21:03:04 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <stdio.h>
# include <stdint.h>
# include "libft.h"

# define DIRENT         struct dirent
# define USER           "USER"
# define OPT_LOWER_A    1
# define OPT_LOWER_L    2
# define OPT_LOWER_R    4
# define OPT_LOWER_T    8
# define OPT_UPPER_R    16
# define OPTIONS        "alrtR"

int		ft_printf(const char *restrict format, ...);

/*
** parse_args.c
*/
int		parse_args(int argc, char *argv[], uint8_t *options, t_list **paths);

/*
** utils.c
*/
int		print_all_file_in_dir(char *dir_name);
char	*get_env_by_name(char *envp[], char *name);
void	println(char *line);
void	print_list(t_list *elem);

#endif
