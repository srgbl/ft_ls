/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 21:17:20 by gloras-t          #+#    #+#             */
/*   Updated: 2019/05/03 05:37:40 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_fill_value(t_format *data, char c)
{
	UI		length;
	char	*str;

	length = ft_strlen(data->value);
	if (data->null_term)
		length = 1;
	str = ft_fill_line(data->width - length, c);
	ft_join_prefix_wrapper(&data->value, str);
}

void	ft_transform_align(t_format *data)
{
	char	*str;
	UI		length;

	length = ft_strlen(data->value);
	if (data->width > (length + data->null_term))
	{
		if (data->flag['-'])
		{
			str = ft_fill_line(data->width - data->null_term - length, ' ');
			ft_join_wrapper(&data->value, str);
		}
		else
			ft_fill_value(data, ' ');
	}
}

void	ft_remove_unused_flags(t_format *data)
{
	if (ft_is_flag(data->flag))
	{
		ft_remove_hash(data);
		ft_remove_space(data);
		ft_remove_zero(data);
		ft_remove_plus(data);
	}
}

void	ft_prepate_to_print(t_format *data)
{
	ft_transform_width(data);
	ft_transform_hash(data);
	ft_transform_prefix(data);
	ft_transform_sign(data);
	ft_transform_align(data);
}
