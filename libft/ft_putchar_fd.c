/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:09:27 by diomarti          #+#    #+#             */
/*   Updated: 2022/11/09 13:38:49 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd == -1)
		return ;
	write(fd, &c, 1);
}

/*fd - 0 vai ler no input
fd - 1 vai escrever no output
fd - 2 erros*/