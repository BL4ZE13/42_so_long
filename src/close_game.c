/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:15:57 by diomarti          #+#    #+#             */
/*   Updated: 2023/05/08 17:18:30 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(void)
{
	mlx_destroy_image((*all()).mlx, (*all()).wall);
	mlx_destroy_image((*all()).mlx, (*all()).flor);
	mlx_destroy_image((*all()).mlx, (*all()).pl_d);
	mlx_destroy_image((*all()).mlx, (*all()).pl_l);
	mlx_destroy_image((*all()).mlx, (*all()).pl_r);
	mlx_destroy_image((*all()).mlx, (*all()).pl_u);
	mlx_destroy_image((*all()).mlx, (*all()).cl);
	mlx_destroy_image((*all()).mlx, (*all()).ext_f);
	mlx_destroy_image((*all()).mlx, (*all()).c_bd);
	mlx_destroy_image((*all()).mlx, (*all()).c_be);
	mlx_destroy_image((*all()).mlx, (*all()).c_cd);
	mlx_destroy_image((*all()).mlx, (*all()).c_ce);
	mlx_destroy_image((*all()).mlx, (*all()).b_b);
	mlx_destroy_image((*all()).mlx, (*all()).b_c);
	mlx_destroy_image((*all()).mlx, (*all()).b_e);
	mlx_destroy_image((*all()).mlx, (*all()).b_d);
	free_map(&((*all()).map));
	mlx_destroy_window((*all()).mlx, (*all()).win);
	mlx_destroy_display((*all()).mlx);
	free((*all()).mlx);
	exit(EXIT_SUCCESS);
}

void	exit_game(char *str)
{
	mlx_destroy_image((*all()).mlx, (*all()).pl_d);
	mlx_destroy_image((*all()).mlx, (*all()).pl_l);
	mlx_destroy_image((*all()).mlx, (*all()).pl_r);
	mlx_destroy_image((*all()).mlx, (*all()).pl_u);
	mlx_destroy_image((*all()).mlx, (*all()).c_bd);
	mlx_destroy_image((*all()).mlx, (*all()).c_be);
	mlx_destroy_image((*all()).mlx, (*all()).c_cd);
	mlx_destroy_image((*all()).mlx, (*all()).c_ce);
	mlx_destroy_image((*all()).mlx, (*all()).b_b);
	mlx_destroy_image((*all()).mlx, (*all()).b_c);
	mlx_destroy_image((*all()).mlx, (*all()).b_e);
	mlx_destroy_image((*all()).mlx, (*all()).b_d);
	if (check_elements((*all()).map, 'X'))
		mlx_destroy_image((*all()).mlx, (*all()).en);
	mlx_destroy_image((*all()).mlx, (*all()).wall);
	mlx_destroy_image((*all()).mlx, (*all()).flor);
	mlx_destroy_image((*all()).mlx, (*all()).cl);
	mlx_destroy_image((*all()).mlx, (*all()).ext_f);
	free_map(&((*all()).map));
	mlx_destroy_window((*all()).mlx, (*all()).win);
	mlx_destroy_display((*all()).mlx);
	free((*all()).mlx);
	ft_putstr_fd(str, 1);
	exit(EXIT_SUCCESS);
}
