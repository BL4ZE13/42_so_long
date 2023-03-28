/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:47:25 by diomarti          #+#    #+#             */
/*   Updated: 2022/11/09 15:37:51 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	len_str;
	char	*ptr;

	len_str = ft_strlen(str);
	if (start > len_str)
	{
		ptr = malloc(sizeof(char));
		*ptr = 0;
		return (ptr);
	}
	if (len >= len_str)
		len = len_str - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	return (ft_memcpy(ptr, &str[start], len));
}
