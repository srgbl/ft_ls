/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:33:22 by slindgre          #+#    #+#             */
/*   Updated: 2020/07/04 18:56:14 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_free_elem(void *elem, size_t content_size)
{
	ft_bzero(elem, content_size);
	ft_memdel(&elem);
}
