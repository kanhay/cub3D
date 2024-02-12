/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:45:30 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/10 11:41:15 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_var_dda(t_cub *cub)
{
	cub->steps = 0;
	cub->dda_x1 = 0;
	cub->dda_y1 = 0;
	cub->dda_dx = 0;
	cub->dda_dy = 0;
	cub->ddax_inc = 0;
	cub->dday_inc = 0;
	cub->dda_curr_x = 0;
	cub->dda_curr_y = 0;
}

double	get_angle(t_cub *cub)
{
	double	angle;

	angle = 0;
	if (cub->p_direction == 'N')
		angle = 3 * M_PI / 2;
	else if (cub->p_direction == 'S')
		angle = M_PI / 2;
	else if (cub->p_direction == 'W')
		angle = M_PI;
	else if (cub->p_direction == 'E')
		angle = 0;
	return (angle);
}

void	init_var(t_cub *cub)
{
	cub->rl = false;
	cub->ud = false;
	cub->r = false;
	cub->rl_move = 0;
	cub->fb_move = 0;
	cub->rotate = 0;
	cub->rotationspeed = (3 * M_PI) / 180;
	cub->ray_angle = 0;
}
