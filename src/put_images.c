/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:13:13 by diomarti          #+#    #+#             */
/*   Updated: 2023/04/21 17:19:11 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    choose_image(char c, int x, int y, t_all img)
{
	if (c == '1')
		mlx_put_image_to_window(img.mlx, img.win, img.wall, x * 64, y * 64);
	if (c == '0')
		mlx_put_image_to_window(img.mlx, img.win, img.flor, x * 64, y * 64);
	if (c == 'C')
		mlx_put_image_to_window(img.mlx, img.win, img.cl, x * 64, y * 64);
	if (c == 'P')
		mlx_put_image_to_window(img.mlx, img.win, img.pl_i, x * 64, y * 64);
	if (c == 'X')
		mlx_put_image_to_window(img.mlx, img.win, img.en, x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(img.mlx, img.win, img.ext_f, x * 64, y * 64);
}

void    put_images(char **map, t_all img)
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

void	print_steps()
{
	char	*steps;
	char	*str;
	
	steps = ft_itoa((*all()).steps);
	str = ft_strjoin("steps: ", steps);
	mlx_string_put((*all()).mlx, (*all()).win, 50, 50, 0xFFFFFFFF, str);
	free(steps);
	free(str);
}
