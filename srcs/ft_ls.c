/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:49:36 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/14 15:12:36 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

static void	print_usage_and_exit(char illegal_opt)
{
	ft_printf("ft_ls: illegal option -- %c\n", illegal_opt);
	ft_printf("usage: ft_ls [-%s] [file ..]\n", OFLAGS);
	exit(1);
}

static int	get_options(int	*dest, int argc, char **argv)
{
	int		ax;
	int		ix;
	int		fx;

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

int		main(int argc, char **argv)
{
	int		opts;
	int		ax;

	ax = get_options(&opts, argc, argv);
	if (ax == argc)
		list_dir(".", opts);
	else
	{
		list_dir(argv[ax++], opts);
		while (ax < argc)
		{
			ft_printf("\n");
			list_dir(argv[ax], opts);
			++ax;
		}
	}
	ft_printf("\n");
	return (0);
}
