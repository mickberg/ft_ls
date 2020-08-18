/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:11:12 by mberglun          #+#    #+#             */
/*   Updated: 2019/11/12 18:11:48 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	tmp;

	start = 0;
	while ((s[start] == 32 || s[start] == 10 ||
		s[start] == 9) && s[start] != '\0')
	{
		++start;
	}
	tmp = start;
	end = start;
	while (s[tmp] != '\0')
	{
		if (s[tmp] != 32 && s[tmp] != 10 && s[tmp] != 9)
			end = tmp;
		++tmp;
	}
	return (ft_strsub(s, start, end - start + 1));
}
