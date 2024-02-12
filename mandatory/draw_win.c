/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:17:11 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/06 15:59:34 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_pixel_put(t_cub *cub, int y, int x, int color)
{
	int		pos;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pos = ((y * cub->size_line) + (x * (cub->bpp / 8)));
	*(unsigned int *)(cub->img_data + pos) = color;
}

void	put_image(t_cub *c)
{
	c->img_ptr = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	if (!c->img_ptr)
		return (free_tab(c->map), mlx_destroy_window(c->mlx, c->win), exit(1));
	c->img_data = mlx_get_data_addr(c->img_ptr, &(c->bpp),
			&(c->size_line), &(c->endian));
	if (!c->img_data)
	{
		mlx_destroy_image(c->mlx, c->img_ptr);
		mlx_destroy_window(c->mlx, c->win);
		return (free_tab(c->map), exit(1));
	}
}
