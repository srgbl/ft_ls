/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:49:25 by gloras-t          #+#    #+#             */
/*   Updated: 2020/07/04 18:58:43 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		print_all_file_in_dir(char *dir_name)
{
	DIR			*dirp;
	t_dirent	*dp;
	
	dirp = opendir(dir_name);
	if (dirp == NULL)
		return (-1);
	while ((dp = readdir(dirp)) != NULL)
		ft_putendl(dp->d_name);
	return (closedir(dirp));
}

int		set_file(char *dir_name, t_file *file)
{
	DIR			*dirp;
	t_dirent	*dp;

	file++;
	
	dirp = opendir(dir_name);
	if (dirp == 0)
		return (-1);
	while ((dp = readdir(dirp)) != 0)
	{
		if (!ft_strcmp(dp->d_name, "Makefile"))
		{
			file->name = ft_strnew(dp->d_namlen);
			ft_strcpy(file->name, dp->d_name);
			file->type = dp->d_type;
			if (dp->d_name[0] == '.')
				file->visibility = 1;
			get_file_stat(file);
		}
	}
	return (closedir(dirp));
}

/*
** memory allocated
*/
int		time_format(long *timestamp)
{
	char	*timeformat;
	char	*ptr;
	char	*t;
	
	timeformat = ctime(timestamp);
	ptr = ft_strchr(timeformat, ':');
	t = ft_strnew(5);
	t[0] = *(ptr - 2);
	t[1] = *(ptr - 1);
	t[2] = ':';
	t[3] = *(ptr + 1);
	t[4] = *(ptr + 2);
	ft_putendl(t);
	return (0);
}

t_file	*init_file()
{
	t_file	*file;

	file = (t_file*)malloc(sizeof(t_file));
	file->name = NULL;
	file->type = 0;
	file->visibility = 0;
	file->last_modified = 0;
	file->n_links = 0;
	file->size = 0;
	file->gid = 0;
	file->uid = 0;
	return (file);
}

void	get_file_stat(t_file *file)
{
	t_stat	buf;

	stat(file->name, &buf);
	file->last_modified = buf.st_mtimespec.tv_sec;
	file->n_links = buf.st_nlink;
	file->size = buf.st_size;
	file->gid = buf.st_gid;
	file->uid = buf.st_uid;
}


char	*get_env_by_name(char *envp[], char *name)
{
	int	i;
	int	sep_pos;

	i = 0;
	while (envp[i])
	{
		sep_pos = ft_strchrind(envp[i], '='); //check if not found
		if (!ft_strncmp(envp[i], name, sep_pos))
			return ft_strsub(envp[i], sep_pos + 1, ft_strlen(envp[i]));
		i++;
	}
	return NULL;
}
