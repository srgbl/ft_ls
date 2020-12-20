/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:19:04 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/20 22:35:34 by slindgre         ###   ########.fr       */
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
	time = ctime(&file->mtime_sec);
	time[ft_strlen(time) - 1] = '\0';
	if (ft_strlen(time) > 16)
		time[16] = '\0';
	print_file_type(file);
	print_file_mode(file);
	ft_printf(" %#5d %8s\t%8s\t%#8d %#12s ",
	file->n_links, user_name,
	group_name, file->size, time + 4);
}

void	print_file_info(t_file *file, uint8_t options)
{
	if (options & OPT_LOWER_S)
	{
		if (file->invalid)
			ft_printf("%#4s ", "?");
		else
			ft_printf("%#4d ", file->blocks / 2);
	}
	if (options & OPT_LOWER_L)
	{
		if (file->invalid)
			ft_printf("-????????? %#5s %8s\t%8s\t%#8s %#12s ",
		"?", "?", "?", "?", "?");
		else
			print_valid_file(file);
	}
	ft_printf("%s", file->name);
	if (options & OPT_LOWER_L && !(file->invalid) && file->type == S_IFLNK)
		ft_printf(" -> %s", file->target_path);
	ft_printf("\n");
}

int		print_files(t_list *list, uint8_t options)
{
	t_file	*file;
	t_list	*head;
	int		total_blocks;

	head = list;
	total_blocks = 0;
	while (list)
	{
		file = (t_file*)list->content;
		if ((file->visibility == TRUE || options & OPT_LOWER_A) &&
			file->invalid == FALSE)
			total_blocks += file->blocks / 2;
		list = list->next;
	}
	if (options & OPT_LOWER_L && total_blocks > 0)
		ft_printf("total %d\n", total_blocks);
	list = head;
	while (list)
	{
		file = (t_file*)list->content;
		if (file->visibility == TRUE || options & OPT_LOWER_A)
			print_file_info(file, options);
		list = list->next;
	}
	return (options & OPT_NEW_LINE);
}
