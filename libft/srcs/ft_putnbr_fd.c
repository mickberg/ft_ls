/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:08:13 by mberglun          #+#    #+#             */
/*   Updated: 2019/11/01 20:08:20 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		exp;
	int		len;

	num = ft_abs(n);
	len = ft_intlen(num);
	if (n < 0)
		ft_putchar_fd('-', fd);
	else if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	exp = (int)ft_pow(10, len - 1);
	while (exp > 0)
	{
		ft_putchar_fd((char)((num / exp) + 48), fd);
		num = num % exp;
		exp /= 10;
	}
}
