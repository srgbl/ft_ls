/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils_03.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 05:22:48 by gloras-t          #+#    #+#             */
/*   Updated: 2019/08/03 02:18:25 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_transform_int(t_format *data)
{
	char	*str;

	str = ft_fill_line(data->precision - ft_strlen(data->value), '0');
	ft_join_prefix_wrapper(&data->value, str);
}

void	ft_transform_prec_int(t_format *data)
{
	UI length;

	length = ft_strlen(data->value);
	if (data->check_types_int[(int)(data->type)] || data->type == 'p')
	{
		if (data->precision > length)
			ft_transform_int(data);
		if (data->dot
			&& data->precision == 0
			&& data->value[0] == '0'
			&& data->check_types_int[(int)(data->type)])
		{
			ft_update_value(&data->value, ft_strdup(""));
		}
	}
}

void	ft_transform_line(t_format *data)
{
	char	*tmp;
	char	*str;

	if (data->size[0] == 'l' && data->type == 's')
		ft_strsub_utf(data);
	else
	{
		str = ft_strsub(data->value, 0, data->precision);
		tmp = ft_strdup(str);
		ft_update_value(&data->value, tmp);
		free(str);
	}
}

void	ft_transform_prec_char(t_format *data)
{
	UI	length;

	length = ft_strlen(data->value);
	if (data->type == 's')
	{
		if (data->precision > 0 && data->precision < length)
			ft_transform_line(data);
		if (data->dot && data->precision == 0)
			ft_update_value(&data->value, ft_strdup(""));
	}
	if (data->type == 'c' && data->precision > 0)
	{
		data->precision = 0;
		data->dot = 0;
	}
}
