/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:08:02 by mikaelber         #+#    #+#             */
/*   Updated: 2020/01/17 12:38:41 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_number(const char *format, int *pos, int *num)
{
	char	*str;

	str = (char*)format + (*pos);
	*num = 0;
	while (ft_isdigit(*str))
	{
		*num = *num * 10 + (int)(*str - '0');
		(*pos)++;
		++str;
	}
}
