/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:49:25 by gloras-t          #+#    #+#             */
/*   Updated: 2020/08/24 02:38:24 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		print_all_file_in_dir(char *dir_name)
{
	DIR			*dirp;
	t_dirent	*dp;

	dirp = opendir(dir_name);
	if (dirp == 0)
		return (-1);
	while ((dp = readdir(dirp)) != 0)
		println(dp->d_name);
	closedir(dirp);
	return (1);
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
			return (ft_strsub(envp[i], sep_pos + 1, ft_strlen(envp[i])));
		i++;
	}
	return (NULL);
}

void	println(char *line)
{
	ft_printf("%s\n", line);
}

void	print_file_name(t_list *list)
{
	t_file *file;

	file = (t_file*)list->content;
	ft_printf("%s\n", file->name);
}
