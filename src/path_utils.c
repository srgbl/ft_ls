/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:26:02 by slindgre          #+#    #+#             */
/*   Updated: 2020/08/23 23:00:37 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_error(int err, t_list *path)
{
	if (err == ENOENT)
	{
		ft_printf("ft_ls: cannot access '%s': %s\n",
				path->content, strerror(errno));
	}
}

void	ft_lst_free_file(void *elem, size_t content_size)
{
	ft_strdel(&(((t_file*)elem)->name));
	ft_bzero(elem, content_size);
	ft_memdel(&elem);
}

void	map_to_file(t_stat buf, char *path, t_file *file)
{
	file->name = ft_strdup(path);
	file->type = buf.st_mode & __S_IFMT;
	file->n_links = buf.st_nlink;
	file->size = buf.st_size;
	file->gid = buf.st_gid;
	file->uid = buf.st_uid;
	file->last_modified = buf.st_mtime;
}

void	ft_lst_del_elem(t_list **list, t_list **needle)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *list;
	prev = NULL;
	while (tmp)
	{
		if (tmp == *needle)
		{
			if (!prev)
			{
				*list = tmp->next;
			}
			else
			{
				prev->next = tmp->next;
			}
			*needle = tmp->next;
			free(tmp->content);
			free(tmp);
			break ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void	verify_paths(t_list **paths, t_list **files, uint8_t options)
{
	t_stat	buf;
	t_file	file;
	t_list	*path;
	int		(*stat_func)(const char *, struct stat *);

	path = *paths;
	stat_func = (options & OPT_LOWER_L) ? stat : lstat;
	while (path != NULL)
	{
		errno = 0;
		stat_func(path->content, &buf);
		if (errno == ENOENT)
		{
			print_error(errno, path);
			ft_lst_del_elem(paths, &path);
		}
		else if ((buf.st_mode & __S_IFMT) != __S_IFDIR)
		{
			map_to_file(buf, path->content, &file);
			ft_lstadd(files, ft_lstnew(&file, sizeof(file)));
			ft_lst_del_elem(paths, &path);
		}
		else
			path = path->next;
	}
}
