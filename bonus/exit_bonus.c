/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:02:10 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/06 12:09:34 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_exit(t_cub *cub)
{
	t_tx	*next;

	free_tab(cub->map);
	next = cub->tx;
	while (next && next->link)
	{
		free_tab(next->path);
		next = next->link;
	}
	mlx_destroy_image(cub->mlx, cub->img_ptr);
	mlx_destroy_window(cub->mlx, cub->win);
	exit(0);
}

void	ft_esc(t_cub *cub)
{
	t_tx	*next;

	free_tab(cub->map);
	next = cub->tx;
	while (next && next->link)
	{
		free_tab(next->path);
		next = next->link;
	}
	mlx_destroy_image(cub->mlx, cub->img_ptr);
	mlx_destroy_window(cub->mlx, cub->win);
	exit(0);
}
