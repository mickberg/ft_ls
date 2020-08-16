/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:10:30 by mikaelber         #+#    #+#             */
/*   Updated: 2020/08/16 22:06:59 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_entry	*ft_list_dir(char *path, int opts)
{
	DIR				*dir;
	struct dirent	*dp;
	t_entry			*tmp;
	t_entry			*list;
	char			*name;

	list = NULL;
	if (!(dir = opendir(path)))
	{
		ft_perror(path);
		return (NULL);
	}
	while ((dp = readdir(dir)) != NULL)
	{
		if (!ft_strncmp(dp->d_name, ".", 1) && !(opts & OFLAG_ALL))
			continue;
		name = ft_strnew(dp->d_namlen);
		ft_strncat(name, dp->d_name, dp->d_namlen);
		if (!(tmp = ft_make_entry(path, name)))
			free(name);
		list = ft_add_entry(list, tmp, opts);
	}
	closedir(dir);
	return (list);
}

static void		ft_read_dir(char *path, char *name, int opts)
{
	char	cpath[(ft_strlen(path) + ft_strlen(name) + 2)];
	t_entry	*tmp;
	t_entry	*list;

	ft_concat_path(cpath, path, name);
	if (!(list = ft_list_dir(cpath, opts)))
		return ;
	ft_print_dir(cpath, list, opts);
	while (list)
	{
		if (opts & OFLAG_REC && S_ISDIR(list->mflags) && !list->relative)
		{
			ft_printf("\n%s/%s:\n", cpath, list->name);
			ft_read_dir(cpath, list->name, opts);
		}
		tmp = list;
		list = list->next;
		free(tmp->name);
		free(tmp);
	}
}

void			ft_get_entries(char *path, char **names, int opts)
{
	t_entry		*tmp;
	t_entry		*files;
	t_entry		*dirs;

	files = dirs = NULL;
	while (*names)
	{
		if (!(tmp = ft_make_entry(path, *(names++))))
			continue;
		if (S_ISDIR(tmp->mflags))
			dirs = ft_add_entry(dirs, tmp, opts);
		else
			files = ft_add_entry(files, tmp, opts);
	}
	if (files)
	{
		ft_print_entries(path, files, opts);
		ft_del_entries(files);
	}
	while (dirs)
	{
		if (opts & OFLAG_MULTIPLE)
			ft_printf("%*s%s:%*s", !!files, "\n", dirs->name, !!dirs->next, "\n");
		ft_read_dir(path, dirs->name, opts);
		tmp = dirs;
		dirs = dirs->next;
		ft_del_entry(tmp);
	}
}
