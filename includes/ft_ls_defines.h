/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:57:11 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/26 17:13:47 by slindgre         ###   ########.fr       */
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

# define OPT_LOWER_A    (uint16_t)(1)
# define OPT_LOWER_L    (uint16_t)(1 << 1)
# define OPT_LOWER_R    (uint16_t)(1 << 2)
# define OPT_LOWER_T	(uint16_t)(1 << 3)
# define OPT_UPPER_R    (uint16_t)(1 << 4)
# define OPT_LOWER_S    (uint16_t)(1 << 5)
# define OPT_UPPER_S    (uint16_t)(1 << 6)
# define OPT_LOWER_H    (uint16_t)(1 << 7)
# define OPT_UPPER_Q    (uint16_t)(1 << 8)
# define OPT_LOWER_M    (uint16_t)(1 << 9)
# define OPT_LOWER_G    (uint16_t)(1 << 10)
# define OPT_LOWER_I	(uint16_t)(1 << 11)
# define OPT_ONE		(uint16_t)(1 << 12)

# define OPT_NEW_LINE	(uint16_t)(1 << 15)
# define OPTIONS        "alrtRsShQmgi1"
# define FALSE			0
# define TRUE			1
# define FILES_PER_ROW	1
# define MODES_LEN		9
# define MODES			"rwxrwxrwx"
# define PATH_LEN		1024
# define BLOCK_SIZE		1024
# define HALF_YEAR		15552000

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct			s_file
{
	unsigned long		inode;
	char				*name;
	int					type;
	int					mode;
	int					visibility;
	long				mtime_sec;
	long				mtime_nsec;
	long				gid;
	long				uid;
	unsigned long		n_links;
	long				size;
	char				*prefix;
	int					invalid;
	char				*target_path;
	int					blksize;
	long				blocks;
}						t_file;

#endif
