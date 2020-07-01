/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:31:03 by slindgre          #+#    #+#             */
/*   Updated: 2019/11/13 00:25:35 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <wchar.h>
# include <locale.h>
# include <stdint.h>
# include "../libft/libft.h"

# define UI				unsigned int
# define UL				unsigned long
# define LL				long long
# define ULL			unsigned long long
# define U128			__uint128_t
# define B63			0x8000000000000000
# define DEF_PREC_F		6
# define DEF_PREC_D		1
# define DEF_PREC_A		15

# define FLAGS			"-+ '#0"
# define TYPES			"_%aAbBdDiuUoOxXfFeEgGcCsSnp"
# define TYPES_INTEGER	"bBdDiuUoOxX"
# define DIGITS			"0123456789"
# define SIZES			"hljzLH"
# define BASE_16		"0123456789abcdef"
# define TYPES_ALIAS	"BDOUCS"
# define SIGN_INT_TYPE	"diaAeEfFgG"
# define FLOAT_TYPES	"aAeEgGfF"

# define COLOR_NUMBER	7

# define COLOR_RED		"\033[0;31m"
# define COLOR_GREEN	"\033[0;32m"
# define COLOR_YELLOW	"\033[0;33m"
# define COLOR_BLUE		"\033[0;34m"
# define COLOR_MAGENTA	"\033[0;35m"
# define COLOR_CYAN		"\033[0;36m"
# define COLOR_EOC		"\033[0m"

# define BUF_SIZE		200
# define TABLE_SIZE		21
# define FLAG_SIZE		49

typedef struct			s_line
{
	unsigned char		*line;
	int					length;
	int					amount;
}						t_line;

typedef struct			s_cast
{
	UI					gp_offset;
	UI					fp_offset;
	void				*overflow_arg_area;
	void				*reg_save_area;
}						t_cast[1];

typedef struct			s_format
{
	char				flag[CHAR_MAX];
	UI					width;
	UI					precision;
	char				size[2];
	char				type;
	char				*value;
	char				*exp;
	UI					sign;
	UI					dot;
	UI					null_term;
	UI					arg_index;
	UI					fd;
	t_cast				cast;
	char				check_flag[CHAR_MAX];
	char				check_types[CHAR_MAX];
	char				check_sizes[CHAR_MAX];
	char				check_types_int[CHAR_MAX];
	char				check_types_alias[CHAR_MAX];
	char				check_float_type[CHAR_MAX];
	char				check_signed_int_type[CHAR_MAX];
}						t_format;

typedef	void			(*t_handler)(t_format*, va_list);

typedef	struct			s_table
{
	char				type;
	t_handler			fun;
}						t_table;

typedef union			u_float
{
	long double			data;
	U128				ldata;
	struct				s_fl
	{
		uint64_t		mant:64;
		uint16_t		expon:15;
		uint16_t		sign:1;
	}					t_fl;
}						t_float;

/*
**	utils.c
*/

void					ft_update_value(char **s1, char *s2);
void					ft_join_wrapper(char **s1, char *s2);
void					ft_join_prefix_wrapper(char **s1, char *s2);

/*
**	line_utils.c
*/

t_line					*ft_init_line();
void					ft_update_line_color(t_line *line, char *color);
void					ft_update_line_by_char(t_line *line, char c);
void					ft_free_line(t_line *line);

/*
**	parse_utils_01.c
*/

void					ft_prepare_parse(const char *fmt, t_format *data,
						int *len);
const char				*ft_parse_digit(const char *fmt, int *number,
						int *context);
const char				*ft_dot_treat(const char *fmt, t_format *data,
						int *context);
const char				*ft_digit_treat(const char *fmt, t_format *data,
						int *context, va_list ap);
const char				*ft_asterisk_treat(const char *fmt, t_format *data,
						int *context, va_list ap);

/*
**	parse_utils_02.c
*/

void					ft_set_size(t_format *data, char c);
void					ft_parse(const char *fmt, int *len, t_format *data,
						va_list ap);

/*
**	data_utils.c
*/

t_format				*ft_init_data(va_list ap);
void					ft_reset_data(t_format *data);
void					v(char *dst, char *str);
void					ft_bzero_8_byte(void *s, size_t n);

/*
**	get_arg_utils_01.c
*/

LL						ft_get_long_long(int indx, t_format *data, va_list ap);
UL						ft_get_u_long(int indx, t_format *data, va_list ap);
ULL						ft_get_u_long_long(int ind, t_format *data, va_list ap);
int						ft_get_int(int indx, t_format *data, va_list ap);
void					*ft_get_void_ptr(int indx, t_format *data, va_list ap);

/*
**	get_arg_utils_02.c
*/

long double				ft_get_double(int indx, t_format *data, va_list ap);
long double				ft_get_long_double(int ind, t_format *data, va_list ap);
wchar_t					ft_get_wchar_t(int indx, t_format *data, va_list ap);
wchar_t					*ft_get_wchar_t_ptr(int id, t_format *data, va_list ap);
char					*ft_get_char_ptr(int indx, t_format *data, va_list ap);

/*
**	flag-utils.c
*/

int						ft_is_flag(char *flag);
void					ft_remove_hash(t_format *data);
void					ft_remove_space(t_format *data);
void					ft_remove_zero(t_format *data);
void					ft_remove_plus(t_format *data);

/*
**	transform_utils_01.c
*/

void					ft_transform_width(t_format *data);
void					ft_transform_hash(t_format *data);
void					ft_transform_prefix(t_format *data);
void					ft_transform_sign(t_format *data);

/*
**	transform_utils_02.c
*/

void					ft_transform_type(t_format *data);
void					ft_transform_prec(t_format *data);

/*
**	transform_utils_03.c
*/

void					ft_transform_prec_int(t_format *data);
void					ft_transform_prec_char(t_format *data);

/*
**	arithmetic_utils.c
*/

void					ft_prepare_parse(const char *fmt, t_format *data,
						int *len);
void					ft_abs_int(int *number);
LL						ft_int_abs(LL n);
int						ft_get_base(t_format *data);

/*
**	transform_double.c
*/

int						ft_round_double(t_format *data);

/*
**	transform_a.c
*/

int						ft_round_a(t_format *data);

/*
**	transform_exp.c
*/

t_format				*ft_init_data();
int						ft_printf(const char *restrict format, ...);
void					ft_parse_format(t_format *data, va_list ap);
void					ft_set_flag(t_format *data, char c);
void					ft_set_value_by_context(t_format *data, int context,
						int *number);
void					ft_remove_unused_flags(t_format *data);
void					ft_transform_prec(t_format *data);
void					ft_prepate_to_print(t_format *data);
void					ft_put_wstr(t_line *line, t_format *data);
void					ft_data_output(t_line *line, t_format *data);
void					ft_reset_data(t_format *data);
void					ft_transform_exp_helper(t_format *data, size_t z);
void					ft_transform_exp(t_format *data);

char					ft_get_char(int index, t_format *data, va_list ap);
int						ft_check_in_line(char c, char *line);
void					ft_print_bits(U128 n);
void					ft_foo_fd(t_format *data, va_list ap);
void					ft_foo_int(t_format *data, va_list ap);
void					ft_foo_str(t_format *data, va_list ap);
void					ft_foo_char(t_format *data, va_list ap);
void					ft_foo_ptr(t_format *data, va_list ap);
void					ft_foo_float(t_format *data, va_list ap);
void					ft_foo_float_a(t_format *data, t_float fl, LL len);
int						ft_foo_float_e(t_format *data, U128 expon, U128 fract,
						LL len);
char					*ft_exp_to_str(U128 expon, int len);
char					*ft_fract_to_str(U128 fract, int expon);
char					*ft_itoa_base(ULL n, int base);
void					ft_strtoupper(char *str);
void					ft_remove_zeros(char *str);
size_t					ft_wchar_len(wchar_t c);
size_t					ft_wide_strlen(wchar_t *wstr);
void					ft_fage_capitalize(t_format *data);

int						ft_get_color_index(char *fmt);
void					ft_update_line_by_line(t_line *line, char *str);
void					ft_strsub_utf(t_format *data);

#endif
