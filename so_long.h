/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:53:42 by diomarti          #+#    #+#             */
/*   Updated: 2023/03/28 17:03:33 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "mlx_linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>

//structs

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_player
{
	int pos_x;
	int pos_y;
	
}			t_player;

// main
int ft_close(t_vars *vars);

// KEYS
int		handle_keys(int o, t_vars *vars);
void	move_front();
void	move_back();
void	move_right();
void	move_left();
void	ft_sprint();

#endif