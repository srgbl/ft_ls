/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_fract_to_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:06:01 by slindgre          #+#    #+#             */
/*   Updated: 2019/05/03 04:59:20 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_mult_digit_arb(char *res, size_t n)
{
	size_t	i;
	size_t	len;
	int		*arr;

	len = ft_strlen(res);
	arr = (int*)ft_memalloc(sizeof(int) * (len + 1));
	i = 0;
	while (i < len)
	{
		arr[i] = (res[i] - '0') * n;
		i++;
	}
	i = 0;
	while (i < len)
	{
		arr[i + 1] += arr[i] / 10;
		arr[i] = arr[i] % 10;
		i++;
	}
	len += (arr[i] > 0) ? 1 : 0;
	i = -1;
	while (++i < len)
		res[i] = arr[i] + '0';
	free(arr);
}

char	*ft_pow_digit_arb(size_t n, size_t power)
{
	char	*res;
	size_t	i;

	i = 0;
	res = ft_strnew(power + 64);
	res[0] = '1';
	while (i++ < power)
		ft_mult_digit_arb(res, n);
	return (res);
}

char	*int_arr_to_decimal(int *arr, size_t len)
{
	char	*res;
	size_t	i;

	res = ft_strnew(len + 1);
	i = 0;
	len--;
	while (i < len)
	{
		arr[len - i - 1] += arr[len - i] / 10;
		arr[len - i] = arr[len - i] % 10;
		i++;
	}
	i = 0;
	while (i <= len)
	{
		res[i] = arr[i] + '0';
		i++;
	}
	free(arr);
	return (res);
}

char	*ft_fract_to_str(U128 fract, int expon)
{
	char	*pow_of_five;
	int		i;
	int		*arr;

	if (expon >= 63 || !fract)
		return (ft_strdup("0"));
	fract <<= (64 + ((expon < 0) ? 0 : (expon + 1)));
	expon += (expon == -16383) ? 1 : 0;
	expon = (expon >= 0) ? 1 : -expon;
	arr = (int*)ft_memalloc((sizeof(int) * (80 + expon)));
	pow_of_five = ft_pow_digit_arb(5, expon);
	while (fract)
	{
		i = -1;
		if (((U128)1 << 127) & fract)
			while (++i < expon && pow_of_five[i])
				arr[expon - i - 1] += pow_of_five[i] - '0';
		expon++;
		ft_mult_digit_arb(pow_of_five, 5);
		fract <<= 1;
	}
	free(pow_of_five);
	return (int_arr_to_decimal(arr, expon - 1));
}
