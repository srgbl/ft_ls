/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:49:25 by gloras-t          #+#    #+#             */
/*   Updated: 2020/07/04 13:00:19 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	print_all_file_in_dir(char *dir_name)
{
	DIR		*dirp;
	DIRENT	*dp;
	
	dirp = opendir(dir_name);
	if (dirp == 0)
		return (-1);
	while ((dp = readdir(dirp)) != 0)
		println(dp->d_name);
	closedir(dirp);
	return (1);
}

int	print_visible_files_in_dir(char *dir_name)
{
	DIR		*dirp;
	DIRENT	*dp;
	
	dirp = opendir(dir_name);
	if (dirp == 0)
		return (-1);
	while ((dp = readdir(dirp)) != 0)
	{
		if (dp->d_name[0] != '.')
			println(dp->d_name);
	}
	closedir(dirp);
	return (1);
}

/*
** memory allocated
*/
int	time_format(long *timestamp)
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
	println(t);
	return (0);
}
int	get_file_stat(char *name)
{
	struct stat	buf;

	stat(name, &buf);
	// buf.st_size
	// buf.st_nlink
	// buf.st_mtimespec
	time_format(&(buf.st_mtimespec.tv_sec));
	return (0);
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

void	println(char *line)
{
	ft_printf("%s\n", line);
}
