/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:48:29 by mikaelber         #+#    #+#             */
/*   Updated: 2020/08/06 16:01:00 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_ls_types.h"

# include <errno.h>

# include "libft.h"
# include <dirent.h>
# include <unistd.h>

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include <sys/xattr.h>

void	ft_get_entries(char *path, char **names, int opts);
void	ft_stat_dir(char *path, int opts);
/** * Util functions */
void	ft_string_sort(char **strings, int argc);
void	ft_perror(char *str);
void	ft_concat_path(char *cpath, char *path, char *name);
/** * Entry list functions */
t_entry	*ft_make_entry(char *path, char *name);
t_entry	*ft_create_entry(struct stat *stat, char *name);
t_entry	*ft_add_entry(t_entry *list, t_entry *entry, int opts);
void	ft_print_entries(t_entry *entries, int opts);
void	ft_print_dir(t_entry *list, int opts);
void	ft_del_entry(t_entry *entry);
void	ft_del_entries(t_entry *list);

char	*ft_get_uname(uid_t id);
char	*ft_get_gname(gid_t id);

#endif
