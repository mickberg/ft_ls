/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 23:45:01 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/06 16:22:59 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_width(t_format *info, t_output *out, char *argstr, char *prefix)
{
	size_t	pos;
	size_t	arglen;
	size_t	prefix_len;
	char	width_char;

	prefix_len = ft_strlen(prefix);
	arglen = ft_strlen(argstr);
	if (info->specifier == spec_char)
		arglen = 1;
	out->len = ft_max(arglen + prefix_len, info->width);
	if (!(out->string = ft_strnew(out->len)) &&
			(out->len = 0) == 0)
		return ;
	width_char = 48 - !(info->flags & FLAG_ZERO) * 16;
	pos = (out->len - arglen);
	if (info->flags & FLAG_MINUS)
		pos = prefix_len;
	ft_strncpy(out->string + pos, argstr, arglen);
	ft_memset(out->string, width_char, pos);
	ft_memset(out->string + pos + arglen, width_char, \
		out->len - (pos + arglen));
	pos -= prefix_len;
	if (info->flags & FLAG_ZERO)
		pos = 0;
	ft_strncpy(out->string + pos, prefix, prefix_len);
}
