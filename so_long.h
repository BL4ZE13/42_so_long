/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:53:42 by diomarti          #+#    #+#             */
/*   Updated: 2023/04/20 13:06:49 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "get_next_line.h"
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
	t_map		map;
	void		*mlx;
	void		*win;
	void		*wall;
	void		*flor;
	void		*pl_c;
	void		*pl_u;
	void		*pl_d;
	void		*pl_r;
	void		*pl_l;
	void		*col;
	void		*en;
	void		*ext;
	int			steps;

}			t_all;

// MAIN
int		ft_close();
t_all	*all(void);
void	init_img(t_all *img);


// KEYS
int		handle_keys(int o);
void	move_player(char **map, int x, int y);

// MAP
int		check_all(t_map map);
int		map_lines(char *path);
t_map	get_map(char *path);
void	free_map(t_map *map);
t_map	create_map(char *path);

//IMG
void    choose_image(char c, int x, int y, t_all img);
void	print_steps();
void    put_images(char **map, t_all img);


#endif