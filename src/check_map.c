/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:43:45 by diomarti          #+#    #+#             */
/*   Updated: 2023/05/07 20:06:57 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_sides(t_map map)
{
	int	i;

	i = 0;
	while (i < map.map_h)
	{
		if (map.mat[i][0] != '1' || map.mat[i][map.map_w - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_up_down(t_map map)
{
	int	i;

	i = 0;
	while (i < map.map_w - 1)
	{
		if (map.mat[0][i] != '1' || map.mat[map.map_h - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_rect(t_map map)
{
	if (map.map_h == map.map_w)
		return (0);
	return (1);
}

int	check_elements(t_map map, char c)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (i < map.map_h)
	{
		j = 0;
		while (j < map.map_w - 1)
		{
			if (map.mat[i][j] == c)
				counter++;
			if (map.mat[i][j] != '1' && map.mat[i][j] != '0' && \
				map.mat[i][j] != 'C' && map.mat[i][j] != 'E' && \
				map.mat[i][j] != 'P' && map.mat[i][j] != 'X')
				return (0);
			j++;
		}
		i++;
	}
	return (counter);
}

int	check_all(t_map map)
{
	if (!check_rect(map))
	{
		ft_putstr_fd("The map is not rectangle!\n", 2);
		return (0);
	}
	else if (!check_up_down(map) || !check_sides(map))
	{
		ft_putstr_fd("The map is not closed!\n", 2);
		return (0);
	}
	else if (!check_elements(map, 'C'))
	{
		ft_putstr_fd("Theres no collectables or invalid elements!\n", 2);
		return (0);
	}
	else if (!check_elements(map, 'P') || !check_elements(map, 'E'))
	{
		ft_putstr_fd("theres no Player or Exit!\n", 2);
		return (0);
	}
	return (1);
}
