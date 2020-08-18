/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:55:19 by mberglun          #+#    #+#             */
/*   Updated: 2019/11/09 20:23:21 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	const char *match;

	match = NULL;
	while (*s != '\0')
	{
		if ((int)*s == c)
			match = s;
		++s;
	}
	if (c == '\0')
		return ((char*)s);
	return ((char*)match);
}
