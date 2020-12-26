/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 01:59:24 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/26 17:25:27 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	convert_file_mtime(t_file *file, char *time_str)
{
	char		*mtime;
	int			time_now;

	time_now = time(NULL);
	mtime = ctime(&file->mtime_sec);
	mtime[ft_strlen(mtime) - 1] = '\0';
	if (ft_strlen(mtime) >= 24)
	{
		if (time_now - file->mtime_sec > HALF_YEAR)
		{
			mtime[11] = mtime[19];
			mtime[12] = mtime[20];
			mtime[13] = mtime[21];
			mtime[14] = mtime[22];
			mtime[15] = mtime[23];
		}
		mtime[16] = '\0';
	}
	ft_strcpy(time_str, mtime + 4);
}

void	print_file_blocks(t_file *file)
{
	if (file->invalid)
		ft_printf("%#4s ", "?");
	else
		ft_printf("%#4ld ", file->blocks / 2);
}

void	print_file_inode(t_file *file)
{
	if (file->invalid)
		ft_printf("%#18s ", "?");
	else
		ft_printf("%#18lu ", file->inode);
}
