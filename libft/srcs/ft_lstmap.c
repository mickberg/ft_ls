/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:53:53 by mberglun          #+#    #+#             */
/*   Updated: 2019/11/12 18:54:41 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nitem;
	t_list	*nlist;

	nitem = f(lst);
	if (nitem == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (nitem);
	else
	{
		nlist = ft_lstmap(lst->next, f);
		if (!nlist)
			return (NULL);
		ft_lstadd(&nlist, nitem);
		return (nlist);
	}
}
