/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:59:19 by diomarti          #+#    #+#             */
/*   Updated: 2022/11/09 14:08:49 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		s_len;
	char	*str;

	s_len = ft_strlen(s);
	str = malloc(s_len + 1);
	if (str == NULL)
		return (0);
	ft_memcpy(str, (void *)s, ft_strlen(s) + 1);
	return (str);
}

/*vai duplicar a string para dentro da mem
alocada*/
