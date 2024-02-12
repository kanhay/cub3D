/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:54:42 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/08 10:44:49 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_right_left(t_cub *cub)
{
	float	x;
	float	y;
	float	step_move;

	x = cub->p_x;
	y = cub->p_y;
	step_move = cub->rl_move * MOVE_SPEED;
	x += (step_move * cos(cub->rotationangle + (M_PI / 2)));
	y += (step_move * sin(cub->rotationangle + (M_PI / 2)));
	if (has_wall_coll(cub, x, y))
		return ;
	cub->p_x = x;
	cub->p_y = y;
}

void	move_backward_forward(t_cub *cub)
{
	float	x;
	float	y;
	float	step_move;

	x = cub->p_x;
	y = cub->p_y;
	step_move = cub->fb_move * MOVE_SPEED;
	x += (step_move * cos(cub->rotationangle));
	y += (step_move * sin(cub->rotationangle));
	if (has_wall_coll(cub, x, y))
		return ;
	cub->p_x = x;
	cub->p_y = y;
}

void	rotation(t_cub *cub)
{
	cub->rotationangle += (cub->rl_move * cub->rotationspeed);
	cub->rotationangle = normalize_angle(cub->rotationangle);
}

void	cast_all_rays(t_cub *cub)
{
	int		i;

	i = 0;
	cub->ray_angle = cub->rotationangle - ((FOV_ANGLE * M_PI / 180) / 2);
	cub->num_rays = WIDTH / WALL_STRIP_WIDTH;
	while (i < cub->num_rays)
	{
		cub->ray_angle = normalize_angle(cub->ray_angle);
		ft_raycasting(cub, i);
		cub->ray_angle += ((FOV_ANGLE * M_PI / 180) / cub->num_rays);
		i++;
	}
}

int	update(t_cub *cub)
{
	if (cub->rl)
		move_right_left(cub);
	if (cub->ud)
		move_backward_forward(cub);
	if (cub->r)
		rotation(cub);
	mlx_clear_window(cub->mlx, cub->win);
	cast_all_rays(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img_ptr, 0, 0);
	return (0);
}
