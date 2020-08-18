/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:01:22 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/07 20:02:34 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Counts number of characters in string;
*/

int		ft_strcc(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str != '\0')
		if (*str++ == c)
			++count;
	return (count);
}
