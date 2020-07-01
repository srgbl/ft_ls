/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:31:04 by gloras-t          #+#    #+#             */
/*   Updated: 2019/08/03 01:57:45 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_foo_percent(t_format *data, va_list ap)
{
	if (ap)
		ft_update_value(&data->value, ft_strdup("%"));
}

t_table	ft_init_handler(char type, t_handler fun)
{
	t_table table;

	table.type = type;
	table.fun = fun;
	return (table);
}

void	ft_init_table(t_table *table)
{
	table[0] = ft_init_handler('%', ft_foo_percent);
	table[1] = ft_init_handler('d', ft_foo_int);
	table[2] = ft_init_handler('x', ft_foo_int);
	table[3] = ft_init_handler('o', ft_foo_int);
	table[4] = ft_init_handler('u', ft_foo_int);
	table[5] = ft_init_handler('X', ft_foo_int);
	table[6] = ft_init_handler('i', ft_foo_int);
	table[7] = ft_init_handler('f', ft_foo_float);
	table[8] = ft_init_handler('F', ft_foo_float);
	table[9] = ft_init_handler('g', ft_foo_float);
	table[10] = ft_init_handler('G', ft_foo_float);
	table[11] = ft_init_handler('e', ft_foo_float);
	table[12] = ft_init_handler('E', ft_foo_float);
	table[13] = ft_init_handler('a', ft_foo_float);
	table[14] = ft_init_handler('A', ft_foo_float);
	table[15] = ft_init_handler('c', ft_foo_char);
	table[16] = ft_init_handler('s', ft_foo_str);
	table[17] = ft_init_handler('p', ft_foo_ptr);
	table[18] = ft_init_handler('b', ft_foo_int);
	table[19] = ft_init_handler('B', ft_foo_int);
	table[20] = ft_init_handler('_', ft_foo_fd);
}

void	ft_parse_format(t_format *data, va_list ap)
{
	int		i;
	t_table table[TABLE_SIZE];

	ft_init_table(table);
	i = 0;
	while (i < TABLE_SIZE)
	{
		if (table[i].type == data->type)
		{
			table[i].fun(data, ap);
			break ;
		}
		i++;
	}
}

void	ft_data_output(t_line *line, t_format *data)
{
	if (data->type != '\0')
	{
		data->null_term = (data->type == 'c'
		&& !ft_strcmp(data->value, "") ? 1 : 0);
		ft_remove_unused_flags(data);
		if (data->value)
			ft_transform_prec(data);
	}
	if (data->value)
	{
		ft_prepate_to_print(data);
		ft_put_wstr(line, data);
	}
	ft_reset_data(data);
}
