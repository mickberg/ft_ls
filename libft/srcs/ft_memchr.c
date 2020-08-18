/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:06:18 by mberglun          #+#    #+#             */
/*   Updated: 2019/11/12 17:25:38 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*source;

	cc = (unsigned char)c;
	source = (unsigned char*)s;
	while (n--)
	{
		if (*source == cc)
			return ((void*)source);
		++source;
	}
	return (NULL);
}
