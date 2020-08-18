/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:09:31 by mberglun          #+#    #+#             */
/*   Updated: 2019/11/09 20:19:53 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	n;
	size_t	l;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen((char*)src);
	dst += dstlen;
	if (dstlen >= dstsize)
		return (dstsize + srclen);
	n = dstsize - dstlen - 1;
	l = 0;
	while (l++ < n && *src != '\0')
	{
		*dst = *src;
		++dst;
		++src;
	}
	*dst = '\0';
	return (dstlen + srclen);
}
