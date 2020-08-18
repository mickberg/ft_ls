/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 08:25:58 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/06 16:08:28 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_format(const char *format, t_output *out, int *pos, va_list ap)
{
	t_format	info;

	ft_bzero(&info, sizeof(t_format));
	parse_flags(&info, format, pos);
	parse_width(&info, format, pos, ap);
	parse_precision(&info, format, pos, ap);
	parse_length(&info, format, pos);
	parse_specifier(&info, format, pos);
	if (info.specifier == spec_none)
		return ;
	if (info.flags & FLAG_MINUS)
		info.flags &= ~FLAG_ZERO;
	format_router(&info, out, ap);
}
