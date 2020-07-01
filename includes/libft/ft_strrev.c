/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:30:07 by slindgre          #+#    #+#             */
/*   Updated: 2019/05/17 20:19:00 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str, int len)
{
	int		i;
	char	c;

	i = 0;
	while (i < len--)
	{
		c = str[i];
		str[i] = str[len];
		str[len] = c;
		i++;
	}
	return (str);
}
