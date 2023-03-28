/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:41:27 by diomarti          #+#    #+#             */
/*   Updated: 2022/11/09 13:42:24 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digit_counter(int n)
{
	if (n > 0)
		return (0);
	return (1);
}

int	is_neg(int n)
{
	if (n > 0)
		return (1);
	return (-1);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	num;
	size_t	len;

	num = (long)n * is_neg(n);
	len = digit_counter(n);
	while (n)
	{
		n /= 10;
		len++;
	}
	res = malloc(len + 1);
	if (!res)
		return (0);
	res[len--] = '\0';
	while (num > 0)
	{
		res[len--] = num % 10 + 48;
		num /= 10;
	}
	if (len == 0 && res[1] == '\0')
		res[0] = 48;
	else if (len == 0 && res[1] != '\0')
		res[0] = '-';
	return (res);
}
