/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:42:49 by slindgre          #+#    #+#             */
/*   Updated: 2019/05/03 05:47:42 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_resolve_unsigned_size(t_format *data, ULL *value)
{
	if (data->size[0])
	{
		if (data->size[0] == 'h' && !data->size[1])
			*value = (short unsigned int)(*value);
		else if (data->size[0] == 'h' && data->size[1] == 'h')
			*value = (unsigned char)(*value);
		else if (data->size[0] == 'z')
			*value = (size_t)(*value);
		else if (data->size[0] == 'j')
			*value = (intmax_t)(*value);
		else if (data->size[0] == 't'
			|| (data->size[0] == 'l' && !data->size[1]))
			*value = (unsigned long)(*value);
	}
	else
		*value = (unsigned int)(*value);
}

void	ft_foo_unsigned_int(t_format *data, va_list ap)
{
	ULL		value;
	int		base;

	base = ft_get_base(data);
	value = ft_get_u_long_long(data->arg_index, data, ap);
	ft_resolve_unsigned_size(data, &value);
	data->value = ft_itoa_base(value, base);
	if (data->type == 'X')
		ft_strtoupper(data->value);
}

void	ft_resolve_size(t_format *data, LL *value)
{
	if (data->size[0])
	{
		if (data->size[0] == 'h' && !data->size[1])
			*value = (short)(*value);
		else if (data->size[0] == 'h' && data->size[1] == 'h')
			*value = (signed char)(*value);
		else if (data->size[0] == 'z')
			*value = (size_t)(*value);
		else if (data->size[0] == 'j')
			*value = (intmax_t)(*value);
		else if (data->size[0] == 't'
			|| (data->size[0] == 'l' && !data->size[1]))
			*value = (long)(*value);
	}
	else
		*value = (int)(*value);
}

void	ft_foo_signed_int(t_format *data, va_list ap)
{
	LL		value;
	int		base;

	base = ft_get_base(data);
	value = ft_get_long_long(data->arg_index, data, ap);
	ft_resolve_size(data, &value);
	if (value < 0)
		data->sign = 1;
	value = ft_int_abs(value);
	data->value = ft_itoa_base(value, base);
}

void	ft_foo_int(t_format *data, va_list ap)
{
	if (ft_strchr("uUoOxXbB", data->type))
		ft_foo_unsigned_int(data, ap);
	else
		ft_foo_signed_int(data, ap);
}
