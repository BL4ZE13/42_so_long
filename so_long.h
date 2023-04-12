/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:53:42 by diomarti          #+#    #+#             */
/*   Updated: 2023/04/12 14:52:50 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "gnl/get_next_line.h"
#include "mlx_linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

//structs
typedef struct s_player
{
	int x;
	int y;
}			t_player;

typedef struct s_map
{
	int		map_h;
	int		map_w;
	char	**mat;

}			t_map;

typedef struct	s_all
{
	t_player	player;
	t_map		map;	
	void		*mlx;
	void		*win;
	int			steps;

}			t_all;

// MAIN
int ft_close();
t_all	*all(void);

// KEYS
int		handle_keys(int o);
void	move_front();
void	move_back();
void	move_right();
void	move_left();

// UTILS
void	print_steps();

// MAP
int check_all(t_map map);
int	map_lines(char *path);
static t_map	get_map(char *path);
void	free_map(t_map *map);
t_map create_map(char *path);

#endif