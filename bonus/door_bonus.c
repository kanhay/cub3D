/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:15:59 by khanhayf          #+#    #+#             */
/*   Updated: 2024/02/07 11:26:39 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

bool	has_door(t_cub *cub, float x, float y)
{
	double	nextx;
	double	nexty;

	nextx = floor(x / TILE_SIZE);
	nexty = floor(y / TILE_SIZE);
	if (cub->map[(int)nexty][(int)nextx] == 'D')
		return (true);
	return (false);
}

void	open_doors1(t_cub *c)
{
	if (c->was_vertical && has_door(c, c->p_x + TILE_SIZE, c->p_y))
	{
		c->map[(int)(c->p_y / TILE_SIZE)][(int)(c->p_x / TILE_SIZE) + 1] = 'd';
		c->openedx = c->p_x + TILE_SIZE;
		c->openedy = c->p_y;
		c->openning = true;
	}
	else if (c->was_vertical && has_door(c, c->p_x - TILE_SIZE, c->p_y))
	{
		c->map[(int)(c->p_y / TILE_SIZE)][(int)(c->p_x / TILE_SIZE) - 1] = 'd';
		c->openedx = c->p_x - TILE_SIZE;
		c->openedy = c->p_y;
		c->openning = true;
	}
}

void	open_doors(t_cub *c)
{
	if (!c->was_vertical && has_door(c, c->p_x, c->p_y - TILE_SIZE))
	{
		c->map[(int)(c->p_y / TILE_SIZE) - 1][(int)(c->p_x / TILE_SIZE)] = 'd';
		c->openedx = c->p_x;
		c->openedy = c->p_y - TILE_SIZE;
		c->openning = true;
	}
	else if (!c->was_vertical && has_door(c, c->p_x, c->p_y + TILE_SIZE))
	{
		c->map[(int)(c->p_y / TILE_SIZE) + 1][(int)(c->p_x / TILE_SIZE)] = 'd';
		c->openedx = c->p_x;
		c->openedy = c->p_y + TILE_SIZE;
		c->openning = true;
	}
	else
		open_doors1(c);
	mlx_put_image_to_window(c->mlx, c->win, c->img_ptr, 0, 0);
}

void	close_doors(t_cub *c)
{
	if (c->map[(int)c->p_y / TILE_SIZE][(int)c->p_x / TILE_SIZE] \
	!= c->map[(int)c->openedy / TILE_SIZE][(int)c->openedx / TILE_SIZE])
	{
		c->map[(int)(c->openedy / TILE_SIZE)][(int)(c->openedx \
		/ TILE_SIZE)] = 'D';
		c->openning = false;
	}
	mlx_put_image_to_window(c->mlx, c->win, c->img_ptr, 0, 0);
}
