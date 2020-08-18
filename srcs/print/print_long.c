/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 18:27:05 by mikaelber         #+#    #+#             */
/*   Updated: 2020/08/18 17:58:54 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Prints last modification/access time in clean format.
** if time is more than 6 months from now or in the future
** shows year instead of hour:minute.
*/

static void	ft_print_time(time_t mtime)
{
	time_t	cur;
	char	*timestr;

	timestr = ctime(&(mtime));
	cur = time(NULL);
	if ((cur - mtime) > YEAR_SEC / 2 || cur < mtime)
		ft_printf(" %.6s  %.4s", timestr + 4, timestr + 20);
	else
		ft_printf(" %.12s", timestr + 4);
}

/*
** Prints entry size or minor and major disk ids
** for block and char specific files.
*/

static void	ft_print_size(t_entry *entry, t_lengths *lens)
{
	if (S_ISCHR(entry->mflags) || S_ISBLK(entry->mflags))
	{
		ft_printf("  %*d", lens->major, major(entry->rdev));
		ft_printf(", %*d", lens->minor, minor(entry->rdev));
	}
	else
		ft_printf("  %*lld", lens->size, entry->size);
}

/*
** Prints basic long format properties
** split because of norme.
*/

static void	ft_long_base(t_entry *entry, t_lengths *lens, char *path)
{
	char	buf[NAME_MAX + 1];

	ft_print_modes(entry, path);
	ft_printf(" %*d", lens->nlink, entry->nlink);
	ft_printf(" %-*s", lens->uname, entry->uname);
	ft_printf("  %-*s", lens->gname, entry->gname);
	ft_print_size(entry, lens);
	ft_print_time(entry->time);
	ft_printf(" %s", entry->name);
	if (S_ISLNK(entry->mflags))
	{
		ft_memset(&buf, '\0', NAME_MAX + 1);
		readlink(path, buf, NAME_MAX);
		ft_printf(" -> %s", buf);
	}
	ft_printf("\n");
}

/*
** Recursive function for printing entries in long format.
*/

void		ft_print_long(t_entry *entry, t_lengths *lens, char *path)
{
	char	*cpath;
	size_t	len;

	len = ft_strlen(path) + ft_strlen(entry->name) + 2;
	if (!(cpath = (char*)malloc(sizeof(char) * len)))
	{
		errno = ENOMEM;
		ft_perror("");
	}
	else
	{
		ft_concat_path(cpath, path, entry->name);
		ft_long_base(entry, lens, cpath);
		free(cpath);
	}
	if (entry->next)
		ft_print_long(entry->next, lens, path);
}
