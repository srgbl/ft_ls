/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:26:02 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/27 10:09:57 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lst_free_file(void *elem, size_t content_size)
{
	if ((((t_file*)elem)->name) != NULL)
		ft_strdel(&(((t_file*)elem)->name));
	if ((((t_file*)elem)->prefix) != NULL)
		ft_strdel(&(((t_file*)elem)->prefix));
	if ((((t_file*)elem)->target_path) != NULL)
		ft_strdel(&(((t_file*)elem)->target_path));
	if ((((t_file*)elem)->owner_name) != NULL)
		ft_strdel(&(((t_file*)elem)->owner_name));
	if ((((t_file*)elem)->group_name) != NULL)
		ft_strdel(&(((t_file*)elem)->group_name));
	ft_bzero(elem, content_size);
	ft_memdel(&elem);
}

void		map_to_file(t_stat buf, char *path, char *prefix, t_file *file)
{
	file->inode = buf.st_ino;
	file->name = ft_strdup(path);
	file->type = buf.st_mode & S_IFMT;
	file->mode = buf.st_mode;
	file->n_links = buf.st_nlink;
	file->size = buf.st_size;
	file->gid = buf.st_gid;
	file->uid = buf.st_uid;
	file->mtime_sec = buf.st_mtime;
	file->mtime_nsec = buf.st_mtim.tv_nsec;
	file->prefix = ft_strdup(prefix);
	file->visibility = (path[0] != '.') ? TRUE : FALSE;
	file->invalid = FALSE;
	file->target_path = NULL;
	file->blksize = buf.st_blksize;
	file->blocks = buf.st_blocks;
	file->owner_name = NULL;
	file->group_name = NULL;
	file->xattr = get_xattr(file->name, file->prefix);
}

int			is_dot_path(char *path)
{
	if (ft_strcmp(path, ".") == 0 || ft_strcmp(path, "..") == 0)
		return (TRUE);
	return (FALSE);
}

int			verify_paths(t_list *path, t_list **dirs, t_list **files, \
															uint16_t options)
{
	t_stat	buf;
	t_file	file;
	int		(*stat_func)(const char *, struct stat *);
	int		res;

	res = 0;
	stat_func = (options & OPT_LOWER_L) ? stat : lstat;
	while (path != NULL)
	{
		errno = 0;
		stat_func(path->content, &buf);
		if (errno)
			res += print_error(errno, path->content, buf.st_mode & S_IFMT);
		else
		{
			map_to_file(buf, path->content, "", &file);
			if (file.type != S_IFDIR)
				ft_lstadd(files, ft_lstnew(&file, sizeof(file)));
			else
				ft_lstadd(dirs, ft_lstnew(&file, sizeof(file)));
		}
		path = path->next;
	}
	return (res);
}
