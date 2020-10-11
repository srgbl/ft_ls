/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 02:23:45 by slindgre          #+#    #+#             */
/*   Updated: 2020/10/12 02:05:22 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	get_file(char *prefix, char *file_name, uint8_t options)
{
	t_file	file;
	t_stat	buf;
	char	*path;
	int		(*stat_func)(const char *, struct stat *);

	errno = 0;
	path = ft_strjoin(prefix, file_name);
	stat_func = (options & OPT_LOWER_L) ? stat : lstat;
	stat_func(path, &buf);
	if (errno)
		print_error(errno, path);
	map_to_file(buf, file_name, prefix, &file);
	free(path);
	return (file);
}

t_list	*get_files(char *prefix, DIR *dir_stream, uint8_t options)
{
	t_dirent	*dirent;
	t_file		file;
	t_list		*files;

	files = NULL;
	while ((dirent = readdir(dir_stream)) != NULL)
	{
		file = get_file(prefix, dirent->d_name, options);
		ft_lstadd(&files, ft_lstnew(&file, sizeof(file)));
	}
	return (files);
}

t_list	*read_dir(t_file *dir, uint8_t options)
{
	t_list	*files;
	char	*temp;
	DIR		*dir_stream;
	char	*path;

	path = ft_strjoin(dir->prefix, dir->name);
	while (ft_strlen(path) > 1 && path[ft_strlen(path) - 1] == '/')
		path[ft_strlen(path) - 1] = '\0';
	if (path[ft_strlen(path) - 1] != '/')
	{
		temp = ft_strjoin(path, "/");
		free(path);
		path = temp;
	}
	errno = 0;
	files = NULL;
	dir_stream = opendir(path);
	if (errno)
		print_error(errno, dir->name);
	else
		files = get_files(path, dir_stream, options);
	free(path);
	closedir(dir_stream);
	return (files);
}

void	print_header(int i, int step, t_file *dir, uint8_t options)
{
	if (i != 0 || options & OPT_NEW_LINE)
		ft_printf("\n");
	if (step > 0)
		ft_printf("%s", dir->prefix);
}

void	print_dirs(t_list *dirs, uint8_t options, int step)
{
	t_list	*files;
	t_file	*dir;
	int		i;

	i = 0;
	files = NULL;
	while (dirs)
	{
		dir = (t_file*)dirs->content;
		if (dir->type == __S_IFDIR && ((!is_dot_path(dir->name) &&
		(dir->visibility == TRUE || options & OPT_LOWER_A)) || step == 0))
		{
			print_header(i, step, dir, options);
			if (!(i == 0 && dirs->next == NULL) || options & OPT_UPPER_R)
				ft_printf("%s:\n", dir->name);
			files = read_dir(dir, options);
			sort_list(&files, sort_files);
			print_files(files, options);
			if (options & OPT_UPPER_R)
				print_dirs(files, options, step + 1);
			ft_lstdel(&files, ft_lst_free_file);
		}
		dirs = dirs->next;
		i++;
	}
}
