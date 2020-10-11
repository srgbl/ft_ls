/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:57:11 by gloras-t          #+#    #+#             */
/*   Updated: 2020/10/12 00:49:41 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_DEFINES_H
# define FT_LS_DEFINES_H

# include <dirent.h>
# include <stdio.h>
# include <stdint.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include "libft.h"

# define USER           "USER"
# define OPT_LOWER_A    1
# define OPT_LOWER_L    2
# define OPT_LOWER_R    4
# define OPT_LOWER_T    8
# define OPT_UPPER_R    16
# define OPT_NEW_LINE	128
# define OPTIONS        "alrtR"
# define FALSE			0
# define TRUE			1
# define FILES_PER_ROW	10
# define ACL_LEN		9
# define ACL			"rwxrwxrwx"

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct			s_file
{
	char				*name;
	int					type;
	int					mode;
	int					visibility;
	long				last_modified;
	long				gid;
	long				uid;
	int					n_links;
	int					size;
	char				*prefix;
}						t_file;

#endif
