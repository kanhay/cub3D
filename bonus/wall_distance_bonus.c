/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_distance_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:50:35 by iassafe           #+#    #+#             */
/*   Updated: 2024/01/24 20:07:56 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

float	get_distance(t_cub *cub, float x, float y)
{
	float	distance;

	distance = sqrt(((x - cub->p_x) * (x - cub->p_x))
			+ ((y - cub->p_y) * (y - cub->p_y)));
	return (distance);
}

void	smallest_value(t_cub *cub)
{
	float	horz_dist;
	float	vert_dist;

	if (cub->found_horz_wall == true)
		horz_dist = get_distance(cub, cub->horz_wall_x, cub->horz_wall_y);
	else
		horz_dist = INT_MAX;
	if (cub->found_vert_wall == true)
		vert_dist = get_distance(cub, cub->vert_wall_x, cub->vert_wall_y);
	else
		vert_dist = INT_MAX;
	if (horz_dist < vert_dist)
	{
		cub->wall_x = cub->horz_wall_x;
		cub->wall_y = cub->horz_wall_y;
		cub->distance = horz_dist;
	}
	else
	{
		cub->wall_x = cub->vert_wall_x;
		cub->wall_y = cub->vert_wall_y;
		cub->distance = vert_dist;
		cub->was_vertical = true;
	}
}
