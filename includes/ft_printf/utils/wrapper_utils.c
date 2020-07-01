/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 05:49:54 by gloras-t          #+#    #+#             */
/*   Updated: 2019/05/03 05:50:51 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_update_value(char **s1, char *s2)
{
	char	*tmp;

	tmp = *s1;
	free(tmp);
	*s1 = ft_strdup(s2);
	free(s2);
}

void	ft_join_prefix_wrapper(char **s1, char *s2)
{
	char	*tmp;

	if (*s1)
	{
		tmp = *s1;
		*s1 = ft_strjoin(s2, *s1);
		free(tmp);
	}
	else
		*s1 = ft_strdup(s2);
	free(s2);
}

void	ft_join_wrapper(char **s1, char *s2)
{
	char	*tmp;

	if (*s1)
	{
		tmp = *s1;
		*s1 = ft_strjoin(*s1, s2);
		free(tmp);
	}
	else
		*s1 = ft_strdup(s2);
	free(s2);
}
