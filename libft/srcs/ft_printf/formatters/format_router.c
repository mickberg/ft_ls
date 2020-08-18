/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_router.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:47:34 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/06 16:09:48 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_router(t_format *info, t_output *out, va_list ap)
{
	void	(*funcs[256])(t_format*, t_output*, va_list);

	funcs[0] = NULL;
	funcs[1] = format_int;
	funcs[2] = format_octal;
	funcs[3] = format_uint;
	funcs[4] = format_hex;
	funcs[5] = format_hex;
	funcs[6] = format_float;
	funcs[7] = format_char;
	funcs[8] = format_str;
	funcs[9] = format_ptr;
	funcs[10] = format_perc;
	funcs[11] = format_bin;
	if (funcs[info->specifier])
		(funcs[info->specifier])(info, out, ap);
}
