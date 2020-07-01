/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:57:11 by gloras-t          #+#    #+#             */
/*   Updated: 2020/07/02 00:30:14 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

#include <dirent.h>
#include <stdio.h>
#include "libft/libft.h"

# define	DIRENT	struct dirent
# define	USER	"USER"

int 	ft_printf(const char *restrict format, ...);
int		foo(char *dir_name);
char	*get_env_by_name(char *envp[], char *name);
void	println(char *line);

#endif