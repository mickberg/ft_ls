/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:48:29 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/14 15:07:10 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_ls_types.h"

# include "libft.h"
# include <stdlib.h>
# include <dirent.h>

void	list_dir(char *path, int opts);

#endif
