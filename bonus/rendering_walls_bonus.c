/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_walls_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:17:38 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/11 16:03:26 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_var_render_walls(t_cub *cub)
{
	cub->correct_wall_dist = cub->distance * \
	(cos(cub->ray_angle - cub->rotationangle));
	cub->dist_proj_plane = (WIDTH / 2) / tan((FOV_ANGLE * M_PI / 180) / 2);  
	cub->wall_strip_height = (TILE_SIZE / cub->correct_wall_dist) \
		* cub->dist_proj_plane;
	cub->y_start = (HEIGHT / 2) - (cub->wall_strip_height / 2);
	cub->y_end = (HEIGHT / 2) + (cub->wall_strip_height / 2);
}

t_tx	*get_texture(t_cub *c)
{
	char	ch;
	t_tx	*next;

	next = c->tx;
	if ((c->was_vertical && (has_door(c, c->wall_x + 1, c->wall_y)
				|| has_door(c, c->wall_x - 1, c->wall_y)))
		|| (!c->was_vertical && (has_door(c, c->wall_x, c->wall_y + 1)
				|| has_door(c, c->wall_x, c->wall_y - 1))))
		ch = 'D';
	else if (c->was_vertical && c->right)
		ch = 'E';
	else if (c->was_vertical && c->left)
		ch = 'W';
	else if (!c->was_vertical && c->up)
		ch = 'N';
	else if (!c->was_vertical && c->down)
		ch = 'S';
	next = c->tx;
	while (next && next->link)
	{
		if (next->path[0][0] == ch)
			return (next);
		next = next->link;
	}
	return (next);
}

void	rendering_walls(t_cub *c, float x)
{
	float	n;
	t_tx	*t;

	init_var_render_walls(c);
	t = get_texture(c);
	if (!c->was_vertical)
		c->tex_offsetx = (t->w * fmod(c->wall_x, TILE_SIZE)) / TILE_SIZE;
	else
		c->tex_offsetx = (t->h * fmod(c->wall_y, TILE_SIZE)) / TILE_SIZE;
	n = 0;
	while (n >= 0 && n < HEIGHT)
	{
		if (n < c->y_start)
			my_pixel_put(c, n, x, c->c_rgb);
		else if (n >= c->y_start && n < c->y_end)
		{
			c->tex_offsety = (t->h * (n - c->y_start)) / c->wall_strip_height;
			my_pixel_put(c, n, x, t->pxl_data[(c->tex_offsety * t->w) \
			+ c->tex_offsetx]);
		}
		else
			my_pixel_put(c, n, x, c->f_rgb);
		n++;
	}
}
