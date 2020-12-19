/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:26:02 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/19 19:52:19 by slindgre         ###   ########.fr       */
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

void	quick_sort(t_list **list_arr, int low, int high,
					int (*comparator)(t_list*, t_list*))
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
		while (comparator(list_arr[i], mid) < 0 && i < high)
			i++;
		while (comparator(list_arr[j], mid) > 0)
			j--;
		if (i <= j)
			swap_arr_elems(&list_arr[i++], &list_arr[j--]);
	}
	if (low < i - 1)
		quick_sort(list_arr, low, i - 1, comparator);
	if (i < high)
		quick_sort(list_arr, i, high, comparator);
}

void	sort_list_by(t_list **list, int (*comparator)(t_list*, t_list*))
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
	quick_sort(list_arr, 0, size - 1, comparator);
	while (i > 1)
	{
		list_arr[size - i]->next = list_arr[size - i + 1];
		i--;
	}
	list_arr[size - 1]->next = NULL;
	*list = list_arr[0];
	free(list_arr);
}

void	sort_list(t_list **list, uint8_t options)
{
	int (*comparator)(t_list*, t_list*);

	comparator = compare_by_name_asc;
	if (options & OPT_LOWER_R)
		comparator = compare_by_name_desc;
	if (options & OPT_LOWER_T)
	{
		comparator = compare_by_time_asc;
		if (options & OPT_LOWER_R)
			comparator = compare_by_time_desc;
	}
	sort_list_by(list, comparator);
}
