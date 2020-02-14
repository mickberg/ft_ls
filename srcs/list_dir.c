/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:01:13 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/14 15:12:28 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void	list_dir(char *path, int opts)
{
	DIR				*dir;
	struct dirent	*dp;

	dir = opendir(path);

	while (( dp = readdir(dir)) != NULL)
	{
		if (!(opts & OFLAG_ALL) && dp->d_name[0] == '.')
			continue;
		ft_printf("%-10.*s", (int)dp->d_namlen, dp->d_name);
	}
	(void)closedir(dir);
}
