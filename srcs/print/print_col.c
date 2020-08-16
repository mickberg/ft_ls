/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 19:33:49 by mikaelber         #+#    #+#             */
/*   Updated: 2020/08/16 21:47:53 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_get_rows(t_lengths *lens, int numof)
{
	struct winsize	winfo;
	int				rows;
	int				cols;
	int				strlen;

	strlen = lens->name + 1;
	ioctl(0, TIOCGWINSZ, &winfo);
	cols = ft_max(1, winfo.ws_col / strlen);
	rows = numof / cols + !!(numof % cols);
	return (rows);
}

static t_entry	*ft_entry_nth(t_entry *list, int nth)
{
	int	i;

	i = 0;
	while (i++ < nth && list)
		list = list->next;
	return (list);
}

void			ft_print_cols(t_entry *list, t_lengths *lens, int numof, int opts)
{
	int		rows;
	int		r;
	int		c;
	t_entry	*tmp;

	(void)opts;

	rows = ft_get_rows(lens, numof);
	r = 0;
	while (r < rows)
	{
		c = r;
		while (c < numof)
		{
			tmp = ft_entry_nth(list, c);
			ft_printf("%-*s", lens->name + 1, tmp->name);
			c += rows;
		}
		ft_printf("\n");
		++r;
	}
}
