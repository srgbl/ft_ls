/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_exp_to_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:05:09 by slindgre          #+#    #+#             */
/*   Updated: 2019/05/03 04:59:17 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

U128	ft_get_bit(U128 n, int i)
{
	U128	b;

	if (i > 64)
		b = 0;
	else
		b = (n & (U128)1 << (63 - i)) ? 1 : 0;
	return (b);
}

char	*ft_double_dabble(U128 n, int len)
{
	int		i;
	int		j;
	char	*res;

	i = -1;
	res = ft_strnew(len / 3 + 2);
	while (++i <= len)
	{
		j = -1;
		while (res[++j])
			res[j] += ((res[j] - '0') > 4) ? 3 : 0;
		if (j)
		{
			res[j] = ((res[j - 1] - '0') > 7) ? '1' : 0;
			j--;
		}
		while (j > 0)
		{
			res[j] = ((((res[j] - '0') << 1) & 15) | ((res[j - 1] - '0') > 7));
			res[j] += '0';
			j--;
		}
		res[j] = ((((res[j] - '0') << 1) & 15) | ft_get_bit(n, i)) + '0';
	}
	return (res);
}

char	*ft_exp_to_str(U128 expon, int len)
{
	char	*res;

	if (len >= 0)
	{
		while (!(((U128)1 << 63) & expon))
			expon <<= 1;
		res = ft_double_dabble(expon, len);
		res = ft_strrev(res, ft_strlen(res));
	}
	else
		res = ft_strdup("0");
	return (res);
}
