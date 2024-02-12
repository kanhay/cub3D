/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:33:45 by khanhayf          #+#    #+#             */
/*   Updated: 2024/02/07 19:33:47 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_raycasting(t_cub *cub, int i)
{
	init_var_raycasting(cub);
	init_var_intercept(cub);
	cub->horz_wall_x = 0;
	cub->horz_wall_y = 0;
	cub->found_horz_wall = false;
	intersection_horizontal(cub);
	init_var_intercept(cub);
	cub->vert_wall_x = 0;
	cub->vert_wall_y = 0;
	cub->found_vert_wall = false;
	intersection_vertical(cub);
	cub->was_vertical = false;
	smallest_value(cub);
	rendering_walls(cub, i * WALL_STRIP_WIDTH);
}

void	ft_draw(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (free_tab(cub->map), exit(1));
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3D");
	if (!cub->win)
		return (free_tab(cub->map), exit(1));
	put_image(cub);
	pos_player(cub);
	direction_player(cub);
	cub->rotationangle = get_angle(cub);
	init_var(cub);
	file2img(cub);
	mlx_hook(cub->win, 2, 0, &keypressed, cub);
	mlx_hook(cub->win, 3, 0, &keyreleased, cub);
	mlx_loop_hook(cub->mlx, &update, cub);
	mlx_mouse_move(cub->win, WIDTH / 2, HEIGHT / 2);
	mlx_mouse_get_pos(cub->win, &cub->mouse_x, &cub->mouse_y);
	mlx_hook(cub->win, 6, 0, mouse_rotation, cub);
	mlx_hook(cub->win, 17, 0, ft_exit, cub);
	mlx_loop(cub->mlx);
}

t_tx	*ft_parsing(char *av, t_cub *c, t_tx *t)
{
	c->cf = NULL;
	c->directions = NULL;
	c->map = NULL;
	c->fd = open(av, O_RDONLY);
	if (c->fd < 0)
		return (write(2, "Error opening file\n", 19), exit(1), NULL);
	ft_read_map(c);
	check_dir(c);
	check_cf(c);
	check_map_char(c);
	check_zero_sides(c);
	t = get_tex(c, &t);
	free_tab(c->directions);
	get_rgb(c, c->cf);
	free_tab(c->cf);
	close(c->fd);
	return (t);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (write(2, "Invalid number of arguments\n", 28), 1);
	if (check_extension(av[1], ".cub"))
		return (write(2, "Invalid extension\n", 18), 1);
	cub.tx = ft_parsing(av[1], &cub, NULL);
	cub.mouse_key = 0;
	cub.openning = false;
	ft_draw(&cub);
}
