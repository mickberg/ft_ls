/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:10:57 by mberglun          #+#    #+#             */
/*   Updated: 2019/11/08 22:40:31 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_truncate(char ***oldarr, char *str)
{
	char	**conc;
	char	**arr;
	size_t	len;

	arr = *oldarr;
	len = 0;
	while (arr[len] != NULL)
		++len;
	conc = (char**)malloc(sizeof(char*) * (len + 2));
	if (!conc)
		return (NULL);
	conc[0] = str;
	conc[len + 1] = NULL;
	while (len > 0)
	{
		conc[len] = arr[len - 1];
		--len;
	}
	free(*oldarr);
	*oldarr = NULL;
	return (conc);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	char	*sub;
	size_t	start;
	size_t	end;

	start = 0;
	while (s[start] != '\0' && s[start] == c)
		++start;
	end = start;
	while (s[end] != '\0' && s[end] != c)
		++end;
	if (s[start] == '\0')
	{
		ret = (char**)malloc(sizeof(char*) * 1);
		if (!ret)
			return (NULL);
		ret[0] = NULL;
		return (ret);
	}
	sub = ft_strsub(s, start, end - start);
	ret = ft_strsplit(s + end, c);
	if (ret == NULL || sub == NULL)
		return (NULL);
	return (ft_truncate(&ret, sub));
}
