/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_en.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:45:03 by diomarti          #+#    #+#             */
/*   Updated: 2023/05/07 20:30:06 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// t_player	find_en(char **map, int n)
// {
// 	t_player	coords;
//     int j;

// 	coords.y = 0;
//     j = 0;
// 	while (map[coords.y])
// 	{
// 		coords.x = 0;
// 		while (map[coords.y][coords.x])
// 		{
// 			if (map[coords.y][coords.x] == 'X' && n == j)
// 				return (coords);
//             if (map[coords.y][coords.x] == 'X')
//                 j++;
// 			coords.x++;
// 		}
// 		coords.y++;
// 	}
// 	return (coords);
// }

// int check_colision_en(char **map, t_player coords, char c, int n)
// {
// 	t_player en;

// 	en = find_en(map, n);
// 	if (map[en.y + coords.y][en.x + coords.x] == c)
// 		return (1);
// 	return (0);	
// }

// void choose_en_move(t_player *coords)
// {
//     int nb;

//     nb = rand() % 2 + 1;
//     if (nb == 1)
//         coords->x = 1;
//     if (nb == 2)
//         coords->x = -1;
// }

// void move_en(char **map, int n)
// {
//     t_player en;
//     t_player move;

//     move.x = 0;
//     move.y = 0;
//     choose_en_move(&move);
//     en = find_en(map, n);
//     if (check_colision_en(map, move, 'P', n))
//         exit_game("YOU LOSE!!!\n");
//     else if(!check_colision_en(map,
// move, '1', n) && 
//     !check_colision_en(map, move, 'C', n) &&
//     !check_colision_en(map, move, 'E', n))
//     {
//         map[en.y][en.x] = '0';
//         map[en.y + move.y][en.x + move.x] = 'X';
//     }
// }

// int en(t_all *all)
// {
//     int n;
//     static int delay;

//     n = 0;
//     if (delay < 3000)
//     {
//         delay++;
//         return (0);
//     }
//     move_en(all->map.mat, n);
//     mlx_clear_window(all->mlx, all->win);
//     put_images(all->map.mat, *all);
//     mlx_key_hook(all->win, handle_keys, NULL);
//     delay = 0;
//     return (0);
// }