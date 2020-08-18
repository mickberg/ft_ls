/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:22:28 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/05 19:37:00 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_spec	get_spec(char c)
{
	char	specs[256];

	ft_bzero(specs, 256);
	specs['d'] = spec_int;
	specs['i'] = spec_int;
	specs['o'] = spec_octal;
	specs['u'] = spec_uint;
	specs['x'] = spec_hex;
	specs['X'] = spec_hexup;
	specs['f'] = spec_float;
	specs['c'] = spec_char;
	specs['s'] = spec_str;
	specs['p'] = spec_ptr;
	specs['%'] = spec_perc;
	specs['b'] = spec_bin;
	return (specs[(int)c]);
}

void			parse_specifier(t_format *info, const char *format, int *pos)
{
	info->specifier = get_spec(*(char*)(format + (*pos)));
	if (info->specifier)
		++(*pos);
}
