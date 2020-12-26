/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:19:04 by ahugh             #+#    #+#             */
/*   Updated: 2020/12/26 21:31:02 by ahugh            ###   ########.fr       */
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

void				print_file_size(t_file *file)
{
	uint			unit_type;
	float			file_size;

	file_size = (float)(file->size);
	if (file_size < BLOCK_SIZE)
	{
		ft_printf("%zu", file_size);
		return ;
	}
	unit_type = 1;
	while (file_size > BLOCK_SIZE && !(unit_type & PB))
	{
		file_size /= BLOCK_SIZE;
		unit_type <<= 1;
	}
	ft_printf("%.1f", file_size);
	print_unit_type_literal(unit_type);
}
