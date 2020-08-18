/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:07:01 by mberglun          #+#    #+#             */
/*   Updated: 2019/11/12 17:25:09 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;
	size_t	i;

	dest = (char*)dst;
	source = (char*)src;
	if (dest > source)
		while (len--)
			dest[len] = source[len];
	else
	{
		i = 0;
		while (i < len)
		{
			dest[i] = source[i];
			++i;
		}
	}
	return (dst);
}
