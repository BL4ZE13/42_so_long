/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:24:31 by diomarti          #+#    #+#             */
/*   Updated: 2023/05/08 17:14:14 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	flood_fill(int x, int y, int *flag, char **tmp)
{
	if (tmp[y][x] == '1' || tmp[y][x] == 'P' || tmp[y][x] == 'D')
		return ;
	else if (tmp[y][x] == '0')
		tmp[y][x] = 'P';
	else if (tmp[y][x] == 'C' || tmp[y][x] == 'X')
		tmp[y][x] = 'D';
	else if (tmp[y][x] == 'E')
	{
		(*flag)++;
		tmp[y][x] = 'E';
	}
	flood_fill(x + 1, y, flag, tmp);
	flood_fill(x - 1, y, flag, tmp);
	flood_fill(x, y + 1, flag, tmp);
	flood_fill(x, y - 1, flag, tmp);
}

static int	check_all_collectible(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

char **get_map_copy(void)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	// Ver protecoes de mallocs
	ret = ft_calloc((*all()).map.map_h + 1, sizeof(char *));
	while (i < (*all()).map.map_h)
	{
		ret[i] = ft_calloc((*all()).map.map_w + 1, sizeof(char));
		j = 0;
		while (j < (*all()).map.map_w)
		{
			ret[i][j] = (*all()).map.mat[i][j];
			j++;
		}
		i++;
	}
	return (ret);
}

void	free_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

int	fill_flood(void)
{
	t_player	p;
	int		flag;
	char	**map;

	flag = 0;
	map =  get_map_copy();
	p = find_player(map);
	flood_fill(p.x + 1, p.y, &flag, map);
	flood_fill(p.x - 1, p.y, &flag, map);
	flood_fill(p.x, p.y - 1, &flag, map);
	flood_fill(p.x, p.y + 1, &flag, map);
	if (flag == 0 || !check_all_collectible(map))
	{
		ft_putstr_fd("Invalid path\n", 2);
		free_matrix(map);
		return (0);
	}
	free_matrix(map);
	return (1);
}
