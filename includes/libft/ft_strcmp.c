/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:19:58 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/27 01:11:23 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*a;
	unsigned char	*b;

	if (!s1 || !s2)
		return (1);
	if (!s1 && !s2)
		return (0);
	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	while (*a)
	{
		if (*a != *b)
			break ;
		a++;
		b++;
	}
	return (*a - *b);
}
