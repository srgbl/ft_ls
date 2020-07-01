/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_exp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 05:32:25 by gloras-t          #+#    #+#             */
/*   Updated: 2019/05/03 05:32:59 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_transform_exp_helper(t_format *data, size_t z)
{
	int		i;
	int		n;
	char	*expon;

	i = ft_strchr(data->exp, '-') ? -1 : 1;
	n = ft_atoi(data->exp + 2) + i * z;
	expon = ft_itoa(n);
	if (ft_strlen(expon) == ft_strlen(data->exp + 2))
		ft_strcpy(data->exp + 2, expon);
	else if (ft_strlen(expon) > ft_strlen(data->exp + 2))
	{
		*(data->exp + 2) = '\0';
		ft_join_wrapper(&data->exp, expon);
	}
	else if (ft_strlen(expon) > 1)
		ft_strcpy(data->exp + 2, expon);
	else
	{
		*(data->exp + 2) = '0';
		ft_strcpy(data->exp + 3, expon);
	}
}

void	ft_transform_exp(t_format *data)
{
	char	*res;

	if (data->exp && ft_strchr("eE", *(data->exp)))
	{
		res = data->value;
		if (res[1] != '.')
		{
			res[2] = res[1];
			res[1] = '.';
			res[ft_strlen(res) - 1] = '\0';
			ft_transform_exp_helper(data, 1);
		}
	}
}
