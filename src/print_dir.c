/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 02:23:45 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/26 14:16:24 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	get_file(char *prefix, char *file_name)
{
	t_file	file;
	t_stat	buf;
	char	*path;
	int		(*stat_func)(const char *, struct stat *);
	char	*target;

	errno = 0;
	path = ft_strjoin(prefix, file_name);
	stat_func = lstat;
	stat_func(path, &buf);
	map_to_file(buf, file_name, prefix, &file);
	if (errno)
	{
		print_error(errno, path, 0);
		file.invalid = TRUE;
		file.blocks = 0;
		file.size = 0;
	}
	else if (file.mode & S_IFLNK && (target = ft_strnew(PATH_LEN)) != NULL)
	{
		readlink(path, target, PATH_LEN);
		file.target_path = target;
	}
	free(path);
	return (file);
}

t_list	*get_files(char *path, DIR *dir_stream)
{
	t_dirent	*dirent;
	t_file		file;
	t_list		*files;
	char		*prefix;

	files = NULL;
	prefix = NULL;
	if (path[ft_strlen(path) - 1] != '/')
		prefix = ft_strjoin(path, "/");
	else
		prefix = ft_strdup(path);
	while ((dirent = readdir(dir_stream)) != NULL)
	{
		file = get_file(prefix, dirent->d_name);
		ft_lstadd(&files, ft_lstnew(&file, sizeof(file)));
	}
	free(prefix);
	return (files);
}

t_list	*read_dir(t_file *dir)
{
	t_list	*files;
	DIR		*dir_stream;
	char	*path;

	path = ft_strjoin(dir->prefix, dir->name);
	while (ft_strlen(path) > 1 && path[ft_strlen(path) - 1] == '/')
		path[ft_strlen(path) - 1] = '\0';
	errno = 0;
	files = NULL;
	dir_stream = opendir(path);
	if (errno)
		print_error(errno, path, S_IFDIR);
	else
		files = get_files(path, dir_stream);
	free(path);
	closedir(dir_stream);
	return (files);
}

void	print_header(int i, int step, t_file *dir, uint16_t opt)
{
	if (i != 0 || opt & OPT_NEW_LINE)
		ft_printf("\n");
	if (step > 0)
		ft_printf(opt & OPT_UPPER_Q ? "\"%s" : "%s", dir->prefix);
}

void	print_dirs(t_list *dirs, uint16_t opt, int step)
{
	t_list	*files;
	t_file	*dir;
	int		i;

	i = 0;
	files = NULL;
	while (dirs)
	{
		dir = (t_file*)dirs->content;
		if (dir->type == S_IFDIR && ((!is_dot_path(dir->name) &&
		(dir->visibility == TRUE || opt & OPT_LOWER_A)) || step == 0))
		{
			if ((files = read_dir(dir)) != NULL)
				print_header(i, step, dir, opt);
			if ((!(i == 0 && !dirs->next) || opt & OPT_UPPER_R) && files)
				ft_printf(opt & OPT_UPPER_Q ? "%s\":\n" : "%s:\n", dir->name);
			sort_list(&files, opt);
			print_files(files, opt, S_IFDIR);
			if (opt & OPT_UPPER_R)
				print_dirs(files, opt, step + 1);
			ft_lstdel(&files, ft_lst_free_file);
		}
		dirs = dirs->next;
		i++;
	}
}
