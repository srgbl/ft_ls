/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 05:26:32 by gloras-t          #+#    #+#             */
/*   Updated: 2019/07/27 23:19:27 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		ft_check_zeroes(char *str)
{
	while (*str)
	{
		if (*str != '0')
			return (1);
		str++;
	}
	return (0);
}

int		ft_round_double_check(char *dot, t_format *data)
{
	if (*(dot - 1) == '.' && ((*dot > '9')
			|| ((*dot > '5') && data->precision == 0)
			|| (*dot == '5' && (ft_check_zeroes(dot + 1)
			|| (*(dot - 2) % 2 && data->precision == 0)))))
		return (1);
	return (0);
}

void	ft_round_to_border(char **finder, char **border, int i, char c)
{
	char *str;

	str = *finder;
	if (str != *border && (str - 1) != *border)
	{
		*str = c;
		str -= i;
		*str += 1;
	}
	while (*str - '0' > 9 && str != *border && *(str - 1) != '.')
	{
		*str = '0';
		*(str - 1) += 1;
		str--;
	}
	*finder = str;
}

int		ft_round_double(t_format *data)
{
	char	*dot;
	char	*tmp;

	tmp = ft_strchr(data->value, '.');
	if (!tmp || (ft_strlen(data->value) - (tmp - data->value) - 1)
		<= data->precision)
		return (0);
	dot = tmp + data->precision + 1;
	if (*dot && (*dot > '5' ||
		(*dot == '5' && (ft_check_zeroes(dot + 1) || (*(dot - 1) == '.'
		&& *(dot - 2) % 2) || (*(dot - 1) != '.' && *(dot - 1) % 2)))))
	{
		ft_round_to_border(&dot, &tmp, 1, '\0');
		if (ft_round_double_check(dot, data))
			ft_round_to_border(&dot, &(data->value), 2, '0');
		if (*dot > '9')
		{
			*dot = '0';
			ft_update_value(&data->value, ft_strjoin("1", dot));
		}
		*(tmp + data->precision + 1) = '\0';
	}
	else
		*dot = '\0';
	return (1);
}
