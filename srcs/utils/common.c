/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:17:30 by mikaelber         #+#    #+#             */
/*   Updated: 2020/08/16 22:26:11 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_perror(char *str)
{
	char	*tmp;

	if (!(tmp = ft_strjoin("ft_ls: ", str)))
		return ;
	perror(tmp);
	free(tmp);
	tmp = NULL;
}

void		ft_concat_path(char *cpath, char *path, char *name)
{
	ft_memset(cpath, '\0', ft_strlen(path) + ft_strlen(name) + 2);
	if (ft_strlen(path))
	{
		ft_strcat(cpath, path);
		ft_strcat(cpath, "/");
	}
	ft_strcat(cpath, name);
}
