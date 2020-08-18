/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:56:35 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/09 14:42:51 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		len;

	va_start(ap, format);
	len = ft_vprintf(format, ap);
	va_end(ap);
	return (len);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	size_t		len;

	va_start(ap, format);
	len = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (len);
}

int			ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

int			ft_vdprintf(int fd, const char *format, va_list ap)
{
	int			pos;
	t_output	out;
	size_t		out_len;

	pos = 0;
	out_len = 0;
	while (format[pos] != '\0')
	{
		if (format[pos] == '%')
		{
			++pos;
			ft_bzero(&out, sizeof(t_output));
			parse_format(format, &out, &pos, ap);
			write(fd, out.string, out.len);
			if (out.string != NULL)
				free(out.string);
			out_len += out.len;
		}
		else
		{
			write(fd, &(format[pos++]), 1);
			++out_len;
		}
	}
	return (out_len);
}
