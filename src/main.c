/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:03:20 by diomarti          #+#    #+#             */
/*   Updated: 2023/04/20 13:07:22 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_all	*all(void)
{
	static t_all	all;

	return (&all);
}

void	init_img(t_all *img)
{
	int i;
	
	img->wall = mlx_xpm_file_to_image(img->mlx, "images/wall.xpm", &i, &i);
	img->flor = mlx_xpm_file_to_image(img->mlx, "images/wall.xpm", &i, &i);
	img->col = mlx_xpm_file_to_image(img->mlx, "images/wall.xpm", &i, &i);
	img->en = mlx_xpm_file_to_image(img->mlx, "images/wall.xpm", &i, &i);
	img->pl_u = mlx_xpm_file_to_image(img->mlx, "images/wall.xpm", &i, &i);
	img->pl_d = mlx_xpm_file_to_image(img->mlx, "images/wall.xpm", &i, &i);
	img->pl_l = mlx_xpm_file_to_image(img->mlx, "images/wall.xpm", &i, &i);
	img->pl_r = mlx_xpm_file_to_image(img->mlx, "images/wall.xpm", &i, &i);
	img->ext = mlx_xpm_file_to_image(img->mlx, "images/wall.xpm", &i, &i);
	img->pl_c = img->pl_u;

	
}

int main(int ac, char **av)
{
	// (void)ac;
	// (void)av;
	if (ac != 2)
		exit(write(2, "Error\n", 6));
	(*all()).map = create_map(av[1]);
	(*all()).mlx = mlx_init();
	init_img(all());
	(*all()).win = mlx_new_window((*all()).mlx, (*all()).map.map_w * 64, (*all()).map.map_h * 64, "so_long");
	mlx_hook((*all()).win, 17, 1, ft_close, NULL);
	mlx_hook((*all()).win, 2, 1L<<0, handle_keys, NULL);
	put_images((*all()).map.mat, (*all()));
	mlx_loop((*all()).mlx);
	return (0);
}

