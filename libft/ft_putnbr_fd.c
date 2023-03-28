/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:34:17 by diomarti          #+#    #+#             */
/*   Updated: 2022/11/09 13:42:39 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	c = n + 48;
	if (n >= INT_MIN && n <= INT_MAX)
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else if (n == -2147483648)
		{
			write(fd, "-", 1);
			write(fd, "2", 1);
			write(fd, "147483648", 9);
		}
		else if (n < 0)
		{
			n = -n;
			write(fd, "-", 1);
			ft_putnbr_fd(n, fd);
		}
		else
			write(fd, &c, 1);
	}
}
