/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:09:38 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/05 20:03:44 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_hex(t_format *info, t_output *out, va_list ap)
{
	t_u64	arg;
	char	*argstr;
	char	prefix[3];
	int		hexup;

	info->flags &= ~(FLAG_PLUS | FLAG_SPACE);
	info->flags &= ~(FLAG_ZERO * info->has_precision);
	info->precision += !info->has_precision;
	arg = number_argument_unsigned(info->length, ap);
	if (arg == 0)
		info->flags &= ~FLAG_POUND;
	hexup = info->specifier == spec_hexup;
	if (!(argstr = base_conversion(arg, 16, hexup, info->precision)))
		return ;
	ft_memset(prefix, 0, 3);
	if (info->flags & FLAG_POUND)
	{
		if (info->specifier == spec_hexup)
			ft_strncpy(prefix, "0X", 2);
		else
			ft_strncpy(prefix, "0x", 2);
	}
	format_width(info, out, argstr, prefix);
	free(argstr);
}
