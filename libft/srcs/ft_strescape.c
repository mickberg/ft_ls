/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strescape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:51:41 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/07 21:00:44 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns new string with all backslashes (\) escaped
** Enables printing of escaped versions of non-printable characters
*/

char	*ft_strescape(const char *str)
{
	size_t	ecount;
	size_t	ix;
	char	*escaped;

	ix = 0;
	ecount = 0;
	while (str[ix] != '\0')
	{
		if (ft_isspecial(str[ix++]))
			++ecount;
	}
	if (!(escaped = ft_strnew(ecount + ft_strlen(str))))
		return (NULL);
	ix = 0;
	while (*str != '\0')
	{
		if (ft_isspecial(*str))
		{
			escaped[ix++] = '\\';
			escaped[ix++] = ft_isspecial(*str);
		}
		else
			escaped[ix++] = *str;
		++str;
	}
	return (escaped);
}
