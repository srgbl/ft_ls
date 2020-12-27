/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:19:04 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/27 03:29:32 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_valid_file(t_file *file, uint16_t opt, t_columns *c)
{
	char		time[13];

	convert_file_mtime(file, time);
	print_file_type(file);
	print_file_mode(file);
	ft_printf(" %*lu ", c->w_links, file->n_links);
	if (!(opt & OPT_LOWER_G))
		ft_printf("%-*s ", c->w_owner, file->owner_name);
	if (!(opt & OPT_UPPER_G))
		ft_printf("%-*s ", c->w_group, file->group_name);
	print_file_size(file, c);
	ft_printf(" %#12s ", time);
}

void	print_invalid_file(uint16_t opt, t_columns *c)
{
	ft_printf("-????????? %*s ", c->w_links, "?");
	if (!(opt & OPT_LOWER_G))
		ft_printf("%-*s ", c->w_owner, "?");
	if (!(opt & OPT_UPPER_G))
		ft_printf("%-*s ", c->w_group, "?");
	ft_printf("%*s %12s ", c->w_size, "?", "?");
}

void	print_file_info(t_file *file, uint16_t opt, t_columns *c, int last)
{
	if (opt & OPT_LOWER_I)
		print_file_inode(file, c);
	if (opt & OPT_LOWER_S)
		print_file_blocks(file, c);
	if (opt & OPT_LOWER_L)
	{
		if (file->invalid)
			print_invalid_file(opt, c);
		else
			print_valid_file(file, opt, c);
	}
	ft_printf(opt & OPT_UPPER_Q ? "\"%s\"" : "%s", file->name);
	if ((opt & OPT_LOWER_L) && !(file->invalid)
		&& file->type == S_IFLNK)
		ft_printf(opt & OPT_UPPER_Q ? LINKQ : LINK, file->target_path);
	if (opt & OPT_LOWER_M && last == FALSE)
		ft_printf(",");
	ft_printf("\n");
}

int		print_files(t_list *list, uint16_t opt, int context)
{
	t_file		*file;
	t_columns	columns;

	columns.total_blocks = 0;
	columns.inode = 0;
	columns.blocks = 0;
	columns.n_links = 0;
	columns.w_owner = 0;
	columns.w_group = 0;
	columns.w_name = 0;
	columns.w_size = 0;
	columns.options = opt;
	prepare_to_print_files(list, &columns);
	get_fields_width(&columns);
	if (context == S_IFDIR && (opt & OPT_LOWER_L || opt & OPT_LOWER_S))
		print_blocks(columns.total_blocks, &columns, "total ", "\n");
	while (list)
	{
		file = (t_file*)list->content;
		if (file->visibility == TRUE || opt & OPT_LOWER_A)
			print_file_info(file, opt, &columns, list->next == NULL);
		list = list->next;
	}
	return (opt & OPT_NEW_LINE);
}
