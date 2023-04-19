/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:39:39 by diomarti          #+#    #+#             */
/*   Updated: 2023/04/19 16:08:29 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_front()
{
	(*all()).steps += 1;
	print_steps();
}

void	move_back()
{
	(*all()).steps += 1;
	print_steps();
}

void	move_right()
{
	(*all()).steps += 1;
	print_steps();
}

void	move_left()
{
	(*all()).steps += 1;
	print_steps();
}
