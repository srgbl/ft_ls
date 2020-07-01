/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 23:32:09 by slindgre          #+#    #+#             */
/*   Updated: 2020/05/21 00:02:22 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void		ft_wide_char_to_utf(wchar_t wchar, unsigned char *s, size_t len)
{
	size_t	i;

	i = 0;
	len--;
	while (len - i)
	{
		s[len - i] = ((wchar >> 6 * i) & 63) + 128;
		i++;
	}
	if (len)
		s[0] = (wchar >> 6 * len) + ((~((unsigned int)1)) << (6 - i));
	else
		s[0] = wchar;
	s += len + 1;
}

char		*ft_wstr_to_utf(wchar_t *wstr)
{
	char	*res;
	size_t	str_len;
	size_t	char_len;

	str_len = ft_wide_strlen(wstr);
	res = malloc(str_len + 1);
	res[str_len] = '\0';
	while (*wstr)
	{
		char_len = ft_wchar_len(*wstr);
		ft_wide_char_to_utf(*wstr, (unsigned char *)res, char_len);
		res += char_len;
		wstr++;
	}
	return (res - str_len);
}

void		ft_foo_char(t_format *data, va_list ap)
{
	wchar_t		value;
	char		*res;
	size_t		len;

	if (data->size[0] == 'l')
		value = ft_get_wchar_t(data->arg_index, data, ap);
	else
		value = (char)ft_get_int(data->arg_index, data, ap);
	len = ft_wchar_len(value);
	res = ft_strnew(len);
	ft_wide_char_to_utf(value, (unsigned char *)res, len);
	ft_update_value(&data->value, res);
}

void		ft_foo_str(t_format *data, va_list ap)
{
	char	*tmp;
	wchar_t	*wstr;

	if (data->size[0] == 'l' && data->type == 's')
	{
		wstr = ft_get_wchar_t_ptr(data->arg_index, data, ap);
		if (wstr)
			ft_update_value(&data->value, ft_wstr_to_utf(wstr));
		else
			ft_update_value(&data->value, ft_strdup("(null)"));
	}
	else
	{
		tmp = ft_get_char_ptr(data->arg_index, data, ap);
		if (tmp)
			ft_update_value(&data->value, ft_strdup(tmp));
		else
			ft_update_value(&data->value, ft_strdup("(null)"));
	}
}

void		ft_foo_ptr(t_format *data, va_list ap)
{
	intptr_t	value;

	value = (intptr_t)ft_get_void_ptr(data->arg_index, data, ap);
	if (!(data->dot
		&& data->precision == 0
		&& !value))
		ft_update_value(&data->value, ft_itoa_base(value, 16));
	else
		ft_update_value(&data->value, ft_strdup(""));
}
