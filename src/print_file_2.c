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

static inline void	print_human_readable_size(uint64_t size, t_columns *c, \
											uint width, uint8_t use_precision)
{
	uint			unit_type;
	float			f_size;

	if (size < BLOCK_SIZE || !(c->options & OPT_LOWER_H))
	{
		ft_printf("%*zu", width, size);
		return ;
	}
	f_size = (float)size;
	unit_type = 1;
	while (f_size >= BLOCK_SIZE && !(unit_type & PB))
	{
		f_size /= BLOCK_SIZE;
		unit_type <<= 1;
	}
	ft_printf("%*.*f", width - 1, use_precision, f_size);
	print_unit_type_literal(unit_type);
}

void				print_file_size(t_file *file, t_columns *c)
{
	print_human_readable_size(file->size, c, c->w_size, TRUE);
}

void				print_blocks(uint64_t count, t_columns *c, \
													char *prefix, char *suffix)
{
	uint8_t			use_precision;

	use_precision = ft_nbrlen(count) >= c->w_blocks ? FALSE : TRUE;
	ft_putstr(prefix);
	if (c->options & OPT_LOWER_H)
		print_human_readable_size(count * BLOCK_SIZE, c, \
										c->w_blocks + 1, use_precision);
	else
		print_human_readable_size(count, c, c->w_blocks, use_precision);
	ft_putstr(suffix);
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
