/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:03:20 by diomarti          #+#    #+#             */
/*   Updated: 2023/03/28 13:21:54 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void data_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 720, 800, "so_long");
}

int ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int main(void)
{
	t_vars vars;

	data_init(&vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_hook(vars.win, 2, 1l << 0, handle_keys, &vars);
	mlx_loop(vars.mlx);
		
}

