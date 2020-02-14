/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:44:26 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/14 15:06:25 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_TYPES_H
# define FT_LS_TYPES_H

/* ** typedef structs for cleaner code */
typedef struct s_ditem	t_ditem;

/* ** Typedef of native types for cleaner code */
typedef unsigned char	t_uint8;
typedef unsigned short	t_uint16;

/* ** Option flags are parsed based on OFLAGS macro */
# define OFLAGS			"Ralrt"
# define OFLAG_REC		0x01
# define OFLAG_ALL		0x02
# define OFLAG_LLONG	0x04
# define OFLAG_REVERSE	0x08
# define OFLAG_SORTT	0x08

/*
** directory structure, combines dirent and lstat properties.
** Works as a linked list
*/
struct					s_ditem
{
	t_uint16		size;
	t_uint8			nlen;
	char			name[255 + 1];
	struct s_ditem	*next;
};

#endif
