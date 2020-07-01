/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:49:25 by gloras-t          #+#    #+#             */
/*   Updated: 2020/07/01 22:19:43 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	foo(void)
{
	DIR		*dirp;
	DIRENT	*dp;
	
	dirp = opendir(".");
	if (dirp == 0)
		return (-1);
	while ((dp = readdir(dirp)) != 0)
		ft_printf("%s\n", dp->d_name);
	closedir(dirp);
	return (1);
}
