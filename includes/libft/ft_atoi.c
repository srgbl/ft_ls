/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 17:50:49 by slindgre          #+#    #+#             */
/*   Updated: 2019/05/17 20:08:44 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					neg;
	unsigned long long	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f' ||
	str[i] == '\r' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		neg = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	if ((res > 9223372036854775807) && neg == 1)
		return (-1);
	if ((res - 1 > 9223372036854775807) && neg == -1)
		return (0);
	return (neg * res);
}
