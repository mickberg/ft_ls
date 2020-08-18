/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:05:36 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/05 20:02:33 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_char(t_format *info, t_output *out, va_list ap)
{
	char	arg;
	char	argstr[2];

	info->flags &= ~(FLAG_POUND | FLAG_PLUS | FLAG_SPACE);
	info->precision = 1;
	arg = number_argument_unsigned(len_char, ap);
	ft_memset(argstr, '\0', 2);
	argstr[0] = arg;
	format_width(info, out, argstr, "");
}
