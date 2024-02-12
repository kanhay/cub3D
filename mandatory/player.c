/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:23:28 by iassafe           #+#    #+#             */
/*   Updated: 2024/01/24 20:10:12 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	pos_player(t_cub *cub)
{
	int		x;
	int		y;

	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == 'N' || cub->map[y][x] == 'S' ||
				cub->map[y][x] == 'W' || cub->map[y][x] == 'E')
			{
				cub->p_x = ((x * TILE_SIZE) + (TILE_SIZE / 2));
				cub->p_y = ((y * TILE_SIZE) + (TILE_SIZE / 2));
				break ;
			}
			x++;
		}
		y++;
	}
}

void	direction_player(t_cub *cub)
{
	float	x;
	float	y;

	x = (cub->p_x - (TILE_SIZE / 2)) / TILE_SIZE;
	y = (cub->p_y - (TILE_SIZE / 2)) / TILE_SIZE;
	if (cub->map[(int)y][(int)x] == 'N')
		cub->p_direction = 'N';
	else if (cub->map[(int)y][(int)x] == 'S')
		cub->p_direction = 'S';
	else if (cub->map[(int)y][(int)x] == 'W')
		cub->p_direction = 'W';
	else if (cub->map[(int)y][(int)x] == 'E')
		cub->p_direction = 'E';
}
