/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:38:38 by khanhayf          #+#    #+#             */
/*   Updated: 2024/02/08 15:51:17 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	mouse_rotation(int x, int y, t_cub *c)
{
	float	step;
	float	rot;

	if (c->mouse_key % 2 == 0)
	{
		mlx_mouse_show();
		return (0);
	}
	mlx_mouse_hide();
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
	{
		c->is_centering = true;
		mlx_mouse_move(c->win, WIDTH / 2, c->mouse_y);
		mlx_mouse_get_pos(c->win, &c->mouse_x, &c->mouse_y);
		return (c->is_centering = false, 0);
	}
	if (c->is_centering == false)
	{
		step = x - c->mouse_x;
		rot = step * MOUSE_SPEED;
		c->rotationangle += rot;
		c->mouse_x = x;
		c->mouse_y = y;
	}
	return (0);
}

void	color_minimap_image(t_cub *c)
{
	c->t = TILE_SIZE;
	c->y_w = c->p_y - (MINIMAP_H / 2);
	c->y_mm = 0;
	while (c->y_mm < MINIMAP_H)
	{
		c->x_w = c->p_x - (MINIMAP_W / 2);
		c->x_mm = 0;
		while (c->x_mm < MINIMAP_W)
		{
			if ((int)(c->y_w / c->t) < 0 || (int)(c->y_w / c->t) >= c->row_nb
			|| (int)(c->x_w / c->t) < 0 || (int)(c->x_w / c->t) >= c->col_nb
			|| c->map[(int)(c->y_w / c->t)][(int)(c->x_w / c->t)] == ' ')
				my_pixel_put(c, c->y_mm, c->x_mm, 0xccb95e);
			else if (c->map[(int)(c->y_w / c->t)][(int)(c->x_w / c->t)] == '1')
				my_pixel_put(c, c->y_mm, c->x_mm, 0x929292);
			else if (c->map[(int)(c->y_w / c->t)][(int)(c->x_w / c->t)] == 'D')
				my_pixel_put(c, c->y_mm, c->x_mm, 0x587287);
			else
				my_pixel_put(c, c->y_mm, c->x_mm, 0x313131);
			c->x_w++;
			c->x_mm++;
		}
		c->y_w++;
		c->y_mm++;
	}
}

void	minimap(t_cub	*c)
{
	color_minimap_image(c);
	draw_circle(c);
	drawline(c, MINIMAP_W / 2, MINIMAP_H / 2);
	mlx_put_image_to_window(c->mlx, c->win, c->img_ptr, 0, 0);
}

bool	has_d(t_cub *cub, float x, float y)
{
	double	nextx;
	double	nexty;

	nextx = floor(x / TILE_SIZE);
	nexty = floor(y / TILE_SIZE);
	if (cub->map[(int)nexty][(int)nextx] == 'd')
		return (true);
	return (false);
}
