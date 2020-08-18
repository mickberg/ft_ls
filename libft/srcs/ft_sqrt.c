/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:48:30 by mberglun          #+#    #+#             */
/*   Updated: 2019/12/17 15:52:34 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	res;
	long	last;

	res = 0;
	while (res < nb)
	{
		if (res * res == nb)
		{
			break ;
		}
		else if (res * res > nb)
		{
			res = last;
			break ;
		}
		last = res;
		res++;
	}
	return (res);
}
