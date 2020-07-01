/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:29:02 by gloras-t          #+#    #+#             */
/*   Updated: 2019/08/02 23:10:48 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void		v(char *dst, char *str)
{
	while (*str)
	{
		dst[(int)(*str)] = *str;
		str++;
	}
}

void		ft_bzero_8_byte(void *s, size_t n)
{
	__uint64_t	*p;
	char		*a;
	size_t		i;

	p = (__uint64_t*)s;
	while (n % 8 && n > 7)
	{
		*p &= (__uint64_t)0;
		p++;
		n -= 8;
	}
	i = 0;
	a = (char*)p;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}

void		ft_set_checkers(t_format *data)
{
	ft_bzero_8_byte(data->check_flag, CHAR_MAX);
	v(data->check_flag, FLAGS);
	ft_bzero_8_byte(data->check_types, CHAR_MAX);
	v(data->check_types, TYPES);
	ft_bzero_8_byte(data->check_sizes, CHAR_MAX);
	v(data->check_sizes, SIZES);
	ft_bzero_8_byte(data->check_types_int, CHAR_MAX);
	v(data->check_types_int, TYPES_INTEGER);
	ft_bzero_8_byte(data->check_types_alias, CHAR_MAX);
	v(data->check_types_alias, TYPES_ALIAS);
	ft_bzero_8_byte(data->check_signed_int_type, CHAR_MAX);
	v(data->check_signed_int_type, SIGN_INT_TYPE);
	ft_bzero_8_byte(data->check_float_type, CHAR_MAX);
	v(data->check_float_type, FLOAT_TYPES);
}

t_format	*ft_init_data(va_list ap)
{
	t_format	*data;

	data = malloc(sizeof(t_format));
	ft_bzero_8_byte(data->flag, CHAR_MAX);
	data->width = 0;
	data->precision = 0;
	data->size[0] = '\0';
	data->size[1] = '\0';
	data->type = '\0';
	data->value = NULL;
	data->exp = NULL;
	data->sign = 0;
	data->dot = 0;
	data->null_term = 0;
	data->arg_index = 1;
	data->fd = 1;
	data->cast->fp_offset = ap->fp_offset;
	data->cast->gp_offset = ap->gp_offset;
	data->cast->overflow_arg_area = ap->overflow_arg_area;
	data->cast->reg_save_area = ap->reg_save_area;
	ft_set_checkers(data);
	return (data);
}

void		ft_reset_data(t_format *data)
{
	if (data)
	{
		ft_bzero_8_byte(data->flag, CHAR_MAX);
		data->width = 0;
		data->precision = 0;
		data->size[0] = '\0';
		data->size[1] = '\0';
		data->type = '\0';
		data->value = NULL;
		if (data->exp)
			free(data->exp);
		data->exp = NULL;
		data->sign = 0;
		data->dot = 0;
		data->null_term = 0;
	}
}
