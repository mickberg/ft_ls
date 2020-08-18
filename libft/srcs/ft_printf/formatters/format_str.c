/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:05:36 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/05 20:10:19 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_str(t_format *info, t_output *out, va_list ap)
{
	char	*arg;
	char	*argstr;

	info->flags &= ~(FLAG_POUND | FLAG_PLUS | FLAG_SPACE);
	arg = (char*)va_arg(ap, char*);
	if (arg == NULL)
		arg = "(null)";
	if (!info->has_precision)
		info->precision = ft_strlen(arg);
	if (!(argstr = ft_strndup(arg, info->precision)))
		return ;
	info->precision = 0;
	format_width(info, out, argstr, "");
	free(argstr);
}
