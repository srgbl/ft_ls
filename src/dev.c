/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:26:02 by slindgre          #+#    #+#             */
/*   Updated: 2020/08/23 18:00:20 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void print_file_info(t_list **paths)
{
    t_stat	buf;
	t_file *file;
	t_list *path;

	if (paths != NULL && *paths != NULL)
	{
		path = *paths;
		while(path != NULL)
		{
			if (errno == ENOENT)
			{
				ft_printf("ft_ls: cannot access '%s': No such file or directory\n", path->content);
				continue;
			}
			file = (t_file*)malloc(sizeof(t_file));
			ft_printf("%s\n", path->content);
			ft_printf("ret val:\t%d\n", stat(path->content, &buf));
			file->last_modified = buf.st_mtime;
			file->n_links = buf.st_nlink;
			file->size = buf.st_size;
			file->gid = buf.st_gid;
			file->uid = buf.st_uid;

			ft_printf("st_dev:\t\t%07lu\n", buf.st_dev);
			ft_printf("st_ino:\t\t%07lu\n", buf.st_ino);
			ft_printf("st_nlink:\t%07lu\n", buf.st_nlink);
			ft_printf("st_mode:\t%07d\n", buf.st_mode);
			ft_printf("st_mode&mask:\t%07o\n", buf.st_mode & __S_IFMT);
					
			ft_printf("st_uid:\t\t%07u\n", buf.st_uid);
			ft_printf("st_gid:\t\t%07u\n", buf.st_gid);
			ft_printf("st_pad0:\t%07u\n", buf.__pad0);
			ft_printf("st_size:\t%07ld\n", buf.st_size);
			ft_printf("st_blksize:\t%07ld\n", buf.st_blksize);
			ft_printf("st_blocls:\t%07ld\n", buf.st_blocks);

			ft_printf("st_atime:\t%07ld\n", buf.st_atime);
			ft_printf("st_mtime:\t%07ld\n", buf.st_mtime);
			ft_printf("st_ctime:\t%07ld\n", buf.st_ctime);
			ft_printf("errno:\t\t%d\n\n", errno);

			path = path->next; 
		}
	}

//__time_t st_atime;			/* Time of last access.  */
//__syscall_ulong_t st_atimensec;	/* Nscecs of last access.  */
//__time_t st_mtime;			/* Time of last modification.  */
//__syscall_ulong_t st_mtimensec;	/* Nsecs of last modification.  */
//__time_t st_ctime;			/* Time of last status change.  */
//__syscall_ulong_t st_ctimensec;	/* Nsecs of last status change.  */
	
//#define	__S_IFDIR	0040000	/* Directory.  */
//#define	__S_IFCHR	0020000	/* Character device.  */
//#define	__S_IFBLK	0060000	/* Block device.  */
//#define	__S_IFREG	0100000	/* Regular file.  */
//#define	__S_IFIFO	0010000	/* FIFO.  */
//#define	__S_IFLNK	0120000	/* Symbolic link.  */
//#define	__S_IFSOCK	0140000	/* Socket.  *

}
