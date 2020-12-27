/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file_prepare.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:19:04 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/27 05:28:14 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_file_mode(t_file *file)
{
	char		modes[MODES_LEN];
	static int	modes_options[MODES_LEN] = {S_IRUSR, S_IWUSR, S_IXUSR,
	S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
	int			i;
	int			mode;

	i = 0;
	mode = file->mode;
	while (i < MODES_LEN)
	{
		if (!(modes_options[i] & mode))
			modes[i] = '-';
		else
			modes[i] = MODES[i];
		i++;
	}
	if (mode & S_ISUID)
		modes[2] = 's';
	if (mode & S_ISGID)
		modes[5] = 's';
	if (mode & S_ISVTX)
		modes[8] = 't';
	ft_printf("%s", modes);
}

void	print_file_type(t_file *file)
{
	char	type_literal;

	type_literal = '-';
	if (file->type == S_IFLNK)
		type_literal = 'l';
	else if (file->type == S_IFSOCK)
		type_literal = 's';
	else if (file->type == S_IFIFO)
		type_literal = 'p';
	else if (file->type == S_IFCHR)
		type_literal = 'c';
	else if (file->type == S_IFBLK)
		type_literal = 'b';
	else if (file->type == S_IFDIR)
		type_literal = 'd';
	ft_printf("%c", type_literal);
}

void	prepare_to_print_file(t_file *f, t_columns *c)
{
	t_passwd	*owner;
	t_group		*group;
	int			size_width;

	f->blocks = (f->blocks == 1) ? 2 : f->blocks;
	c->total_blocks += f->blocks / 2;
	if ((owner = getpwuid(f->uid)) != NULL)
		f->owner_name = ft_strdup(owner->pw_name);
	if ((group = getgrgid(f->gid)) != NULL)
		f->group_name = ft_strdup(group->gr_name);
	c->inode = (f->inode > c->inode) ? f->inode : c->inode;
	c->blocks = (f->blocks > c->blocks) ? f->blocks : c->blocks;
	size_width = get_human_readable_size_width(f->blocks / 2, c->options);
	c->w_blocks = (size_width > c->w_blocks) ? size_width : c->w_blocks;
	c->n_links = (f->n_links > c->n_links) ? f->n_links : c->n_links;
	size_width = get_human_readable_size_width(f->size, c->options);
	c->w_size = (size_width > c->w_size) ? size_width : c->w_size;
	if (ft_strlen(f->owner_name) > c->w_owner)
		c->w_owner = ft_strlen(f->owner_name);
	if (ft_strlen(f->group_name) > c->w_group)
		c->w_group = ft_strlen(f->group_name);
	if (ft_strlen(f->name) > c->w_name)
		c->w_name = ft_strlen(f->name);
}

void	prepare_to_print_files(t_list *list, t_columns *c)
{
	t_file		*f;

	while (list)
	{
		f = (t_file*)list->content;
		if ((f->visibility || c->options & OPT_LOWER_A) && !f->invalid)
			prepare_to_print_file(f, c);
		list = list->next;
	}
}
