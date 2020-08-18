/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:06:10 by mberglun          #+#    #+#             */
/*   Updated: 2019/11/08 19:18:46 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		cc;
	unsigned char		*d;
	const unsigned char	*s;

	cc = (unsigned char)c;
	d = (unsigned char*)dst;
	s = (const unsigned char*)src;
	while (n--)
	{
		*d++ = *s++;
		if (*(s - 1) == cc)
			return (d);
	}
	return (NULL);
}
