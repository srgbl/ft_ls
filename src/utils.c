/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 01:59:24 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/27 01:43:45 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		print_error(int err, char *path, int mode)
{
	int	res;

	res = 0;
	if (err == EACCES && mode == S_IFDIR)
		res = ft_printf("ft_ls: cannot open directory '%s': %s\n%_",
						path, strerror(err), 2);
	else
		res = ft_printf("ft_ls: cannot access '%s': %s\n%_",
						path, strerror(err), 2);
	return (res);
}

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

void	print_file_blocks(t_file *file, t_columns *c)
{
	if (file->invalid)
		ft_printf("%*s ", c->w_blocks, "?");
	else
		print_blocks(file->blocks / 2, c, "", " ");
}

void	print_file_inode(t_file *file, t_columns *c)
{
	if (file->invalid)
		ft_printf("%*s ", c->w_inode, "?");
	else
		ft_printf("%*lu ", c->w_inode, file->inode);
}

void	get_fields_width(t_columns *c)
{
	if (c->w_owner == 0)
		c->w_owner = 1;
	if (c->w_group == 0)
		c->w_group = 1;
	if (c->w_name == 0)
		c->w_name = 1;
	if (c->w_size == 0)
		c->w_size = 1;
	c->blocks /= 2;
	c->w_inode = 0;
	c->w_links = 0;
	c->w_inode = ft_nbrlen(c->inode);
	if (c->options & OPT_LOWER_L || c->options & OPT_ONE)
		c->w_links = ft_nbrlen(c->n_links);
}
