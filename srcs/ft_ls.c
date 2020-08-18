/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:49:36 by mikaelber         #+#    #+#             */
/*   Updated: 2020/08/18 17:28:02 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Prints out first illegal option flag then usage with valid flags and exits
** OFLAGS defines all valid options, defined in ft_ls_types.h
*/

static void	print_usage_and_exit(char illegal_opt)
{
	ft_printf("ft_ls: illegal option -- %c\n", illegal_opt);
	ft_printf("usage: ft_ls [-%s] [file ..]\n", OFLAGS);
	exit(1);
}

/*
** Parses option flags, compares any character after an argument which
** has a - char as its first char to the OFLAGS constant.
** Anything after the last option argument is considered a file path.
**
** Returns number of option arguments.
*/

static int	ft_get_options(int *dest, int argc, char **argv)
{
	int	ax;
	int	ix;
	int	fx;

	*dest = 0;
	ax = 1;
	while (ax < argc && argv[ax][0] == '-')
	{
		ix = 1;
		while (argv[ax][ix] != '\0')
		{
			fx = 0;
			while (OFLAGS[fx] != '\0' && argv[ax][ix] != OFLAGS[fx])
				++fx;
			if (OFLAGS[fx] == '\0')
				print_usage_and_exit(argv[ax][ix]);
			*dest |= (1 << fx);
			++ix;
		}
		++ax;
	}
	return (ax);
}

/*
** Allocates new strings for each file argument.
** Fallbacks to (".") if no file arguments are provided
*/

static char	**ft_get_names(char **argv, int argc)
{
	char	**names;
	int		i;

	if (!(names = (char**)malloc(sizeof(char*) * ft_max(1, argc + 1))))
	{
		errno = ENOMEM;
		ft_perror("");
		return (NULL);
	}
	i = 0;
	if (!argc)
		names[i++] = ft_strdup(".");
	else
	{
		while (i < argc)
		{
			names[i] = ft_strdup(argv[i]);
			++i;
		}
	}
	names[i] = NULL;
	return (names);
}

int			main(int argc, char **argv)
{
	int		opts;
	int		ax;
	char	**names;

	ax = ft_get_options(&opts, argc, argv);
	if (!(names = ft_get_names(argv + ax, argc - ax)))
		return (0);
	ft_get_entries("", names, opts);
	return (0);
}
