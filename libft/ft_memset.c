/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:45:23 by diomarti          #+#    #+#             */
/*   Updated: 2022/11/09 14:02:05 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!s && c == 0)
		return (NULL);
	while (i < n)
	{
		((unsigned char *) s)[i] = c;
		i++;
	}
	return (s);
}

/*vai substituir n bytes do s pelo caractere c*/