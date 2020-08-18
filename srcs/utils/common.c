/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:17:30 by mikaelber         #+#    #+#             */
/*   Updated: 2020/08/18 17:39:37 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Print error string from current errno
** along with custom string.
*/

void	ft_perror(char *str)
{
	char	tmp[ft_strlen(str) + 8];

	ft_memset(tmp, '\0', ft_strlen(str) + 8);
	ft_strcat(tmp, "ft_ls: ");
	ft_strcat(tmp, str);
	perror(tmp);
}

/*
** Concat path with new name into cpath.
** cpath must already have sufficiently allocated space.
*/

void	ft_concat_path(char *cpath, char *path, char *name)
{
	int	pathlen;

	pathlen = ft_strlen(path);
	ft_memset(cpath, '\0', pathlen + ft_strlen(name) + 2);
	if (pathlen)
	{
		ft_strcat(cpath, path);
		if (!(pathlen == 1 && path[0] == '/'))
			ft_strcat(cpath, "/");
	}
	ft_strcat(cpath, name);
}

/*
** Free single entry structure.
*/

void	ft_del_entry(t_entry *entry)
{
	free(entry->name);
	free(entry);
}

/*
** Free a list of entries.
*/

void	ft_del_entries(t_entry *list)
{
	t_entry	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		ft_del_entry(tmp);
	}
}
