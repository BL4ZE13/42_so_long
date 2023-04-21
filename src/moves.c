/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:39:39 by diomarti          #+#    #+#             */
/*   Updated: 2023/04/21 17:42:55 by diomarti         ###   ########.fr       */
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

	p = find_player(map);
	if (map[p.y + y][p.x + x] == c)
		return (1);
	return (0);	
}

void	move_player(char **map, int x, int y)
{
	t_player p;

	p = find_player(map);
	if (x > 0)
		(*all()).pl_i = (*all()).pl_r;
	if (x < 0)
		(*all()).pl_i = (*all()).pl_l;
	if (y > 0)
		(*all()).pl_i = (*all()).pl_d;
	if (y < 0)
		(*all()).pl_i = (*all()).pl_u;
	if (check_colision(map, x, y, 'E') && (*all()).nbr_cl == 0)
		exit_game("WON");
	if (check_colision(map, x, y, 'X'))
		exit_game("LOSE");
	if (!check_colision(map, x, y, '1') && !check_colision(map, x, y, 'X'))
	{
		if (check_colision(map, x, y, 'C'))
			(*all()).nbr_cl--;
		// if ((*all()).nbr_cl == 0)
		// 	(*all()).ext_f = (*all()).ext_a;
		if (!check_colision(map, x, y, 'E'))
		{
			map[p.y][p.x] = '0';
			map[p.y + y][p.x + x] = 'P';
			(*all()).steps++;
		}
	}	
}
