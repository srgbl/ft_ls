/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 02:23:45 by slindgre          #+#    #+#             */
/*   Updated: 2020/10/11 23:10:55 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	get_file(char *dir_name, char *file_name, uint8_t options)
{
	t_file	file;
	t_stat	buf;
	char	*path;
	int		(*stat_func)(const char *, struct stat *);

	errno = 0;
	path = ft_strjoin(dir_name, file_name);
	stat_func = (options & OPT_LOWER_L) ? stat : lstat;
	stat_func(path, &buf);
	if (errno)
		print_error(errno, path);
	map_to_file(buf, file_name, &file);
	free(path);
	return (file);
}

t_list	*get_files(char *dir_name, DIR *dir_stream, uint8_t options)
{
	t_dirent	*dirent;
	t_file		file;
	t_list		*files;

	files = NULL;
	while ((dirent = readdir(dir_stream)) != NULL)
	{
		file = get_file(dir_name, dirent->d_name, options);
		ft_lstadd(&files, ft_lstnew(&file, sizeof(file)));
	}
	return (files);
}

t_list	*read_dir(t_file *dir, uint8_t options)
{
	t_list	*files;
	char	*temp;
	DIR		*dir_stream;

	if (dir == NULL)
		return (NULL);
	if (dir->name[ft_strlen(dir->name) - 1] != '/')
	{
		temp = ft_strjoin(dir->name, "/");
		free(dir->name);
		dir->name = temp;
	}
	errno = 0;
	files = NULL;
	dir_stream = opendir(dir->name);
	if (errno)
		print_error(errno, dir->name);
	else
		files = get_files(dir->name, dir_stream, options);
	closedir(dir_stream);
	return (files);
}

void	print_dirs(t_list *dirs, uint8_t options)
{
	t_list	*files;
	t_file	*dir;
	int		i;

	i = 0;
	files = NULL;
	while (dirs)
	{
		dir = (t_file*)dirs->content;
		if (i != 0 || options & OPT_NEW_LINE)
			ft_printf("\n");
		if (!(i == 0 && dirs->next == NULL))
			ft_printf("%s:\n", dir->name);
		files = read_dir(dir, options);
		sort_list(&files, sort_files);
		print_files(files, options);
		ft_lstdel(&files, ft_lst_free_file);
		dirs = dirs->next;
		i++;
	}
}
