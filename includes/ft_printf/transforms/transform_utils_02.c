/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils_02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:44:39 by gloras-t          #+#    #+#             */
/*   Updated: 2019/05/04 01:06:48 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_remove_last_dot(t_format *data)
{
	size_t		i;
	char		*tmp;

	tmp = data->value;
	if (ft_strchr(tmp, '.'))
	{
		i = ft_strchr(tmp, '.') - tmp;
		if (i == ft_strlen(tmp) - 1 || data->precision == 0)
			tmp[i] = '\0';
	}
}

void	ft_transform_type(t_format *data)
{
	if (data->check_types_alias[(int)(data->type)])
	{
		data->type += 32;
		data->size[0] = 'l';
	}
}

void	ft_transform_float(t_format *data)
{
	int		size;
	char	*str;

	if (ft_strchr(data->value, '.'))
	{
		if (ft_strchr("aA", data->type) && !data->dot)
			data->precision = ft_strlen(data->value) - 2;
		size = data->precision - ft_strlen(data->value) +
			ft_strchr(data->value, '.') - data->value + 1;
		if (size > 0 && ((data->precision || data->dot) ||
			(data->exp && ft_strchr("eE", *(data->exp)))))
		{
			str = ft_fill_line(size, '0');
			ft_join_wrapper(&data->value, str);
		}
	}
}

void	ft_transform_prec_float(t_format *data)
{
	if (data->check_float_type[(int)(data->type)])
	{
		if (ft_strchr("aA", data->type))
			ft_round_a(data);
		else
			ft_round_double(data);
		ft_transform_exp(data);
		if (ft_strchr("aA", data->type) && !data->dot)
			ft_remove_zeros(data->value);
		ft_transform_float(data);
		if (ft_strchr("gG", data->type) && !data->flag['#'])
			ft_remove_zeros(data->value);
		if (!data->flag['#'])
			ft_remove_last_dot(data);
		if (data->exp)
			ft_join_wrapper(&data->value, ft_strdup(data->exp));
		ft_fage_capitalize(data);
	}
}

void	ft_transform_prec(t_format *data)
{
	ft_transform_prec_int(data);
	ft_transform_prec_char(data);
	ft_transform_prec_float(data);
}
