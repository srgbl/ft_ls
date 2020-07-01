/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:07:27 by slindgre          #+#    #+#             */
/*   Updated: 2018/12/05 15:44:14 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*temp;

	dup = (char*)malloc(ft_strlen(s1) + 1);
	if (dup)
	{
		temp = dup;
		while (*s1)
			*temp++ = *s1++;
		*temp = '\0';
		return (dup);
	}
	else
		return (NULL);
}
