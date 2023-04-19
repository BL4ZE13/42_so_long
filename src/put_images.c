/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:13:13 by diomarti          #+#    #+#             */
/*   Updated: 2023/04/19 13:22:51 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    choose_image(char c, int x, int y, t_images img)
{
	if (c == '1')
		mlx_put_image_to_window(img.mlx, img.win, img.wall, x, y);
	if (c == '0')
		mlx_put_image_to_window(img.mlx, img.win, img.flor, x, y);
	if (c == 'C')
		mlx_put_image_to_window(img.mlx, img.win, img.col, x, y);
	if (c == 'P')
		mlx_put_image_to_window(img.mlx, img.win, img.pl, x, y);
	if (c == 'X')
		mlx_put_image_to_window(img.mlx, img.win, img.en, x, y);
	if (c == 'E')
		mlx_put_image_to_window(img.mlx, img.win, img.ext, x, y);
}

void    put_images(char **map, t_images img)
{
    int i;
    int j;
    
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j] != '\n')
        {
            choose_image(map[i][j], j, i, img);
            j++;
        }
        i++;
    }
    print_steps();
}