/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:40:27 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/26 16:46:54 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace_char(char *str, char a, char b)
{
	int	index;

	index = ft_strchrind(str, a);
	str[index] = b;
}
