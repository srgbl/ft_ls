/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:17:53 by slindgre          #+#    #+#             */
/*   Updated: 2018/12/05 16:34:34 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	end;
	size_t	start;
	char	*p;
	char	*res;
	char	*t;

	if (s == NULL)
		return (NULL);
	start = 0;
	p = (char*)s;
	end = ft_strlen(s);
	t = (char*)(s + end - 1);
	while ((*t == ' ' || *t == '\n' || *t == '\t') && t--)
		end--;
	while ((*p == ' ' || *p == '\n' || *p == '\t') && p++)
		start++;
	res = ft_strsub(s, start, (end > start) ? (end - start) : 1);
	return (res);
}
