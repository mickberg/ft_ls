/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entries.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:53:51 by mikaelber         #+#    #+#             */
/*   Updated: 2020/08/17 02:42:19 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_entry		*ft_create_entry(struct stat *stat, char *name)
{
	t_entry	*entry;

	if (!(entry = (t_entry*)malloc(sizeof(t_entry))))
		return (NULL);
	ft_memset(entry, 0, sizeof(t_entry));
	entry->name = name;
	entry->size = stat->st_size;
	entry->mflags = stat->st_mode;
	entry->uid = stat->st_uid;
	entry->gid = stat->st_gid;
	entry->nlink = stat->st_nlink;
	entry->rdev = stat->st_rdev;
	entry->relative = (!ft_strncmp(name, ".", 2) || !ft_strncmp(name, "..", 3));
	entry->blocks = stat->st_blocks;
	entry->time = stat->st_mtimespec.tv_sec;
	entry->next = NULL;
	return (entry);
}

static int	ft_comp_entry(t_entry *a, t_entry *b, int opts)
{
	t_entry	*left;
	t_entry	*right;

	left = a;
	right = b;
	if (opts & OFLAG_REVERSE)
	{
		left = b;
		right = a;
	}
	if (opts & OFLAG_SORTT)
	{
		if (a->time == b->time)
			return (ft_strcmp(b->name, a->name) > 0);
		return (left->time > right->time);
	}
	else
		return (ft_strcmp(right->name, left->name) > 0);
}

t_entry		*ft_add_entry(t_entry *list, t_entry *entry, int opts)
{
	t_entry	*prev;
	t_entry	*inv;

	if (list == NULL)
		return (entry);
	else if (entry == NULL)
		return (list);
	prev = NULL;
	inv = list;
	while (inv && ft_comp_entry(inv, entry, opts))
	{
		prev = inv;
		inv = inv->next;
	}
	entry->next = inv;
	if (prev != NULL)
	{
		prev->next = entry;
		return (list);
	}
	return (entry);
}

t_entry	*ft_make_entry(char *path, char *name)
{
	struct stat	buf;
	t_entry		*entry;
	char		cpath[(ft_strlen(path) + ft_strlen(name) + 2)];

	ft_concat_path(cpath, path, name);
	if (lstat(cpath, &buf) == -1)
	{
		ft_perror(cpath);
		return (NULL);
	}
	if (!(entry = ft_create_entry(&buf, name)))
	{
		errno = ENOMEM;
		ft_perror(cpath);
		return (NULL);
	}
	return (entry);
}

void	ft_del_entry(t_entry *entry)
{
	free(entry->name);
	free(entry);
}

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
