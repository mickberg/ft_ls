/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:08:01 by mberglun          #+#    #+#             */
/*   Updated: 2019/11/01 20:08:11 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	num;
	int		exp;
	int		len;

	num = ft_abs(n);
	len = ft_intlen(num);
	if (n < 0)
		ft_putchar('-');
	else if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	exp = (int)ft_pow(10, len - 1);
	while (exp > 0)
	{
		ft_putchar((char)((num / exp) + 48));
		num = num % exp;
		exp /= 10;
	}
}
