/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:03:20 by diomarti          #+#    #+#             */
/*   Updated: 2023/05/08 17:17:34 by diomarti         ###   ########.fr       */
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
	int	i;

	img->wall = mlx_xpm_file_to_image(img->mlx, "img/parede.xpm", &i, &i);
	img->flor = mlx_xpm_file_to_image(img->mlx, "img/floor.xpm", &i, &i);
	img->cl = mlx_xpm_file_to_image(img->mlx, "img/moeda.xpm", &i, &i);
	img->en = mlx_xpm_file_to_image(img->mlx, "img/en.xpm", &i, &i);
	img->pl_u = mlx_xpm_file_to_image(img->mlx, "img/pl_u.xpm", &i, &i);
	img->pl_d = mlx_xpm_file_to_image(img->mlx, "img/pl_d.xpm", &i, &i);
	img->pl_l = mlx_xpm_file_to_image(img->mlx, "img/pl_l.xpm", &i, &i);
	img->pl_r = mlx_xpm_file_to_image(img->mlx, "img/pl_r.xpm", &i, &i);
	img->ext_f = mlx_xpm_file_to_image(img->mlx, "img/porta.xpm", &i, &i);
	img->c_cd = mlx_xpm_file_to_image(img->mlx, "img/c_cd.xpm", &i, &i);
	img->c_ce = mlx_xpm_file_to_image(img->mlx, "img/c_ce.xpm", &i, &i);
	img->c_bd = mlx_xpm_file_to_image(img->mlx, "img/c_bd.xpm", &i, &i);
	img->c_be = mlx_xpm_file_to_image(img->mlx, "img/c_be.xpm", &i, &i);
	img->b_b = mlx_xpm_file_to_image(img->mlx, "img/b_b.xpm", &i, &i);
	img->b_c = mlx_xpm_file_to_image(img->mlx, "img/b_c.xpm", &i, &i);
	img->b_e = mlx_xpm_file_to_image(img->mlx, "img/b_e.xpm", &i, &i);
	img->b_d = mlx_xpm_file_to_image(img->mlx, "img/b_d.xpm", &i, &i);
	img->pl_i = img->pl_r;
	img->nbr_cl = check_elements(img->map, 'C');
	img->nbr_en = check_elements(img->map, 'X');
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit(write(2, "Error\n", 6));
	(*all()).map = create_map(av[1]);
	(*all()).mlx = mlx_init();
	if (!fill_flood())
		return (0);
	init_img(all());
	(*all()).win = mlx_new_window((*all()).mlx, (*all()).map.map_w * 64,
			(*all()).map.map_h * 64, "so_long");
	mlx_hook((*all()).win, 17, 1, ft_close, NULL);
	mlx_hook((*all()).win, 2, 1L << 0, handle_keys, NULL);
	put_images((*all()).map.mat, (*all()));
	mlx_loop((*all()).mlx);
	return (0);
}
