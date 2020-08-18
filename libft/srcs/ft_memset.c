/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:07:15 by mberglun          #+#    #+#             */
/*   Updated: 2019/11/08 21:23:04 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d;
	unsigned char	cc;

	cc = (unsigned char)c;
	d = (unsigned char*)b;
	while (len--)
	{
		*d++ = cc;
	}
	return (b);
}
