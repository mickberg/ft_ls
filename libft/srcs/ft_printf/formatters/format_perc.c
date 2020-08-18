/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_perc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:56:31 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/05 20:01:11 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_perc(t_format *info, t_output *out, va_list ap)
{
	char	*argstr;

	(void)ap;
	argstr = "%";
	info->precision = 0;
	format_width(info, out, argstr, "");
}
