/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:57:11 by gloras-t          #+#    #+#             */
/*   Updated: 2020/07/01 22:13:21 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

#include <dirent.h>

# define DIRENT	struct dirent

int ft_printf(const char *restrict format, ...);
int foo();

#endif