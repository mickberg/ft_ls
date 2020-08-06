/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:09:31 by mikaelber         #+#    #+#             */
/*   Updated: 2020/07/26 15:37:45 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

static t_id	*ft_new_uid(unsigned int uid)
{
	char			*name;
	struct passwd	*pwd;
	t_id			*id;

	pwd = getpwuid((uid_t)uid);
	if (!pwd)
		name = ft_itoa(uid);
	else
		name = ft_strdup(pwd->pw_name);
	if (!(id = (t_id*)malloc(sizeof(t_id))))
		return (NULL);
	id->name = name;
	id->id = uid;
	id->next = NULL;
	return (id);
}

static t_id	*ft_new_gid(unsigned int gid)
{
	char			*name;
	struct group	*gr;
	t_id			*id;

	gr = getgrgid(gid);

	if (!gr)
		name = ft_itoa((gid_t)gid);
	else
		name = ft_strdup(gr->gr_name);
	if (!(id = (t_id*)malloc(sizeof(t_id))))
		return (NULL);
	id->name = name;
	id->id = gid;
	id->next = NULL;
	return (id);
}

t_id		*ft_get_id(t_id **list, unsigned int id, t_id* (*f)(unsigned int))
{
	t_id		*inv;
	t_id		*prev;
	t_id		*new;

	prev = NULL;
	inv = *list;
	while (inv && id > inv->id)
	{
		prev = inv;
		inv = inv->next;
	}
	if (inv && inv->id == id)
		return (inv);

	new = f(id);
	new->next = inv;
	if (prev != NULL)
		prev->next = new;
	else
		*list = new;
	return (new);
}

char		*ft_get_uname(uid_t id)
{
	static t_id	*udb;
	t_id		*res;

	if (!udb)
	{
		if (!(udb = ft_new_uid(id)))
			return (NULL);
		else
			return (udb->name);
	}

	if (!(res = ft_get_id(&udb, (unsigned int)id, &ft_new_uid)))
		return (NULL);
	return (res->name);
}

char		*ft_get_gname(gid_t id)
{
	static t_id	*gdb;
	t_id		*res;

	if (!gdb)
	{
		if (!(gdb = ft_new_gid(id)))
			return (NULL);
		else
			return (gdb->name);
	}

	if (!(res = ft_get_id(&gdb, (unsigned int)id, &ft_new_gid)))
	{
		ft_perror(ft_itoa(id));
		return (NULL);
	}
	return (res->name);
}
