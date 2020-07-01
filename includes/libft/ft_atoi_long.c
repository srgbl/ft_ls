/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 21:40:16 by slindgre          #+#    #+#             */
/*   Updated: 2019/09/20 11:10:21 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi_long(char **line, int *err)
{
	int					i;
	int					neg;
	unsigned long long	res;
	char				*str;

	i = 0;
	res = 0;
	str = *line;
	while (ft_isspace(str[i]))
		i++;
	neg = (str[i] == '-') ? -1 : 1;
	i += (str[i] == '-' || str[i] == '+') ? 1 : 0;
	*err = ft_isdigit(str[i]) ? 0 : 1;
	while (ft_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	if (!(ft_isspace(str[i]) || str[i] == '\n' || str[i] == '\0'))
		*err = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	*line = *line + i;
	if ((res > 9223372036854775807) && neg == 1)
		return (-1);
	if ((res - 1 > 9223372036854775807) && neg == -1)
		return (0);
	return (neg * res);
}

long	ft_atoi_long_strict(char **line, int *err)
{
	int					i;
	int					neg;
	unsigned long long	res;
	char				*str;

	i = 0;
	res = 0;
	str = *line;
	neg = (str[i] == '-') ? -1 : 1;
	i += (str[i] == '-' || str[i] == '+') ? 1 : 0;
	*err = ft_isdigit(str[i]) ? 0 : 1;
	while (ft_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	*line = *line + i;
	if ((res > 9223372036854775807) && neg == 1)
		return (-1);
	if ((res - 1 > 9223372036854775807) && neg == -1)
		return (0);
	return (neg * res);
}
