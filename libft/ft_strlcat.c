/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:45:37 by diomarti          #+#    #+#             */
/*   Updated: 2022/11/09 15:11:10 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	i = 0;
	if (dlen >= size)
		return (size + slen);
	while (src[i] != '\0' && dlen + 1 < size)
	{			
		dst[dlen] = src[i];
		i++;
		dlen++;
	}
	dst[dlen] = '\0';
	return (dlen + ft_strlen(&src[i]));
}

/*se o tamanho so dest for maior ou igual ao do size
vai dar return do size mais o tamanho da src
se n, vai passar size bites da src para o dest e 
vai dar retrun ao tamanho do dest + o q resta do src*/
