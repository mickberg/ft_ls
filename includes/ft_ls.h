/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:48:29 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/14 18:49:20 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_ls_types.h"

# include "libft.h"
# include <stdlib.h>
# include <dirent.h>

void	ft_read_dir(char *path, int opts);

#endif
