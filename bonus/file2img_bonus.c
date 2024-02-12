/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:26:05 by khanhayf          #+#    #+#             */
/*   Updated: 2024/02/07 20:01:12 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	door_file2img(t_tx *door, t_cub *c)
{
	door->img_ptr = mlx_xpm_file_to_image(c->mlx, DOOR, &door->w, &door->h);
	if (!door->img_ptr)
		ft_error_exec("mlx_xpm_door_file2img failed\n", c);
	door->pxl_data = (int *)mlx_get_data_addr(door->img_ptr, &door->bpp, \
	&door->size_line, &door->endian);
	if (!door->pxl_data)
	{
		mlx_destroy_image(c->mlx, door->img_ptr);
		ft_error_exec("mlx_door_get_data_addr failed\n", c);
	}
}

void	file2img(t_cub *c)
{
	t_tx	*n;

	n = c->tx;
	while (n && n->link)
	{
		n->img_ptr = mlx_xpm_file_to_image(c->mlx, n->path[1], &n->w, &n->h);
		if (!n->img_ptr)
			ft_error_exec("mlx_xpm_dir_tex_file_2_img failed\n", c);
		n->pxl_data = (int *)mlx_get_data_addr(n->img_ptr, &n->bpp, \
		&n->size_line, &n->endian);
		if (!n->pxl_data)
		{
			mlx_destroy_image(c->mlx, n->img_ptr);
			ft_error_exec("mlx_get_data_addr failed\n", c);
		}
		n = n->link;
	}
	door_file2img(n, c);
}
