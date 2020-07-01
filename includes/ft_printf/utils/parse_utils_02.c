/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:26:08 by gloras-t          #+#    #+#             */
/*   Updated: 2019/08/02 22:20:55 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		ft_is_size_correct(char a, char b)
{
	if ((a == b && a == 'h') || (a == b && a == 'l'))
		return (1);
	return (0);
}

void	ft_set_size(t_format *data, char c)
{
	if (data->size[0])
	{
		if (ft_strchrind(SIZES, c) > ft_strchrind(SIZES, data->size[0]))
			data->size[0] = c;
		else if (ft_is_size_correct(data->size[0], c))
			data->size[1] = c;
	}
	else
		data->size[0] = c;
}

void	ft_set_flag(t_format *data, char c)
{
	data->flag[(int)c] = c;
	if (data->flag['0'] && data->flag['-'])
		data->flag['0'] = '\0';
	if (data->flag[' '] && data->flag['+'])
		data->flag[' '] = '\0';
}

void	ft_init_with_default(t_format *data)
{
	if (data->type == 'f' || data->type == 'F' || data->type == 'e'
	|| data->type == 'E')
		data->precision = DEF_PREC_F;
	else if (data->type == 'a' || data->type == 'A')
		data->precision = DEF_PREC_A;
	else if (data->check_types_int[(int)(data->type)])
		data->precision = DEF_PREC_D;
}

void	ft_parse(const char *fmt, int *len, t_format *data, va_list ap)
{
	int			context;
	int			i;
	const char	*offset;

	context = 0;
	i = 0;
	offset = fmt;
	while (i < (*len - 1))
	{
		while (data->check_flag[(int)(*fmt)])
			ft_set_flag(data, *fmt++);
		while (data->check_sizes[(int)(*fmt)])
			ft_set_size(data, *fmt++);
		fmt = ft_dot_treat(fmt, data, &context);
		fmt = ft_asterisk_treat(fmt, data, &context, ap);
		fmt = ft_digit_treat(fmt, data, &context, ap);
		i = ((fmt - offset) == 0) ? 1 : (fmt - offset);
	}
	if (!data->dot)
		ft_init_with_default(data);
}
