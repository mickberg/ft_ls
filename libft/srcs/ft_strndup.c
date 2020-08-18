/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:10:17 by mberglun          #+#    #+#             */
/*   Updated: 2019/11/12 17:30:35 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dup;
	char	*d;
	size_t	strlen;

	strlen = ft_strlen((char*)s1);
	if (strlen < n)
		n = strlen;
	dup = (char*)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	d = dup;
	while (*s1 != '\0' && n--)
		*d++ = (char)*s1++;
	*d = '\0';
	return (dup);
}
