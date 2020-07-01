/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:37:44 by gloras-t          #+#    #+#             */
/*   Updated: 2019/05/04 00:37:56 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_create_characters_line(char *str)
{
	ft_bzero_8_byte(str, CHAR_MAX);
	v(str, FLAGS);
	v(str, TYPES);
	v(str, DIGITS);
	v(str, SIZES);
	v(str, ".*$,;:_");
}

void	ft_prepare_parse(const char *fmt, t_format *data, int *len)
{
	char	str[CHAR_MAX];

	*len = 0;
	ft_create_characters_line(str);
	while (*fmt)
	{
		if (str[(int)(*fmt)])
		{
			*len += 1;
			if (data->check_types[(int)(*fmt)])
			{
				data->type = *fmt;
				break ;
			}
		}
		else
		{
			data->value = ft_insert_char("", *fmt, 0);
			*len += 1;
			break ;
		}
		fmt++;
	}
}

void	ft_strtoupper(char *str)
{
	while (*str)
	{
		if (*str >= 97 && *str <= 122)
			*str -= 32;
		str++;
	}
}

void	ft_set_value_by_context(t_format *data, int context, int *number)
{
	if (context == 1 && *number >= 0)
		data->precision = *number;
	else
		data->dot = 0;
	if (context == 0)
	{
		if (*number < 0)
		{
			ft_set_flag(data, '-');
			ft_abs_int(number);
		}
		data->width = *number;
	}
	*number = 0;
}

int		ft_get_color_index(char *fmt)
{
	int		i;
	char	*colors[COLOR_NUMBER];

	colors[0] = "{red}";
	colors[1] = "{green}";
	colors[2] = "{yellow}";
	colors[3] = "{blue}";
	colors[4] = "{magenta}";
	colors[5] = "{cyan}";
	colors[6] = "{eoc}";
	i = 0;
	while (i < COLOR_NUMBER)
	{
		if (!ft_strcmp(fmt, colors[i]))
			return (i);
		i++;
	}
	return (-1);
}
