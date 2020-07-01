/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:00:50 by gloras-t          #+#    #+#             */
/*   Updated: 2019/05/03 05:03:13 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_line	*ft_init_line(void)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (line)
	{
		line->line = (unsigned char *)ft_strnew(BUF_SIZE);
		line->length = 0;
		line->amount = 0;
		return (line);
	}
	return (NULL);
}

void	ft_increase_line(t_line *line)
{
	unsigned char	*res;
	unsigned char	*tmp;

	if (!(line->length % BUF_SIZE))
	{
		res = (unsigned char*)ft_strnew(line->length + BUF_SIZE);
		tmp = line->line;
		ft_memcpy(res, tmp, line->length);
		line->line = res;
		free(tmp);
	}
}

void	ft_update_line_color(t_line *line, char *color)
{
	while (*color)
	{
		line->line[line->length] = *color;
		line->length += 1;
		ft_increase_line(line);
		color++;
	}
}

void	ft_update_line_by_char(t_line *line, char c)
{
	line->line[line->length] = c;
	line->length += 1;
	line->amount += 1;
	ft_increase_line(line);
}

void	ft_free_line(t_line *line)
{
	if (line)
	{
		free(line->line);
		free(line);
	}
}
