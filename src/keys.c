/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:39:43 by diomarti          #+#    #+#             */
/*   Updated: 2023/04/20 13:04:26 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int handle_keys(int o)
{
	if (o == XK_Escape)
		ft_close();
	else if (o == XK_w)
		move_player((*all()).map.mat, 0, 1);
	else if (o == XK_s)
		move_player((*all()).map.mat, 0, -1);
	else if (o == XK_d)
		move_player((*all()).map.mat, 0, 1);
	else if (o == XK_a)
		move_player((*all()).map.mat, 0, -1);
	mlx_clear_window((*all()).mlx, (*all()).win);
	put_images((*all()).map.mat, (*all()));
	return (1);
	

}
