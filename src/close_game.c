/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:15:57 by diomarti          #+#    #+#             */
/*   Updated: 2023/04/19 15:28:08 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_close()
{
	mlx_destroy_window((*all()).mlx, (*all()).win);
	mlx_destroy_display((*all()).mlx);
	free((*all()).mlx);
	exit(0);
}