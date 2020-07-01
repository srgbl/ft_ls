/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 05:45:24 by gloras-t          #+#    #+#             */
/*   Updated: 2019/05/03 05:49:25 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_abs_int(int *number)
{
	if (*number < 0)
		*number *= -1;
}

LL		ft_int_abs(LL n)
{
	if (n < 0)
		n = -(n);
	return (n);
}

int		ft_get_base(t_format *data)
{
	int	base;

	base = 10;
	if (data->type == 'o' || data->type == 'O')
		base = 8;
	else if (data->type == 'x' || data->type == 'X')
		base = 16;
	else if (data->type == 'b' || data->type == 'B')
		base = 2;
	return (base);
}
