/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:50:28 by iassafe           #+#    #+#             */
/*   Updated: 2024/01/24 20:09:30 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_var_rl(int keycode, t_cub *cub)
{
	if (keycode == 2)
		cub->rl_move = 1;
	else
		cub->rl_move = -1;
	cub->rl = true;
}

void	init_var_fb(int keycode, t_cub*cub)
{
	if (keycode == 13)
		cub->fb_move = 1;
	else
		cub->fb_move = -1;
	cub->ud = true;
}

void	init_var_rot(int keycode, t_cub *cub)
{
	if (keycode == 124)
		cub->rl_move = 1;
	else
		cub->rl_move = -1;
	cub->r = true;
}

int	keypressed(int keycode, t_cub *cub)
{
	if (keycode == 53)
		ft_esc(cub);
	if (keycode == 0 || keycode == 2)
		init_var_rl(keycode, cub);
	if (keycode == 13 || keycode == 1)
		init_var_fb(keycode, cub);
	if (keycode == 124 || keycode == 123)
		init_var_rot(keycode, cub);
	return (0);
}

int	keyreleased(int keycode, t_cub *cub)
{
	if (keycode == 0 || keycode == 2)
		cub->rl = false;
	if (keycode == 13 || keycode == 1)
		cub->ud = false;
	if (keycode == 124 || keycode == 123)
		cub->r = false;
	return (0);
}
