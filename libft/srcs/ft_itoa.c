/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:04:49 by mberglun          #+#    #+#             */
/*   Updated: 2019/11/12 18:12:35 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	int		i;
	char	*str;

	num = ft_abs(n);
	len = ft_intlen(n);
	if (n < 0)
		++len;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	i = 1;
	while (num > 0)
	{
		str[len - i] = (char)(num % 10) + '0';
		++i;
		num /= 10;
	}
	str[len] = '\0';
	return (str);
}
