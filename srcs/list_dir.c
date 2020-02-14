/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:01:13 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/14 19:52:51 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_compare_dentries(t_dent *d1, t_dent *d2)
{
	char	s1[d1->d_namlen + 1];
	char	s2[d2->d_namlen + 1];

	s1[d1->d_namlen] = '\0';
	s2[d2->d_namlen] = '\0';
	ft_strncpy(s1, d1->d_name, d1->d_namlen);
	ft_strncpy(s2, d2->d_name, d2->d_namlen);
	return (ft_strcmp(s1, s2) * -1);
}

static void	ft_sort_dir(t_dent ***entries, int entry_count)
{
	int		ix;
	int		jx;
	t_dent	*tmp;

	ix = 1;
	while (ix < entry_count)
	{
		jx = ix;
		while (jx > 0 &&
				ft_compare_dentries((*entries)[jx - 1], (*entries)[jx]) < 0)
		{
			tmp = (*entries)[jx - 1];
			(*entries)[jx - 1] = (*entries)[jx];
			(*entries)[jx] = tmp;
			--jx;
		}
		++ix;
	}
}

static void	ft_list_dir(char *path, int entry_count, int opts)
{
	t_dent	**entries;
	t_dent	*tmp;
	DIR		*dir;
	int		ex;
	int		namelen;

	if (!(entries = (t_dent **)malloc(sizeof(t_dent *) * entry_count)))
		return ;
	dir = opendir(path);
	ex = 0;
	while ((tmp = readdir(dir)) != NULL)
		if (opts & OFLAG_ALL || tmp->d_name[0] != '.')
			entries[ex++] = tmp;
	namelen = 0;
	ex = 0;
	while (ex < entry_count)
		namelen = ft_max(namelen, entries[ex++]->d_namlen);
	ft_sort_dir((t_dent ***)&entries, entry_count);
	ex = 0;
	while (ex < entry_count)
		ft_printf("%-*.*s", namelen + 1, namelen, entries[ex++]->d_name);
	(void)closedir(dir);
}

void		ft_read_dir(char *path, int opts)
{
	DIR		*dir;
	t_dent	*dp;
	int		entries;

	if (opts & OFLAG_MULTIPLE)
		ft_printf("%s:\n", path);
	entries = 0;
	dir = opendir(path);
	while ((dp = readdir(dir)) != NULL)
		if ((opts & OFLAG_ALL) || dp->d_name[0] != '.')
			++entries;
	(void)closedir(dir);
	ft_list_dir(path, entries, opts);
}
