/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:56:20 by slindgre          #+#    #+#             */
/*   Updated: 2019/05/03 14:19:29 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_bit_to_hex(U128 n)
{
	int		i;
	char	*res;

	i = 0;
	res = ft_strnew(15);
	while (i < 15)
	{
		res[i] = ((((U128)15 << (60 - i * 4)) & n) >> (60 - i * 4)) + '0';
		if (res[i] > '9')
			res[i] = (res[i] - '0') % 10 + 'a';
		i++;
	}
	return (res);
}

char	*ft_a_first_digit(t_format *data, uint64_t *mant, LL *len)
{
	char	*res;

	if (*len == -0x3FFF)
	{
		while (!(*mant & B63) && *mant)
		{
			*mant <<= 1;
			*len = *len - 1;
		}
		*len += 1;
	}
	*mant = *mant | B63;
	res = ft_strdup("1.");
	if (data->size[0] == 'L')
	{
		res[0] = ((((U128)15 << 60) & *mant) >> 60) + '0';
		if (res[0] > '9')
			res[0] = (res[0] - '0') % 10 + 'a';
		*mant = *mant << 3;
		*len = *len - 3;
	}
	*mant = *mant << 1;
	return (res);
}

void	ft_foo_float_a(t_format *data, t_float fl, LL len)
{
	char		*res;
	uint64_t	mant;

	mant = fl.t_fl.mant;
	if (ft_strchr("aA", data->type))
	{
		if (!fl.t_fl.mant && !fl.t_fl.expon)
			data->exp = ft_strdup("p+0");
		else
		{
			res = ft_a_first_digit(data, &mant, &len);
			ft_join_wrapper(&res, ft_bit_to_hex(mant));
			ft_update_value(&data->value, res);
			res = ft_strdup("p");
			ft_join_wrapper(&res, (len >= 0) ? ft_strdup("+") : ft_strdup("-"));
			ft_join_wrapper(&res, ft_itoa_base(ft_int_abs(len), 10));
			ft_update_value(&data->exp, res);
		}
	}
}
