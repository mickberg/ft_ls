/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:01:13 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/14 18:10:21 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

static int	get_lengths(char *path, int opts)
{
	DIR				*dir;
	struct dirent	*dp;
	int				namelen;

	namelen = 0;
	dir = opendir(path);
	while ((dp = readdir(dir)) != NULL)
	{
		if (!(opts & OFLAG_ALL) && dp->d_name[0] == '.')
			continue;
		namelen = ft_max(namelen, dp->d_namlen);
	}
	return (namelen);
}

void	list_dir(char *path, int opts)
{
	DIR				*dir;
	struct dirent	*dp;
	int				namelen;

	namelen = get_lengths(path, opts);
	dir = opendir(path);
	while (( dp = readdir(dir)) != NULL)
	{
		if (!(opts & OFLAG_ALL) && dp->d_name[0] == '.')
			continue;
		ft_printf("%-10.*s", namelen, dp->d_name);
	}
	(void)closedir(dir);
}
