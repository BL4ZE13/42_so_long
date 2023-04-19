/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:39:43 by diomarti          #+#    #+#             */
/*   Updated: 2023/04/19 15:16:32 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int handle_keys(int o)
{
	if (o == XK_Escape)
		ft_close();
	else if (o == XK_w)
		move_front();
	else if (o == XK_s)
		move_back();
	else if (o == XK_d)
		move_right();
	else if (o == XK_a)
		move_left();
	mlx_clear_window((*all()).mlx, (*all()).win);
	put_images((*all()).map.mat, (*all()));
	return (1);
	

}
