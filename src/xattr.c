/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xattr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 10:12:45 by ahugh             #+#    #+#             */
/*   Updated: 2020/12/27 10:31:35 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline char	free_path_and_return_xattr(char *path, char xattr)
{
	free(path);
	errno = 0;
	return (xattr);
}

char				get_xattr(char *file_name, char *prefix)
{
	char			*path;

	errno = 0;
	path = ft_strjoin(prefix, file_name);
	if (listxattr(path, NULL, 0) < 1 || errno != 0)
		return (free_path_and_return_xattr(path, BASE_XATTR));
	if (getxattr(path, ACL_ACCESS, NULL, 0) > 0 || \
		getxattr(path, ACL_DEFAULT, NULL, 0) > 0)
		return (free_path_and_return_xattr(path, SYSTEM_XATTR));
	return (free_path_and_return_xattr(path, CUSTOM_XATTR));
}
