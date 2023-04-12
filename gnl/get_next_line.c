/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:00:17 by diomarti          #+#    #+#             */
/*   Updated: 2022/12/07 15:11:48 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	saved[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (saved[i])
			saved[i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (saved[0] || read(fd, saved, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, saved);
		if (ft_clear(saved))
			break ;
	}
	return (line);
}

/* int main()
{
	int fd = 0;
	char *to_free;
	fd = open("./teste.txt", O_RDWR);
	to_free = get_next_line(fd);
	printf("%s", to_free);
	close(fd);
} */