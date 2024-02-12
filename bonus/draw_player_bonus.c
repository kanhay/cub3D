/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:12:54 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/10 11:41:56 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	drawline(t_cub *cub, float x, float y)
{
	int	i;

	cub->dda_x1 = x + 16 * cos(cub->rotationangle);
	cub->dda_y1 = y + 16 * sin(cub->rotationangle);
	cub->dda_dx = cub->dda_x1 - x;
	cub->dda_dy = cub->dda_y1 - y;
	if (fabsf(cub->dda_dx) > fabsf(cub->dda_dy))
		cub->steps = fabsf(cub->dda_dx);
	else
		cub->steps = fabsf(cub->dda_dy);
	cub->ddax_inc = (float)cub->dda_dx / cub->steps;
	cub->dday_inc = (float)cub->dda_dy / cub->steps;
	cub->dda_curr_x = x;
	cub->dda_curr_y = y;
	i = 0;
	while (i < cub->steps)
	{
		cub->dda_curr_x += cub->ddax_inc;
		cub->dda_curr_y += cub->dday_inc;
		my_pixel_put(cub, cub->dda_curr_y, cub->dda_curr_x, 0xf5f6fa);
		i++;
	}
}

void	draw_circle(t_cub *cub)
{
	int		x;
	int		y;
	int		limit;

	limit = 5;
	x = MINIMAP_W / 2 - limit;
	y = MINIMAP_H / 2 - limit;
	while (y < (MINIMAP_H / 2 + limit))
	{
		x = MINIMAP_W / 2 - limit;
		while (x < (MINIMAP_W / 2 + limit))
		{
			if (sqrt(((x - MINIMAP_W / 2) * (x - MINIMAP_W / 2)) + \
			((y - MINIMAP_H / 2) * (y - MINIMAP_H / 2))) <= 4)
				my_pixel_put(cub, y, x, 0xf5f6fa);
			x++;
		}
		y++;
	}
}
