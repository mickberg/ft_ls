/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 07:38:08 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/09 15:34:20 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "gnl.h"

static t_fdlist	*ft_findcache(t_fdlist **fd_cache, int fd)
{
	t_fdlist	*c;

	c = *fd_cache;
	while (c && c->fd != fd)
		c = c->next;
	if (!c)
	{
		if (!(c = (t_fdlist*)malloc(sizeof(t_fdlist))))
			return (NULL);
		c->cache = ft_strnew(0);
		c->fd = fd;
		c->next = NULL;
		if (*fd_cache)
			c->next = *fd_cache;
		*fd_cache = c;
	}
	return (c);
}

static int		ft_freecache(t_fdlist **fd_cache, int fd)
{
	t_fdlist	*c;
	t_fdlist	*prev;

	c = *fd_cache;
	prev = NULL;
	while (c->fd != fd)
	{
		prev = c;
		c = c->next;
	}
	if (!prev)
	{
		*fd_cache = c->next;
	}
	else
		prev->next = c->next;
	if (c->cache != NULL)
		ft_strdel(&c->cache);
	free(c);
	c = NULL;
	return (0);
}

static int		ft_extract_line(t_fdlist *fdcache, char **line, char brpoint)
{
	char		*tmp;
	char		*nlc;

	nlc = ft_strchr(fdcache->cache, brpoint);
	if (!nlc || !ft_strlen(fdcache->cache))
		return (0);
	if (!(*line = ft_strndup(fdcache->cache, nlc - fdcache->cache)))
		return (-1);
	if (*nlc == '\n')
		++nlc;
	if (!(tmp = ft_strdup(nlc)))
		return (-1);
	ft_strdel(&fdcache->cache);
	fdcache->cache = tmp;
	return (1);
}

static ssize_t	ft_getline(t_fdlist *fdcache, char **line, int fd)
{
	char	buff[BUFF_SIZE + 1];
	ssize_t	br;
	char	*tmp;

	while ((br = ft_extract_line(fdcache, line, '\n')) == 0 &&
			(br = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[br] = '\0';
		if (!(tmp = ft_strjoin(fdcache->cache, buff)))
			return (-1);
		ft_strdel(&fdcache->cache);
		fdcache->cache = tmp;
	}
	if (br < 0)
		return (-1);
	if (br == 0 && ft_extract_line(fdcache, line, '\0'))
		return (1);
	return (br);
}

int				get_next_line(const int fd, char **line)
{
	ssize_t			br;
	static t_fdlist	*fd_cache;
	t_fdlist		*cache;

	if (fd < 0 || line == NULL || !(cache = ft_findcache(&fd_cache, fd)))
		return (-1);
	br = ft_getline(cache, line, fd);
	if (br == 0)
		ft_freecache(&fd_cache, fd);
	return (br);
}
