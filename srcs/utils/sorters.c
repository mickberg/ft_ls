/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 21:24:34 by mikaelber         #+#    #+#             */
/*   Updated: 2020/07/08 11:13:05 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

/**
 * Uses insertion sort to sort lexicographically an array of string pointers
 */
void ft_string_sort(char **strings, int argc)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < argc)
	{
		j = i;
		while (j > 0 && ft_strcmp(strings[j], strings[j - 1]) < 0)
		{
			tmp = strings[j - 1];
			strings[j - 1] = strings[j];
			strings[j] = tmp;
			--j;
		}
		++i;
	}
}

/**
 * Uses ft_strcmp to compare names of 2 t_dirent types
static ft_compare_dirs(t_dirent *d1, t_dirent *d2)
{
	char	s1[d1->d_namlen + 1];
	char	s2[d2->d_namlen + 1];

	s1[d1->d_namlen] = '\0';
	s2[d2->d_namlen] = '\0';
	ft_strncpy(s1, d1->d_name, d1->d_namlen);
	ft_strncpy(s2, d2->d_name, d2->d_namlen);
	return (ft_strcmp(s1, s2));
}

**
 * Sort an array of t_dirents types lexicographically based on name
int ft_sort_ditem(t_dirent **entries, int count)
{
	int		i;
	int		j;
	t_dirent		*tmp;

	i = 1;
	while (i < count)
	{
		j = i;
		while (j > 0 && ft_compare_dirs(entries[j], entries[j - 1]) < 0)
		{
			tmp = entries[j - 1];
			entries[j - 1] = entries[j];
			entries[j] = tmp;
			--j;
		}
		++i;
	}
}
*/
