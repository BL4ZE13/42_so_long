/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:38:37 by diomarti          #+#    #+#             */
/*   Updated: 2022/11/09 13:53:31 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	nmr_str(char const *str, char c)
{
	size_t	i;
	size_t	words;
	size_t	toggle;

	toggle = 0;
	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && toggle == 0)
		{
			toggle = 1;
			words++;
		}
		else if (str[i] == c)
			toggle = 0;
		i++;
	}
	return (words);
}

/*vai contar o nmr de palavras 
sempre q encontra 2 separadores seguidos
ignora e avanca na string*/

char	*new_string(const char *str, int start, int finish)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc((finish - start + 1));
	while (start < finish)
	{
		ptr[i] = str[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*vai escrever para dentro da memoria alocada
a nova palavra*/

char	**mem_alloc(char const *str, char c, char **n_str)
{
	size_t	i;
	size_t	j;
	int		ind;

	j = 0;
	i = 0;
	ind = -1;
	while (i <= ft_strlen(str))
	{
		if (str[i] != c && ind < 0)
			ind = i;
		else if ((str[i] == c || i == ft_strlen(str)) && ind >= 0)
		{
			n_str[j] = new_string(str, ind, i);
			j++;
			ind = -1;
		}
		i++;
	}
	n_str[j] = 0;
	return (n_str);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	ptr = malloc((nmr_str(s, c) + 1) * sizeof(char *));
	if (!ptr || !s)
		return (NULL);
	return (mem_alloc(s, c, ptr));
}

/*ptr vai estar a alocar mem para tds as string
que vao existir*/
