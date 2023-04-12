/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:52:41 by diomarti          #+#    #+#             */
/*   Updated: 2023/04/05 10:57:26 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_steps()
{
	char	*steps;
	char	*str;
	
	steps = ft_itoa((*all()).steps + 1);
	str = ft_strjoin("steps: ", steps);
	(*all()).steps++;
	mlx_clear_window((*all()).mlx, (*all()).win);
	mlx_string_put((*all()).mlx, (*all()).win, 50, 50, 0x00FF0000, str);
	free(steps);
	free(str);
}
