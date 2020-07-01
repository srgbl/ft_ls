/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:46:13 by slindgre          #+#    #+#             */
/*   Updated: 2019/08/03 02:45:42 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_check_inf(t_format *data, t_float fl)
{
	char	*res;

	res = NULL;
	if (fl.t_fl.expon == 0x7FFF && (!fl.t_fl.mant || fl.t_fl.mant == B63))
		res = ft_strdup("inf");
	else if (fl.t_fl.expon == 0x7FFF && fl.t_fl.mant)
	{
		res = ft_strdup("nan");
		if (ft_is_flag(data->flag))
		{
			data->flag['+'] = '\0';
			data->flag[' '] = '\0';
			data->flag['0'] = '\0';
		}
	}
	else if (!fl.t_fl.expon && !fl.t_fl.mant)
		res = ft_strdup("0.");
	if (ft_strcmp(res, "nan"))
		data->sign = fl.t_fl.sign;
	return (res);
}

void	ft_foo_float_f(t_format *data, U128 expon, U128 fract, LL len)
{
	char *tmp;

	tmp = ft_exp_to_str(expon, len);
	ft_join_wrapper(&tmp, ft_strdup("."));
	ft_join_wrapper(&tmp, ft_fract_to_str(fract, len));
	ft_update_value(&data->value, tmp);
}

void	ft_fage_capitalize(t_format *data)
{
	if (ft_strchr("FEGA", data->type) && data->value)
		ft_strtoupper(data->value);
}

void	ft_foo_float_fge(t_format *data, U128 expon, U128 fract, LL len)
{
	int	prec;
	int elen;

	prec = data->precision;
	if (ft_strchr("fF", data->type))
		ft_foo_float_f(data, expon, fract, len);
	else if (ft_strchr("eE", data->type))
		ft_foo_float_e(data, expon, fract, len);
	else if (ft_strchr("gG", data->type))
	{
		elen = ft_foo_float_e(data, expon, fract, len);
		prec = (!data->dot) ? DEF_PREC_F : prec;
		data->precision = (prec) ? prec - 1 : 0;
		ft_round_double(data);
		elen += ft_strchr(data->value, '.') - data->value - 1;
		ft_transform_exp(data);
		if ((prec > elen && elen >= -4) || !ft_strcmp(data->value, "0."))
		{
			ft_foo_float_f(data, expon, fract, len);
			data->precision = prec - elen - 1;
			free(data->exp);
			data->exp = NULL;
		}
	}
}

void	ft_foo_float(t_format *data, va_list ap)
{
	t_float	fl;
	LL		len;
	U128	expon;
	U128	fract;

	fl.ldata = 0;
	if (data->size[0] == 'L')
		fl.data = (long double)va_arg(ap, long double);
	else
		fl.data = (long double)va_arg(ap, double);
	data->value = ft_check_inf(data, fl);
	if (!(data->value) || !ft_strcmp(data->value, "0."))
	{
		len = (int)((int)fl.t_fl.expon - 0x3FFF);
		fract = fl.t_fl.mant;
		expon = 0;
		if (len >= 0)
		{
			expon = fl.t_fl.mant >> (len > 63 ? 0 : (63 - len));
			fract = (len >= 63) ? 0 : fl.t_fl.mant & ((U128)(~0) >> (65 + len));
		}
		ft_foo_float_a(data, fl, len);
		ft_foo_float_fge(data, expon, fract, len);
	}
}
