/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:25:07 by gloras-t          #+#    #+#             */
/*   Updated: 2019/04/18 17:44:27 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strchrind(char *s, char c)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == c)
				return (i);
			i++;
		}
	}
	return (-1);
}
