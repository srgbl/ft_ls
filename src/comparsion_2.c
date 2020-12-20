/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparsion_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:49:25 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/20 02:51:28 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		compare_by_size_asc(t_list *a, t_list *b)
{
	t_file *a_file;
	t_file *b_file;

	a_file = (t_file*)a->content;
	b_file = (t_file*)b->content;
	if (a_file->size == b_file->size)
		return (ft_strcmp(a_file->name, b_file->name));
	return (a_file->size < b_file->size ? 1 : -1);
}

int		compare_by_size_desc(t_list *a, t_list *b)
{
	t_file *a_file;
	t_file *b_file;

	a_file = (t_file*)a->content;
	b_file = (t_file*)b->content;
	if (a_file->size == b_file->size)
		return (ft_strcmp(b_file->name, a_file->name));
	return (a_file->size > b_file->size ? 1 : -1);
}
