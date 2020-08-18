/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspecial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:29:14 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/07 20:54:23 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_isspecial(char c)
{
	char	schars[256];

	ft_bzero(&schars, 256);
	schars[0x07] = 'a';
	schars[0x08] = 'b';
	schars[0x09] = 't';
	schars[0x0A] = 'n';
	schars[0x0B] = 'v';
	schars[0x0C] = 'c';
	schars[0x0D] = 'f';
	schars[0x1B] = 'e';
	schars[0x22] = '\"';
	schars[0x27] = '\'';
	schars[0x3F] = '\?';
	schars[0x5C] = '\\';
	return (schars[(int)c]);
}
