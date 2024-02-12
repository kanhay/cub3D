/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_raycast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:46:10 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/08 17:05:35 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	has_wall_coll(t_cub *cub, float x, float y)
{
	double	nextx;
	double	nexty;

	if (x < 0 || x >= (cub->col_nb * TILE_SIZE) || y < 0
		|| y >= (cub->row_nb * TILE_SIZE))
		return (true);
	nextx = floor(x / TILE_SIZE);
	nexty = floor(y / TILE_SIZE);
	if (cub->map[(int)nexty][(int)nextx] == '1'
		|| (cub->map[(int)(cub->p_y / TILE_SIZE)][(int)nextx] == '1'
		&& cub->map[(int)nexty][(int)(cub->p_x / TILE_SIZE)] == '1'))
		return (true);
	return (false);
}

bool	has_wall(t_cub *cub, float x, float y)
{
	double	nextx;
	double	nexty;

	if (x < 0 || x >= (cub->col_nb * TILE_SIZE) || y < 0
		|| y >= (cub->row_nb * TILE_SIZE))
		return (true);
	nextx = floor(x / TILE_SIZE);
	nexty = floor(y / TILE_SIZE);
	if (cub->map[(int)nexty][(int)nextx] == '1')
		return (true);
	return (false);
}

void	init_var_raycasting(t_cub *cub)
{
	cub->wall_x = 0;
	cub->wall_y = 0;
	cub->right = false;
	cub->left = false;
	cub->up = false;
	cub->down = false;
	if (cub->ray_angle > 0 && cub->ray_angle <= M_PI)
		cub->down = true;
	else
		cub->up = true;
	if ((cub->ray_angle >= (1.5 * M_PI))
		|| cub->ray_angle < (0.5 * M_PI))
		cub->right = true;
	else
		cub->left = true;
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

void	init_var_intercept(t_cub *cub)
{
	cub->x_step = 0;
	cub->y_step = 0;
}
