/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:10:33 by mberglun          #+#    #+#             */
/*   Updated: 2019/11/11 15:02:21 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*str;
	const char	*need;
	size_t		sublen;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0' && len--)
	{
		str = haystack;
		need = needle;
		sublen = len + 1;
		while (*str++ == *need++ && sublen--)
		{
			if (*need == '\0')
				return ((char*)haystack);
		}
		++haystack;
	}
	return (NULL);
}
