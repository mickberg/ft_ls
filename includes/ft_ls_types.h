/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:44:26 by mikaelber         #+#    #+#             */
/*   Updated: 2020/08/17 18:51:50 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_TYPES_H
# define FT_LS_TYPES_H

# include <time.h>
# include <grp.h>
# include <pwd.h>
# include <sys/stat.h>

/* ** typedef structs for cleaner code */
typedef struct s_entry		t_entry;
typedef struct s_lengths	t_lengths;
typedef struct s_id			t_id;

/** * six months ago in seconds */
#define SIX_MA			15721200

/* ** Option flags are parsed based on OFLAGS macro */
# define OFLAGS			"Ralrt"
# define OFLAG_REC		0x01
# define OFLAG_ALL		0x02
# define OFLAG_LLONG	0x04
# define OFLAG_REVERSE	0x08
# define OFLAG_SORTT	0x10
/* ** internal flag */
# define OFLAG_MULTIPLE	0x20

/*
** Entry structure, holds necessary entry entry for all types.
*/
struct					s_entry
{
	char			*name;
	long long		size;
	unsigned short	mflags;
	uid_t			uid;
	gid_t			gid;
	char			*uname;
	char			*gname;
	unsigned short	nlink;
	dev_t			rdev;
	unsigned short	relative;
	unsigned int	blocks;
	time_t			time;
	time_t			ntime;
	struct s_entry	*next;
};

/**
 * Keeps max lengts for entry properties.
 */
struct					s_lengths
{
	int	nlink;
	int	uname;
	int	gname;
	int	size;
	int	minor;
	int	major;
	int	name;
};

/**
 * Stores Group and Passwd id-name pairs
 */
struct					s_id
{
	unsigned int	id;
	char			*name;
	struct s_id		*next;
};

#endif
