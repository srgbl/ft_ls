/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 22:31:10 by gloras-t          #+#    #+#             */
/*   Updated: 2019/08/03 01:55:26 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		ft_is_flag(char *flag)
{
	if (flag['-'])
		return (1);
	if (flag['+'])
		return (1);
	if (flag[' '])
		return (1);
	if (flag['\''])
		return (1);
	if (flag['#'])
		return (1);
	if (flag['0'])
		return (1);
	return (0);
}

void	ft_remove_hash(t_format *data)
{
	if (data->flag['#'])
	{
		if (ft_check_in_line(data->type, "cdius"))
			data->flag['#'] = '\0';
		if (data->type == 'o')
		{
			if ((data->flag['0'] && data->value[0] == '0')
			|| (data->precision > ft_strlen(data->value)))
				data->flag['#'] = '\0';
			if ((data->flag['0'] && data->value[0] == '0'
			&& data->precision == 0))
				data->flag['#'] = '#';
		}
		if (ft_check_in_line(data->type, "xX")
			&& data->value[0] == '0')
			data->flag['#'] = '\0';
	}
}

void	ft_remove_space(t_format *data)
{
	if (data->flag[' '])
	{
		if (!data->check_signed_int_type[(int)(data->type)])
			data->flag[' '] = '\0';
		if (data->type == 'c')
			data->flag[' '] = '\0';
		if (data->sign)
			data->flag[' '] = '\0';
	}
}

void	ft_remove_zero(t_format *data)
{
	if (data->flag['0'])
	{
		if (ft_check_in_line(data->type, "diuxXo")
			&& data->precision > DEF_PREC_D)
			data->flag['0'] = '\0';
		if (data->dot && data->check_types_int[(int)(data->type)])
			data->flag['0'] = '\0';
		if (data->flag['#'] && data->dot && ft_check_in_line(data->type, "oO"))
			data->flag['0'] = '\0';
	}
}

void	ft_remove_plus(t_format *data)
{
	if (data->flag['+'])
	{
		if (!data->check_signed_int_type[(int)(data->type)])
			data->flag['+'] = '\0';
		if (data->sign)
			data->flag['+'] = '\0';
	}
}
