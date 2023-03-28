/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:45:05 by diomarti          #+#    #+#             */
/*   Updated: 2022/11/09 13:59:37 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	size_t			len_str;

	str = (unsigned char *)s;
	i = 0;
	len_str = ft_strlen((const char *)str);
	if (n == 0)
		return (NULL);
	if (c == 0)
		return (&str[len_str]);
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*vai procurar se na string exite o caractere c se sim 
return para a posicao onde encontrou*/