/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:07:23 by mberglun          #+#    #+#             */
/*   Updated: 2019/11/01 20:07:32 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	ft_powpos(double n, int exp)
{
	double	sum;

	sum = n;
	while (--exp > 0)
		sum *= n;
	return (sum);
}

static double	ft_powneg(double n, int exp)
{
	double sum;

	sum = 1;
	while (exp++ < 0)
		sum /= n;
	return (sum);
}

double			ft_pow(double n, int exp)
{
	if (exp == 0)
		return ((double)1);
	else if (exp < 0)
		return (ft_powneg(n, exp));
	else
		return (ft_powpos(n, exp));
}
