/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:26:02 by slindgre          #+#    #+#             */
/*   Updated: 2020/10/04 01:16:22 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap_arr_elems(t_list **a, t_list **b)
{
	t_list *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		sort_paths(t_list *a, t_list *b)
{
	return (ft_strcmp(a->content, b->content));
}

int		sort_files(t_list *a, t_list *b)
{
	t_file *a_file;
	t_file *b_file;

	a_file = (t_file*)a->content;
	b_file = (t_file*)b->content;
	return (ft_strcmp(a_file->name, b_file->name));
}

void	quick_sort(t_list **list_arr, int low, int high,
					int (*sort)(t_list*, t_list*))
{
	int		i;
	int		j;
	t_list	*mid;

	if (high - low == 0)
		return ;
	i = low;
	j = high;
	mid = list_arr[(high + low) / 2];
	while (i <= j)
	{
		while (sort(list_arr[i], mid) < 0 && i < high)
			i++;
		while (sort(list_arr[j], mid) > 0)
			j--;
		if (i <= j)
			swap_arr_elems(&list_arr[i++], &list_arr[j--]);
	}
	if (low < i - 1)
		quick_sort(list_arr, low, i - 1, sort);
	if (i < high)
		quick_sort(list_arr, i, high, sort);
}

void	sort_list(t_list **list, int (*sort)(t_list*, t_list*))
{
	t_list	**list_arr;
	t_list	*tmp;
	size_t	size;
	size_t	i;

	if (list == NULL || *list == NULL)
		return ;
	size = ft_lstsize(*list);
	list_arr = (t_list**)malloc(sizeof(t_list*) * size);
	tmp = *list;
	i = 0;
	while (tmp)
	{
		list_arr[i++] = tmp;
		tmp = tmp->next;
	}
	quick_sort(list_arr, 0, size - 1, sort);
	while (i > 1)
	{
		list_arr[size - i]->next = list_arr[size - i + 1];
		i--;
	}
	list_arr[size - 1]->next = NULL;
	*list = list_arr[0];
	free(list_arr);
}
