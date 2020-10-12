/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:49:25 by gloras-t          #+#    #+#             */
/*   Updated: 2020/10/13 01:04:33 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_files_by_name_asc(t_list *a, t_list *b)
{
	t_file *a_file;
	t_file *b_file;

	a_file = (t_file*)a->content;
	b_file = (t_file*)b->content;
	return (ft_strcmp(a_file->name, b_file->name));
}

int		sort_files_by_time_asc(t_list *a, t_list *b)
{
	t_file *a_file;
	t_file *b_file;

	a_file = (t_file*)a->content;
	b_file = (t_file*)b->content;
	if (a_file->last_modified == b_file->last_modified)
		return (0);
	return (a_file->last_modified < b_file->last_modified ? 1 : -1);
}

int		sort_files_by_name_desc(t_list *a, t_list *b)
{
	t_file *a_file;
	t_file *b_file;

	a_file = (t_file*)a->content;
	b_file = (t_file*)b->content;
	return (!ft_strcmp(a_file->name, b_file->name));
}

int		sort_files_by_time_desc(t_list *a, t_list *b)
{
	t_file *a_file;
	t_file *b_file;

	a_file = (t_file*)a->content;
	b_file = (t_file*)b->content;
	if (a_file->last_modified == b_file->last_modified)
		return (0);
	return (a_file->last_modified > b_file->last_modified ? 1 : -1);
}
