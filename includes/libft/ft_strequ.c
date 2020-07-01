/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:09:45 by slindgre          #+#    #+#             */
/*   Updated: 2018/12/05 15:45:11 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(const char *s1, const char *s2)
{
	unsigned char	c1;
	unsigned char	c2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	c1 = *s1;
	c2 = *s2;
	while (c1 == c2)
	{
		if (c1 == '\0' && c2 == '\0')
			return (1);
		c1 = *s1++;
		c2 = *s2++;
	}
	return (0);
}
