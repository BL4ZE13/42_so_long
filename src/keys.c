/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:39:43 by diomarti          #+#    #+#             */
/*   Updated: 2023/03/28 17:00:53 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int handle_keys(int o, t_vars *vars)
{
	if (o == XK_Escape)
		ft_close(vars);
	else if (o == XK_w)
		move_front();
	else if (o == XK_s)
		move_back();
	else if (o == XK_d)
		move_right();
	else if (o == XK_a)
		move_left();
	else if (o == XK_Shift_L)
		ft_sprint();
	return (1);
	

}
