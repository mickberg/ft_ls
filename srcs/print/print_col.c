/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 19:33:49 by mikaelber         #+#    #+#             */
/*   Updated: 2020/08/18 17:33:40 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Determine number of rows based on terminal width
*/

static int		ft_get_rows(int strlen, int numof)
{
	struct winsize	winfo;
	int				rows;
	int				cols;

	ioctl(0, TIOCGWINSZ, &winfo);
	cols = ft_max(1, winfo.ws_col / (strlen + 1));
	rows = numof / cols + !!(numof % cols);
	return (rows);
}

/*
** Get nth entry in list
*/

static t_entry	*ft_entry_nth(t_entry *list, int nth)
{
	int	i;

	i = 0;
	while (i++ < nth && list)
		list = list->next;
	return (list);
}

/*
** Prints entries into even colums
*/

void			ft_print_cols(t_entry *list, int strlen, int numof)
{
	int		rows;
	int		r;
	int		c;
	t_entry	*tmp;

	rows = ft_get_rows(strlen, numof);
	r = 0;
	while (r < rows)
	{
		c = r;
		while (c < numof)
		{
			tmp = ft_entry_nth(list, c);
			ft_printf("%-*s", strlen + 1, tmp->name);
			c += rows;
		}
		ft_printf("\n");
		++r;
	}
}
