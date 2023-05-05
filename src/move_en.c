/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_en.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:45:03 by diomarti          #+#    #+#             */
/*   Updated: 2023/05/05 11:21:06 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_player find_en(char **map)
{
	t_player coords;
	
	coords.y = 0;
	while (map[coords.y])
	{
		coords.x = 0;
		while (map[coords.y][coords.x])
		{
			if (map[coords.y][coords.x] == 'X')
				return (coords);
			coords.x++;
		}
		coords.y++;
	}
	return (coords);
}

int check_colision_en(char **map, int x, int y, char c)
{
	t_player en;

	en = find_en(map);
	if (map[en.y + y][en.x + x] == c)
		return (1);
	return (0);	
}

void move_en(char **map, int x, int y)
{
    t_player en;
    
    en = find_en(map);
    if (check_colision_en(map, x, y, 'P'))
        exit_game("YOU LOSE!!!");
    else if(!check_colision(map, x, y, '1') && !check_colision(map, x, y, 'C') && \
        !check_colision(map, x, y, 'E'))
    {
        while (map[en.x - 1][en.y] != '1')
        {
            map[en.x][en.y] = '0';
            map[en.x - 1][en.y] = 'X';
        }
        while (map[en.x + 1][en.y] != '1')
        {
            map[en.x][en.y] = '0';
            map[en.x + 1][en.y] = 'X';
        }
    }
}

int en(t_all *all)
{
    int i;
    t_player en;

    en = find_en(all->map.mat);
    i = 0;
    while (i < all->nbr_en)
        move_en(all->map.mat, en.x, en.y);
    mlx_clear_window(all->mlx, all->win);
    put_images(all->map.mat, *all);
    mlx_key_hook(all->win, handle_keys, NULL);
    return (0);
}