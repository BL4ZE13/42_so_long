/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:13:13 by diomarti          #+#    #+#             */
/*   Updated: 2023/04/19 12:40:11 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    choose_image(t_images img)

void    put_images(char **map, t_images img)
{
    int i;
    int j;
    
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j] != '\n')
        {
            choose_image(img);
            j++;
        }
        i++;
    }
    print;

    
}