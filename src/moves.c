/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:39:39 by diomarti          #+#    #+#             */
/*   Updated: 2023/05/07 20:25:06 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_player	find_player(char **map)
{
	t_player	coords;

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

int	check_colision(char **map, int x, int y, char c)
{
	t_player	p;

	p = find_player(map);
	if (map[p.y + y][p.x + x] == c)
		return (1);
	return (0);
}

void	select_move(int x, int y)
{
	if (x > 0)
		(*all()).pl_i = (*all()).pl_r;
	if (x < 0)
		(*all()).pl_i = (*all()).pl_l;
	if (y > 0)
		(*all()).pl_i = (*all()).pl_d;
	if (y < 0)
		(*all()).pl_i = (*all()).pl_u;
}

void	move_player(char **map, int x, int y)
{
	t_player	p;

	p = find_player(map);
	select_move(x, y);
	if (check_colision(map, x, y, 'E') && (*all()).nbr_cl == 0)
		exit_game("YOU WON!!!\n");
	if (check_colision(map, x, y, 'X'))
		exit_game("YOU LOSE!!!\n");
	if (!check_colision(map, x, y, '1') && !check_colision(map, x, y, 'X'))
	{
		if (check_colision(map, x, y, 'C'))
			(*all()).nbr_cl--;
		if (!check_colision(map, x, y, 'E'))
		{
			map[p.y][p.x] = '0';
			map[p.y + y][p.x + x] = 'P';
			(*all()).steps++;
		}
	}
}
