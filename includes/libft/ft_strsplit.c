/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:57:45 by slindgre          #+#    #+#             */
/*   Updated: 2019/01/17 16:03:15 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_len(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		m;
	char	**res;

	if (!s || !(res = (char **)malloc(sizeof(char*) *
		(ft_count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_count_words(s, c))
	{
		m = 0;
		if (!(res[i] = ft_strnew(ft_word_len(&s[j], c) + 1)))
			res[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			res[i][m++] = s[j++];
		res[i][m] = '\0';
		i++;
	}
	res[i] = 0;
	return (res);
}
