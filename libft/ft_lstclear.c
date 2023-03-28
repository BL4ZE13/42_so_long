/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:19:16 by diomarti          #+#    #+#             */
/*   Updated: 2022/11/09 15:57:54 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*lst1;

	if (!*lst || !lst)
		return ;
	while (*lst)
	{
		lst1 = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst1;
	}
	lst = 0;
}

/*vai dar free a lista*/
