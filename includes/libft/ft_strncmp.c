/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:19:58 by slindgre          #+#    #+#             */
/*   Updated: 2019/01/15 18:24:16 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	c1 = *s1;
	c2 = *s2;
	if (!n)
		return (0);
	while ((c1 == c2) && n--)
	{
		if (c1 == '\0' && c2 == '\0')
			return (0);
		c1 = *s1++;
		c2 = *s2++;
	}
	return (c1 - c2);
}
