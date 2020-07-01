/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:48:43 by slindgre          #+#    #+#             */
/*   Updated: 2018/12/05 16:47:58 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	char	*p;

	if (s == NULL || f == NULL)
		return (NULL);
	if (!(res = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	p = res;
	while (*s)
		*p++ = (f)(*s++);
	*p = '\0';
	return (res);
}
