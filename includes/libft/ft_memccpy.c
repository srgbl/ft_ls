/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:03:09 by slindgre          #+#    #+#             */
/*   Updated: 2018/12/01 14:38:17 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*p;
	const unsigned char		*s;

	p = dst;
	s = src;
	while (n--)
	{
		*p = *s;
		if (*s == (unsigned char)c)
			return (p + 1);
		p++;
		s++;
	}
	return (NULL);
}
