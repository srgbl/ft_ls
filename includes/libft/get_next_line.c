/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:24:22 by gloras-t          #+#    #+#             */
/*   Updated: 2019/10/08 22:08:34 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clear_rest_of_line(t_file_list *head)
{
	ft_strdel(&head->rest_of_line);
	if (!head->rest_of_line)
		head->rest_of_line = ft_strnew(0);
}

void	update_rest_of_line(t_file_list *head, char *str)
{
	char	*ptr;

	ptr = head->rest_of_line;
	head->rest_of_line = ft_strjoin(head->rest_of_line, str);
	ft_strdel(&ptr);
}

int		read_line(t_file_list *head, char **line, char *buf)
{
	char	*ptr;

	if ((*line = ft_cutline_by_chr(&head->rest_of_line, '\n')))
		return (1);
	while ((read(head->fd, buf, BUFF_SIZE)))
	{
		if ((ptr = ft_strchr(buf, '\n')))
		{
			buf[ptr - buf] = '\0';
			if ((*line = ft_strjoin(head->rest_of_line, buf)))
				clear_rest_of_line(head);
			update_rest_of_line(head, ptr + 1);
			return (1);
		}
		else
		{
			update_rest_of_line(head, buf);
			ft_bzero(buf, BUFF_SIZE + 1);
		}
	}
	return (0);
}

int		output_rest_and_free(t_file_list *file, char **line)
{
	while (ft_strcmp(file->rest_of_line, ""))
	{
		*line = ft_cutline_by_chr(&file->rest_of_line, '\n');
		if (!(*line))
		{
			*line = ft_strdup(file->rest_of_line);
			ft_strclr(file->rest_of_line);
		}
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static	t_file_list	*head;
	t_file_list			*file;
	char				buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || (read(fd, buf, 0) < 0))
		return (-1);
	if (!head)
		head = create_file(fd);
	if (!get_file_by_fd(&head, fd))
		add_file(&head, create_file(fd));
	file = get_file_by_fd(&head, fd);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (read_line(file, line, buf))
		return (1);
	if (output_rest_and_free(file, line))
		return (1);
	free(head->rest_of_line);
	free(head);
	head = NULL;
	return (0);
}
