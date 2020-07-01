/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:01:34 by slindgre          #+#    #+#             */
/*   Updated: 2019/05/03 04:59:13 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_e_first_digit(U128 expon, LL len, LL *e)
{
	char	*res;
	size_t	strlen;

	res = ft_exp_to_str(expon, len);
	strlen = ft_strlen(res);
	*e = strlen - 1;
	while (--strlen)
		res[strlen + 1] = res[strlen];
	res[1] = '.';
	return (res);
}

char	*ft_e_last_digits(U128 fract, LL len, LL *e)
{
	char	*res;
	char	*tmp;

	res = ft_fract_to_str(fract, len);
	tmp = res;
	*e = -1;
	while (*res == '0')
	{
		*e = *e - 1;
		res++;
	}
	*(res - 1) = *res;
	*res = '.';
	res = ft_strsub(res - 1, 0, ft_strlen(res - 1));
	res = ft_strdup(res);
	free(tmp);
	return (res);
}

int		ft_foo_float_e(t_format *data, U128 expon, U128 fract, LL len)
{
	char	*res;
	char	*tmp;
	LL		e;

	e = 0;
	if (len >= 0)
	{
		res = ft_e_first_digit(expon, len, &e);
		ft_join_wrapper(&res, ft_fract_to_str(fract, len));
	}
	else if (fract)
		res = ft_e_last_digits(fract, len, &e);
	else
		res = ft_strdup("0.");
	data->value = ft_strdup(res);
	free(res);
	res = ft_strdup((e < 0) ? "e-" : "e+");
	if (!(e / 10))
		ft_join_wrapper(&res, ft_strdup("0"));
	tmp = ft_itoa_base(ft_int_abs(e), 10);
	ft_join_wrapper(&res, tmp);
	data->exp = res;
	return (e);
}
