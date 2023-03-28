/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:25:59 by diomarti          #+#    #+#             */
/*   Updated: 2022/11/09 15:31:31 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_len;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s_len = ft_strlen(s1);
	while (s_len && ft_strchr(set, s1[s_len]))
		s_len--;
	return (ft_substr(s1, 0, s_len + 1));
}

/*vai se dar um separador e a funcao vai eliminar td
ate ao primeiro separador e td o q esta para a
frente do segundo
ex: s1 = www.google.com, set = '.'
res: google*/
