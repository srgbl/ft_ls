/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:49:25 by gloras-t          #+#    #+#             */
/*   Updated: 2020/07/05 01:58:18 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_file_(t_dirent *dp, t_file_ll *list)
{
	t_file	*file;

	file = init_file(dp);
	list++;
}

int		set_file(char *dir_name, t_file_ll *list)
{
	DIR			*dirp;
	t_dirent	*dp;

	dirp = opendir(dir_name);
	if (dirp == NULL)
		return (-1);
	while ((dp = readdir(dirp)) != NULL)
		add_file_(dp, list);
	return (closedir(dirp));
}

/*
** memory allocation
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

t_file	*init_file(t_dirent *dp)
{
	t_file	*file;
	
	file = (t_file*)malloc(sizeof(t_file));
	file->name = ft_strnew(dp->d_namlen);
	ft_strcpy(file->name, dp->d_name);
	file->type = dp->d_type;
	if (dp->d_name[0] != '.')
		file->visibility = 1;
	get_file_stat(file);;
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
