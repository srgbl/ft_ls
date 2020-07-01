/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_utils_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:34:17 by gloras-t          #+#    #+#             */
/*   Updated: 2019/05/03 05:03:05 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

LL		ft_get_long_long(int index, t_format *data, va_list ap)
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
	return (va_arg(ap, LL));
}

UL		ft_get_u_long(int index, t_format *data, va_list ap)
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
	return (va_arg(ap, UL));
}

ULL		ft_get_u_long_long(int index, t_format *data, va_list ap)
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
	return (va_arg(ap, ULL));
}

int		ft_get_int(int index, t_format *data, va_list ap)
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
	return (va_arg(ap, int));
}

void	*ft_get_void_ptr(int index, t_format *data, va_list ap)
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
	return (va_arg(ap, void*));
}
