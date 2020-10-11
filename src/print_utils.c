/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:19:04 by slindgre          #+#    #+#             */
/*   Updated: 2020/10/04 01:22:59 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_acl(int mode)
{
	char		*acl;
	static int	modes[ACL_LEN] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP,
	S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
	int			i;

	i = 0;
	acl = "rwxrwxrwx";
	while (i < ACL_LEN)
	{
		if (!(modes[i] & mode))
			acl[i] = '-';
		i++;
	}
	return (acl);
}

void	print_file_info(t_file *file, uint8_t options)
{
	t_passwd	*user;
	t_group		*group;
	char		*user_name;
	char		*group_name;
	char		*time;

	user_name = "user not found";
	group_name = "group not found";
	if (options & OPT_LOWER_L)
	{
		if ((user = getpwuid(file->uid)) != NULL)
			user_name = user->pw_name;
		if ((group = getgrgid(file->gid)) != NULL)
			group_name = group->gr_name;
		time = ctime(&file->last_modified);
		time[ft_strlen(time) - 1] = '\0';
		ft_printf("%c%s\t%d\t%s\t%s\t%#10d %s ",
		(file->type == __S_IFDIR) ? 'd' : '-',
		get_acl(file->mode), file->n_links, user_name,
		group_name, file->size, time);
	}
	ft_printf("%s", file->name);
}

void	print_files(t_list *list, uint8_t options)
{
	t_file	*file;
	int		carry;
	int		i;

	i = 0;
	carry = FILES_PER_ROW;
	if (options & OPT_LOWER_L)
		carry = 1;
	while (list)
	{
		file = (t_file*)list->content;
		if (file->visibility == TRUE || options & OPT_LOWER_A)
		{
			if (i % carry)
				ft_printf(" ");
			print_file_info(file, options);
			i++;
			if (i % carry == 0 || list->next == NULL)
			{
				ft_printf("\n");
				i = 0;
			}
		}
		list = list->next;
	}
}
