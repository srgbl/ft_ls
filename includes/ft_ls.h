/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:57:11 by gloras-t          #+#    #+#             */
/*   Updated: 2020/07/04 18:46:12 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include "libft/libft.h"

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
# define	USER	"USER"

struct      s_file
{
    char    *name;
    int     type;
    int     visibility;
    long    last_modified;
    int     n_links;
    int     size;
	long	gid;
	long	uid;
}typedef    t_file;

int 	ft_printf(const char *restrict format, ...);
int		print_all_file_in_dir(char *dir_name);
int		set_file(char *dir_name, t_file *file);
char	*get_env_by_name(char *envp[], char *name);
void	get_file_stat(t_file *file);
t_file	*init_file();

#endif