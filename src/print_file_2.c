/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:19:04 by ahugh             #+#    #+#             */
/*   Updated: 2020/12/27 02:22:09 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void	print_unit_type_literal(uint unit_type)
{
	if (unit_type & KB)
		ft_putchar('K');
	else if (unit_type & MB)
		ft_putchar('M');
	else if (unit_type & GB)
		ft_putchar('G');
	else if (unit_type & TB)
		ft_putchar('T');
	else if (unit_type & PB)
		ft_putchar('P');
}

void				print_file_size(t_file *file, uint16_t opt, t_columns *c)
{
	uint			unit_type;
	float			file_size;

	file_size = (float)(file->size);
	if (file->size < BLOCK_SIZE || !(opt & OPT_LOWER_H))
	{
		ft_printf("%*zu", c->w_size, file->size);
		return ;
	}
	unit_type = 1;
	while (file_size >= BLOCK_SIZE && !(unit_type & PB))
	{
		file_size /= BLOCK_SIZE;
		unit_type <<= 1;
	}
	ft_printf("%*.1f", c->w_size - 1, file_size);
	print_unit_type_literal(unit_type);
}

int					get_file_size_width(t_file *file, uint16_t opt)
{
	uint			unit_type;
	float			file_size;
	int				width;

	file_size = (float)(file->size);
	if (file->size < BLOCK_SIZE || !(opt & OPT_LOWER_H))
		return (ft_nbrlen(file->size));
	unit_type = 1;
	while (file_size >= BLOCK_SIZE && !(unit_type & PB))
	{
		file_size /= BLOCK_SIZE;
		unit_type <<= 1;
	}
	width = 4;
	while ((file_size /= 10) >= 1)
		width++;
	return (width);
}
