/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_modes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 18:26:55 by mikaelber         #+#    #+#             */
/*   Updated: 2020/08/16 18:48:25 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	ft_file_type(int mflag)
{
	if (S_ISDIR(mflag))
		return ('d');
	else if (S_ISCHR(mflag))
		return ('c');
	else if (S_ISBLK(mflag))
		return ('b');
	else if (S_ISLNK(mflag))
		return ('l');
	else if (S_ISFIFO(mflag))
		return ('p');
	else if (S_ISSOCK(mflag))
		return ('s');
	return ('-');
}

static void	ft_comp_permissions(char *modes, int mflag)
{
	int	i;
	int	j;

	j = 0;
	i = 256;
	while (i > 0)
	{
		if (mflag & i)
			modes[j] = ("rwx")[j % 3];
		else
			modes[j] = '-';
		if ((j % 3) == 2)
		{
			if (j == 2 && S_ISUID & mflag)
				modes[j] = ("sS")[!(modes[j] == 'x')];
			else if (j == 5 && S_ISGID & mflag)
				modes[j] = ("sS")[!(modes[j] == 'x')];
			else if (j == 8 && S_ISVTX & mflag)
				modes[j] = ("tT")[!(modes[j] == 'x')];
		}
		i /= 2;
		++j;
	}
}

void		ft_print_modes(t_entry *entry, char *path)
{
	char	modes[12];
	acl_t	acl;

	ft_bzero(modes, 12);
	modes[0] = ft_file_type(entry->mflags);
	ft_comp_permissions(modes + 1, entry->mflags);
	modes[10] = ' ';
	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		modes[10] = '@';
	else if ((acl = acl_get_file(path, ACL_TYPE_EXTENDED)) != NULL)
	{
		modes[10] = '+';
		acl_free(acl);
	}
	ft_printf("%-11s", modes);
}
