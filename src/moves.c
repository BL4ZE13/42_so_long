/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:39:39 by diomarti          #+#    #+#             */
/*   Updated: 2023/04/20 13:13:40 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_player find_player(char **map)
{
	t_player coords;
	
	coords.y = 0;
	while (map[coords.y])
	{
		coords.x = 0;
		while (map[coords.y][coords.x])
		{
			if (map[coords.y][coords.x] == 'P')
				return (coords);
			coords.x++;
		}
		coords.y++;
	}
	return (coords);
}

int check_colision(char **map, int x, int y, char c)
{
	t_player p;

	if (map[p.y + y][p.x + x] == c)
		return (1);
	return (0);	
}

void	move_player(char **map, int x, int y)
{
	t_player p;

	p = find_player(map);
	if (x > 0)
		(*all()).pl_c = (*all()).pl_r;
	if (x < 0)
		(*all()).pl_c = (*all()).pl_l;
	if (y > 0)
		(*all()).pl_c = (*all()).pl_u;
	if (y < 0)
		(*all()).pl_c = (*all()).pl_d;
	if (check_colision(map, x, y, 'E'))
		exit(EXIT_SUCCESS);
	if (check_colision(map, x, y, 'X'))
		exit(EXIT_SUCCESS);

	
}
