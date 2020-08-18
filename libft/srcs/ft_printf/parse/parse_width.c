/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 09:25:42 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/03 16:00:37 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width(t_format *info, const char *format, int *pos, va_list ap)
{
	int		argwidth;

	if (*(format + *pos) == '*')
	{
		argwidth = (int)va_arg(ap, int);
		if (argwidth < 0)
			info->flags |= FLAG_MINUS;
		info->width = ft_abs(argwidth);
		(*pos)++;
	}
	if (ft_isdigit(*(format + *pos)))
		parse_number(format, pos, &(info->width));
}
