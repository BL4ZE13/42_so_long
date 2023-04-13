/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:09:02 by diomarti          #+#    #+#             */
/*   Updated: 2023/04/13 12:00:13 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_lines(char *path)
{
	int		lines;
	int		fd;
	char	buff;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(write(2, "Invalid fd!\n", 12));
	lines = 0;
	while (read(fd, &buff, 1))
		if (buff == '\n')
			lines++;
	close(fd);
	return (lines);
}

t_map	get_map(char *path)
{
	int i;
	int fd;
	t_map map;

	map.map_h = map_lines(path);
	map.mat = malloc((map.map_h + 1) * sizeof(char *));
	fd = open(path, O_RDONLY);
	if (map.map_h < 2 || !map.mat || fd < 0)
	{
		ft_putstr_fd("Error creating map!\n", 1);
		free_map(&map);
		if (fd != -1)
			close(fd);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < map.map_h)
	{
		map.mat[i] = get_next_line(fd);
		i++;
	}
	map.mat[i] = NULL;
	map.map_w = ft_strlen(map.mat[0]) - 1;
	close(fd);
	return (map);
}

void	free_map(t_map *map)
{
	free(map->mat);
}

t_map create_map(char *path)
{
	t_map	map;
	
	if (ft_strncmp(path + ft_strlen(path) - 4, ".ber", 4))
	{
		ft_putstr_fd("Error! Invalid file type!\n", 2);
		exit(EXIT_FAILURE);
	}
	map = get_map(path);
	if (!check_all(map))
	{
		ft_putstr_fd("INVALID MAP!\n", 2);
		free_map(&map);
		exit(EXIT_FAILURE);
	}
	else
		ft_putstr_fd("VALID MAP!\n", 1);
	return (map);
}