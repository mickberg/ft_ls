/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:51:51 by mikaelber         #+#    #+#             */
/*   Updated: 2020/08/16 19:12:27 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_get_lengths(t_lengths *lens, t_entry *list, int opts)
{
	ft_memset(lens, 0, sizeof(t_lengths));
	lens->minor = 3;
	lens->major = 3;
	while (list)
	{
		if (opts & OFLAG_LLONG)
		{
			list->uname = ft_get_uname(list->uid);
			list->gname = ft_get_gname(list->gid);
			lens->uname = ft_max(lens->uname, ft_strlen(list->uname));
			lens->gname = ft_max(lens->gname, ft_strlen(list->gname));
			lens->nlink = ft_max(lens->nlink, ft_intlen(list->nlink));
			if (S_ISCHR(list->mflags) || S_ISBLK(list->mflags))
			{
				lens->minor = ft_max(lens->minor, ft_intlen(minor(list->rdev)));
				lens->major = ft_max(lens->major, ft_intlen(major(list->rdev)));
				lens->size = ft_max(lens->size, lens->minor + lens->major + 2);
			}
			lens->size = ft_max(lens->size, ft_intlen(list->size));
		}
		lens->name = ft_max(lens->name, ft_strlen(list->name));
		list = list->next;
	}
}


void		ft_print_entries(char *path, t_entry *list, int opts)
{
	t_lengths	lens;

	ft_get_lengths(&lens, list, opts);
	if (opts & OFLAG_LLONG)
		ft_print_long(list, &lens, path, opts);
	else
	{
		while (list)
		{
			ft_printf("%c %s\n", list->type, list->name);
			list = list->next;
		}
	}
}

void		ft_print_dir(char *path, t_entry *list, int opts)
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
		ft_printf("total %lld\n", blocks);
	ft_print_entries(path, list, opts);
}
