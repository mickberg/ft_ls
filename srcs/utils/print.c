/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:51:51 by mikaelber         #+#    #+#             */
/*   Updated: 2020/08/06 15:55:30 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_comp_permissions(char *modes, int mflag)
{
	int	i;
	int	j;

	j = 0;
	if (S_ISDIR(mflag))
		modes[j++] = 'd';
	else if (S_ISLNK(mflag))
		modes[j++] = 'l';
	else
		modes[j++] = '-';
	i = 256;
	while (i > 0)
	{
		if (mflag & i)
			modes[j] = ("rwx")[(j - 1) % 3];
		else
			modes[j] = '-';
		i /= 2;
		++j;
	}
}

static void	ft_get_lengths(t_lengths *lens, t_entry *list)
{
	ft_memset(lens, 0, sizeof(t_lengths));
	while (list)
	{
		list->uname = ft_get_uname(list->uid);
		list->gname = ft_get_gname(list->gid);

		lens->nlink = ft_max(lens->nlink, ft_intlen(list->nlink));
		lens->size = ft_max(lens->size, ft_intlen(list->size));
		lens->uname = ft_max(lens->uname, ft_strlen(list->uname));
		lens->gname = ft_max(lens->gname, ft_strlen(list->gname));
		lens->name = ft_max(lens->name, ft_strlen(list->name));
		list = list->next;
	}
}

void	ft_print_entries(t_entry *list, int opts)
{
	char		modes[11];
	char		*timestr;
	t_lengths	lens;
	(void)opts;

	ft_get_lengths(&lens, list);
	ft_memset(modes, '\0', 11);
	while (list)
	{
		ft_comp_permissions(modes, list->mflags);
		timestr = ctime(&(list->time));

		ft_printf("%-11s", modes);
		ft_printf(" %*d", lens.nlink, list->nlink);
		ft_printf(" %-*s", lens.uname + 1, list->uname);
		ft_printf(" %-*s", lens.gname + 1, list->gname);
		ft_printf(" %*lld", lens.size, list->size);
		ft_printf(" %.12s", timestr + 4);
		ft_printf(" %s\n", list->name);

		list = list->next;
	}
}

void	ft_print_dir(t_entry *list, int opts)
{
	long long	blocks;
	t_entry		*tmp;

	blocks = 0;
	tmp = list;
	while (tmp)
	{
		blocks += tmp->blocks;
		tmp = tmp->next;
	}
	if (list)
		printf("total %lld\n", blocks);
	ft_print_entries(list, opts);
}
