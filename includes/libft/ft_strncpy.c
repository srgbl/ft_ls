/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 19:28:19 by slindgre          #+#    #+#             */
/*   Updated: 2018/12/05 15:48:02 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = dest;
	while (*src && i++ < n)
		*dest++ = *src++;
	while (i++ < n)
		*dest++ = '\0';
	return (p);
}
