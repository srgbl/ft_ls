/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 05:34:42 by gloras-t          #+#    #+#             */
/*   Updated: 2019/05/03 05:41:54 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	ft_increase_hex(char c)
{
	if (c == '9')
		c = 'a';
	else
		c = c + 1;
	return (c);
}

void	ft_round_a_helper(char **str, size_t k, t_format *data)
{
	while ((*str)[k - 1] != '.' && ((*str)[k] > 'f'))
	{
		(*str)[k] = '0';
		k--;
		(*str)[k] = ft_increase_hex((*str)[k]);
	}
	if ((*str)[2] > 'f' || ((*str)[2] >= '8' && data->precision == 0))
	{
		(*str)[2] = '0';
		(*str)[0] = ft_increase_hex((*str)[0]);
	}
}

int		ft_round_a(t_format *data)
{
	size_t	k;
	char	*str;

	str = data->value;
	if (ft_strlen(str) <= data->precision + 2)
		return (0);
	k = data->precision + 2;
	if (str[k - 1] != '.' && (str[k] > '8' ||
		(str[k] == '8' && (ft_strchr(BASE_16, str[k + 1]) - BASE_16) % 2)))
		str[k - 1] = ft_increase_hex(str[k - 1]);
	k--;
	ft_round_a_helper(&str, k, data);
	str[data->precision + 2] = '\0';
	if (str[0] > 'f')
	{
		if (data->size[0] == 'L')
			str[0] = '1';
		else
			str[0] = 'f';
		ft_transform_exp_helper(data, 4);
	}
	return (1);
}
