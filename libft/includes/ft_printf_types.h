/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 07:54:13 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/06 16:25:16 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPES_H
# define FT_PRINTF_TYPES_H

# include <stdlib.h>

typedef struct s_format		t_format;
typedef struct s_output		t_output;
typedef enum e_length		t_len;
typedef enum e_spec			t_spec;
typedef long long			t_64;
typedef long double			t_f128;
typedef unsigned long long	t_u64;

# define FLAG_MINUS			0x01
# define FLAG_PLUS			0x02
# define FLAG_POUND			0x04
# define FLAG_ZERO			0x08
# define FLAG_SPACE			0x10

enum						e_length
{
	len_none,
	len_char,
	len_short,
	len_long,
	len_longlong,
	len_longdouble,
};

enum						e_spec
{
	spec_none,
	spec_int,
	spec_octal,
	spec_uint,
	spec_hex,
	spec_hexup,
	spec_float,
	spec_char,
	spec_str,
	spec_ptr,
	spec_perc,
	spec_bin
};

struct						s_format
{
	char		flags;
	int			width;
	int			precision;
	int			has_precision;
	t_len		length;
	t_spec		specifier;
};

struct						s_output
{
	char		*string;
	size_t		len;
};

#endif
