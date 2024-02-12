/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intercept.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:41:14 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/07 20:00:19 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_cor_wall(t_cub *cub, float x, float y, int flag)
{
	if (flag == 0)
	{
		cub->found_horz_wall = true;
		cub->horz_wall_x = x;
		cub->horz_wall_y = y;
	}
	else
	{
		cub->found_vert_wall = true;
		cub->vert_wall_x = x;
		cub->vert_wall_y = y;
	}
}

void	init_step_horizontal(t_cub *cub)
{
	cub->y_step = TILE_SIZE;
	if (cub->up == true)
		cub->y_step *= -1;
	cub->x_step = TILE_SIZE / tan(cub->ray_angle);
	if (cub->left == true && cub->x_step > 0)
		cub->x_step *= -1;
	if (cub->right == true && cub->x_step < 0)
		cub->x_step *= -1;
}

void	intersection_horizontal(t_cub *c)
{
	float	x_i;
	float	y_i;

	y_i = floor(c->p_y / TILE_SIZE) * TILE_SIZE;
	if (c->down == true)
		y_i += TILE_SIZE;
	x_i = c->p_x + ((y_i - c->p_y) / tan(c->ray_angle));
	init_step_horizontal(c);
	while (x_i >= 0 && x_i < (c->col_nb * TILE_SIZE) && y_i >= 0
		&& y_i < (c->row_nb * TILE_SIZE))
	{
		if (has_wall(c, x_i, y_i - c->up)
			|| has_wall(c, x_i - 0.001, y_i - c->up))
		{
			init_cor_wall(c, x_i, y_i, 0);
			break ;
		}
		else
		{
			x_i += c->x_step;
			y_i += c->y_step;
		}
	}
}

void	init_step_vertical(t_cub *cub)
{
	cub->x_step = TILE_SIZE;
	if (cub->left == true)
		cub->x_step *= -1;
	cub->y_step = TILE_SIZE * tan(cub->ray_angle);
	if (cub->up == true && cub->y_step > 0)
		cub->y_step *= -1;
	if (cub->down == true && cub->y_step < 0)
		cub->y_step *= -1;
}

void	intersection_vertical(t_cub *c)
{
	float	x_i;
	float	y_i;

	x_i = floor(c->p_x / TILE_SIZE) * TILE_SIZE;
	if (c->right == true)
		x_i += TILE_SIZE;
	y_i = c->p_y + ((x_i - c->p_x) * tan(c->ray_angle));
	init_step_vertical(c);
	while (x_i >= 0 && x_i < (c->col_nb * TILE_SIZE)
		&& y_i >= 0 && y_i < (c->row_nb * TILE_SIZE))
	{
		if (has_wall(c, x_i - c->left, y_i)
			|| has_wall(c, x_i - c->left, y_i - 0.001))
		{
			init_cor_wall(c, x_i, y_i, 1);
			break ;
		}
		else
		{
			x_i += c->x_step;
			y_i += c->y_step;
		}
	}
}
