/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:19:04 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/20 00:48:22 by slindgre         ###   ########.fr       */
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

void	print_valid_file(t_file *file)
{
	t_passwd	*user;
	t_group		*group;
	char		*user_name;
	char		*group_name;
	char		*time;

	user_name = "?";
	group_name = "?";
	if ((user = getpwuid(file->uid)) != NULL)
		user_name = user->pw_name;
	if ((group = getgrgid(file->gid)) != NULL)
		group_name = group->gr_name;
	time = ctime(&file->last_modified);
	time[ft_strlen(time) - 1] = '\0';
	print_file_type(file);
	print_file_mode(file);
	ft_printf(" %#5d %s\t%s\t%#11d %#20s ",
	file->n_links, user_name,
	group_name, file->size, time + 4);
}

void	print_file_info(t_file *file, uint8_t options)
{
	if (options & OPT_LOWER_L)
	{
		if (file->invalid)
			ft_printf("-????????? %#5s %s\t%s\t%#11s %#20s ",
		"?", "?", "?", "?", "?");
		else
			print_valid_file(file);
	}
	ft_printf("%s", file->name);
	if (options & OPT_LOWER_L && !(file->invalid) && file->type == S_IFLNK)
		ft_printf(" -> %s", file->target_path);
}

int		print_files(t_list *list, uint8_t options)
{
	t_file	*file;
	int		carry;
	int		i;

	i = 0;
	carry = (options & OPT_LOWER_L) ? 1 : FILES_PER_ROW;
	while (list)
	{
		file = (t_file*)list->content;
		if (file->visibility == TRUE || options & OPT_LOWER_A)
		{
			if (i % carry)
				ft_printf("  ");
			print_file_info(file, options);
			i++;
		}
		if ((i != 0 && i % carry == 0) || (list->next == NULL && i != 0))
		{
			ft_printf("\n");
			options |= OPT_NEW_LINE;
			i = 0;
		}
		list = list->next;
	}
	return (options & OPT_NEW_LINE);
}
