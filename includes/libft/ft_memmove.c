/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:03:09 by slindgre          #+#    #+#             */
/*   Updated: 2018/12/01 14:45:04 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*p;
	const char	*s;
	size_t		n;

	n = len;
	p = dst;
	s = src;
	if (src < dst)
		while (n--)
			*(p + n) = *(s + n);
	else
		while (n--)
			*p++ = *s++;
	return (dst);
}
