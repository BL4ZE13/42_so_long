/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:03:20 by diomarti          #+#    #+#             */
/*   Updated: 2023/04/05 15:08:48 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_all	*all(void)
{
	static t_all	all;

	return (&all);
}

int main(int ac, char **av)
{
	if (ac < 2)
		exit(write(2, "Error\n", 6));
	(*all()).mlx = mlx_init();
	(*all()).win = mlx_new_window((*all()).mlx, 720, 800, "so_long");
	mlx_hook((*all()).win, 17, 0, ft_close, NULL);
	mlx_hook((*all()).win, 2, 1L<<0, handle_keys, NULL);
	//mlx_key_hook((*all()).win, handle_keys, NULL);
	mlx_loop((*all()).mlx);
	return (0);
}

