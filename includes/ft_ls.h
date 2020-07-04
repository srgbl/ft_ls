/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:57:11 by gloras-t          #+#    #+#             */
/*   Updated: 2020/07/04 12:46:24 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include "libft/libft.h"

# define	DIRENT	struct dirent
# define	USER	"USER"

int 	ft_printf(const char *restrict format, ...);
int		print_all_file_in_dir(char *dir_name);
int	    print_visible_files_in_dir(char *dir_name);
char	*get_env_by_name(char *envp[], char *name);
void	println(char *line);
int     get_file_stat(char *name);

struct      s_file
{
    char    *name;
    int     type;
    int     visibility;
    long    last_modified;
    int     n_links;
    int     size;
}typedef    t_file;

#endif