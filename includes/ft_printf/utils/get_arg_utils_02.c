/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_utils_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:38:15 by gloras-t          #+#    #+#             */
/*   Updated: 2019/05/03 05:03:09 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

long double		ft_get_double(int index, t_format *data, va_list ap)
{
	int	i;

	i = 1;
	ap->fp_offset = data->cast->fp_offset;
	ap->gp_offset = data->cast->gp_offset;
	ap->overflow_arg_area = data->cast->overflow_arg_area;
	ap->reg_save_area = data->cast->reg_save_area;
	while (i < index)
	{
		va_arg(ap, void*);
		i++;
	}
	return ((long double)va_arg(ap, double));
}

long double		ft_get_long_double(int index, t_format *data, va_list ap)
{
	int	i;

	i = 1;
	ap->fp_offset = data->cast->fp_offset;
	ap->gp_offset = data->cast->gp_offset;
	ap->overflow_arg_area = data->cast->overflow_arg_area;
	ap->reg_save_area = data->cast->reg_save_area;
	while (i < index)
	{
		va_arg(ap, void*);
		i++;
	}
	return (va_arg(ap, long double));
}

wchar_t			ft_get_wchar_t(int index, t_format *data, va_list ap)
{
	int	i;

	i = 1;
	ap->fp_offset = data->cast->fp_offset;
	ap->gp_offset = data->cast->gp_offset;
	ap->overflow_arg_area = data->cast->overflow_arg_area;
	ap->reg_save_area = data->cast->reg_save_area;
	while (i < index)
	{
		va_arg(ap, void*);
		i++;
	}
	return (va_arg(ap, wchar_t));
}

wchar_t			*ft_get_wchar_t_ptr(int index, t_format *data, va_list ap)
{
	int	i;

	i = 1;
	ap->fp_offset = data->cast->fp_offset;
	ap->gp_offset = data->cast->gp_offset;
	ap->overflow_arg_area = data->cast->overflow_arg_area;
	ap->reg_save_area = data->cast->reg_save_area;
	while (i < index)
	{
		va_arg(ap, void*);
		i++;
	}
	return (va_arg(ap, wchar_t*));
}

char			*ft_get_char_ptr(int index, t_format *data, va_list ap)
{
	int	i;

	i = 1;
	ap->fp_offset = data->cast->fp_offset;
	ap->gp_offset = data->cast->gp_offset;
	ap->overflow_arg_area = data->cast->overflow_arg_area;
	ap->reg_save_area = data->cast->reg_save_area;
	while (i < index)
	{
		va_arg(ap, void*);
		i++;
	}
	return (va_arg(ap, char*));
}
