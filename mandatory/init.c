/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:45:30 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/05 18:05:45 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
