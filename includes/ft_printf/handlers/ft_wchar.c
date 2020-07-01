/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 21:11:25 by slindgre          #+#    #+#             */
/*   Updated: 2019/07/31 21:29:13 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

size_t	ft_wchar_len(wchar_t c)
{
	size_t len;

	if (c <= 127)
		len = 1;
	else if (c >= 127 && c <= 2047)
		len = 2;
	else if (c >= 2048 && c <= 65535)
		len = 3;
	else
		len = 4;
	return (len);
}

size_t	ft_utf_len(unsigned char c)
{
	size_t len;

	len = 0;
	if (!(c & 128))
		len = 1;
	else if (c >> 5 == 6)
		len = 2;
	else if (c >> 4 == 14)
		len = 3;
	else if (c >> 3 == 30)
		len = 4;
	return (len);
}

void	ft_strsub_utf(t_format *data)
{
	unsigned char	*tmp;
	UI				i;
	size_t			char_len;

	tmp = (unsigned char *)data->value;
	i = 0;
	char_len = 0;
	while (tmp[i])
	{
		char_len = ft_utf_len((unsigned char)tmp[i]);
		i += char_len;
		if (i > data->precision)
			tmp[i -= char_len] = '\0';
	}
}

void	ft_put_wstr(t_line *line, t_format *data)
{
	unsigned char	*tmp;
	int				i;

	tmp = (unsigned char *)data->value;
	i = 0;
	if (data->null_term && data->flag['-'])
	{
		ft_update_line_by_char(line, '\0');
		data->null_term = 0;
	}
	while (tmp[i])
	{
		ft_update_line_by_char(line, tmp[i]);
		i++;
	}
	if (data->null_term)
		ft_update_line_by_char(line, '\0');
	free(tmp);
}

size_t	ft_wide_strlen(wchar_t *wstr)
{
	size_t length;

	length = 0;
	while (*wstr)
	{
		length += ft_wchar_len(*wstr);
		wstr++;
	}
	return (length);
}
