/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 23:28:44 by mikaelber         #+#    #+#             */
/*   Updated: 2020/08/18 00:04:20 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"

/*
** sys/ioctl.h is for detecting terminal width.
** sys/xattr.h is for getting extended attributes.
** sys/acl.h is for getting Access Control List.
*/
# include <errno.h>
# include <stdio.h>
# include <dirent.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include <sys/types.h>
# include <sys/errno.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <sys/stat.h>
# include <sys/ioctl.h>

/*
** SIX_MA is six months ago in seconds
**
** OFLAGS contain all options
** OFLAG_* are option bitflags
** OFLAG_* bits correspond to the location of their
** corresponding char in OFLAGS.
**
** OFLAG_MULTIPLE is an internal flag used to determine
** if a new line should be printed after the first files are listed.
*/
# define SIX_MA			15721200
# define OFLAGS			"Ralrt"
# define OFLAG_REC		0x01
# define OFLAG_ALL		0x02
# define OFLAG_LLONG	0x04
# define OFLAG_REVERSE	0x08
# define OFLAG_SORTT	0x10
# define OFLAG_MULTIPLE	0x20

/*
** Typedefs for structures.
*/
typedef struct s_entry		t_entry;
typedef struct s_lengths	t_lengths;
typedef struct s_id			t_id;

/*
** Structure describing entry properties.
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

/*
** Keeps max lengths of properties printed in long format.
** stored in a struct for easier maintability and further improvements.
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

/*
** Stores Group and Passwd id-name pairs
** Used for internal storage to improve performance
** by not calling getpwuid and getgrgid for every entry.
*/
struct					s_id
{
	unsigned int	id;
	char			*name;
	struct s_id		*next;
};

/*
** Main entry point.
*/
void	ft_get_entries(char *path, char **names, int opts);

/*
** Util functions.
*/
void	ft_perror(char *str);
void	ft_concat_path(char *cpath, char *path, char *name);

/*
** Print functions.
*/
void	ft_print_entries(char *path, t_entry *entries, int opts);
void	ft_print_dir(char *path, t_entry *list, int opts);
void	ft_print_cols(t_entry *list, t_lengths *lens, int numof, int opts);
void	ft_print_modes(t_entry *entry, char *path);
void	ft_print_long(t_entry *entries, t_lengths *lens, char *path, int opts);

/*
** Entry manipulation functions.
*/
t_entry	*ft_make_entry(char *path, char *name);
t_entry	*ft_add_entry(t_entry *list, t_entry *entry, int opts);
void	ft_del_entry(t_entry *entry);
void	ft_del_entries(t_entry *list);

/*
** Username / Groupname database functions.
*/
char	*ft_get_uname(uid_t id);
char	*ft_get_gname(gid_t id);

#endif
