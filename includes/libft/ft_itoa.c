/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:16:45 by slindgre          #+#    #+#             */
/*   Updated: 2019/08/31 19:00:51 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_of_int(long nb)
{
	int	i;

	i = 1;
	while ((nb = nb / 10) > 0)
		i++;
	return (i);
}

char		*ft_itoa(int num)
{
	int		i;
	int		sign;
	char	*str;
	int		len;
	long	nb;

	nb = num;
	sign = 0;
	if (nb < 0)
	{
		nb = -nb;
		sign = 1;
	}
	len = ft_size_of_int(nb) + sign;
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	i = 0;
	str[i] = nb % 10 + '0';
	while ((nb = nb / 10) > 0)
		str[++i] = nb % 10 + '0';
	if (sign)
		str[++i] = '-';
	str[++i] = '\0';
	str = ft_strrev(str, len);
	return (str);
}
