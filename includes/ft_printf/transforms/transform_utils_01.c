/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils_01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 05:14:01 by gloras-t          #+#    #+#             */
/*   Updated: 2019/08/03 01:54:40 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		ft_length_treat(t_format *data)
{
	int	length;

	length = ft_strlen(data->value);
	if (data->sign || data->flag['+'])
		length += 1;
	if (data->flag[' '])
		length += 1;
	if (data->flag['#'])
	{
		if (data->type == 'x' || data->type == 'X')
			length += 2;
		if (data->type == 'o' || data->type == 'O')
			length += 1;
	}
	if (data->type == 'c' && !ft_strcmp(data->value, ""))
		length += 1;
	if (ft_check_in_line(data->type, "aAp") && (data->dot || data->flag['0']))
		length += 2;
	return (length);
}

void	ft_transform_width(t_format *data)
{
	UI		length;
	UI		size;
	char	*str;
	UI		k;

	length = ft_length_treat(data);
	size = (data->width > length) ? data->width : length;
	if ((data->width > length) && data->flag['0']
	&& ft_strcmp(data->value, "inf") && ft_strcmp(data->value, "INF"))
	{
		k = (length > size) ? 0 : size - length;
		str = ft_fill_line(k, '0');
		data->flag['0'] = '\0';
		ft_join_prefix_wrapper(&data->value, str);
	}
}

void	ft_transform_hash(t_format *data)
{
	if (data->flag['#'] && ft_check_in_line(data->type, "oOxX"))
	{
		if (ft_check_in_line(data->type, "oO") && ft_strcmp(data->value, "0"))
			ft_join_prefix_wrapper(&data->value, ft_strdup("0"));
		if (data->type == 'x')
			ft_join_prefix_wrapper(&data->value, ft_strdup("0x"));
		if (data->type == 'X')
			ft_join_prefix_wrapper(&data->value, ft_strdup("0X"));
	}
}

void	ft_transform_prefix(t_format *data)
{
	if (ft_check_in_line(data->type, "aAp"))
	{
		if (ft_check_in_line(data->type, "ap") && ft_strcmp(data->value, "nan"))
			ft_join_prefix_wrapper(&data->value, ft_strdup("0x"));
		if (data->type == 'A' && ft_strcmp(data->value, "NAN"))
			ft_join_prefix_wrapper(&data->value, ft_strdup("0X"));
	}
	if (data->flag[' '] && !(data->sign) &&
		ft_check_in_line(data->type, "di"))
		ft_join_prefix_wrapper(&data->value, ft_strdup(" "));
	if (data->check_float_type[(int)(data->type)] &&
		data->flag[' '] && !(data->sign) &&
		(data->width || data->precision || data->dot) &&
		(ft_strcmp(data->value, "nan") || ft_strcmp(data->value, "NAN")))
		ft_join_prefix_wrapper(&data->value, ft_strdup(" "));
}

void	ft_transform_sign(t_format *data)
{
	if (data->sign)
		ft_join_prefix_wrapper(&data->value, ft_strdup("-"));
	else if (data->flag['+'])
		ft_join_prefix_wrapper(&data->value, ft_strdup("+"));
}
