/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:33:45 by khanhayf          #+#    #+#             */
/*   Updated: 2024/02/07 19:35:03 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	rendering_walls(cub, i);
}

void	file2img(t_cub *c)
{
	t_tx	*n;

	n = c->tx;
	while (n)
	{
		n->img_ptr = mlx_xpm_file_to_image(c->mlx, n->path[1], &n->w, &n->h);
		if (!n->img_ptr)
			ft_error_exec("mlx_xpm_file_2_img failed\n", c);
		n->pxl_data = (int *)mlx_get_data_addr(n->img_ptr, \
		&n->bpp, &n->size_line, &n->endian);
		if (!n->pxl_data)
		{
			mlx_destroy_image(c->mlx, n->img_ptr);
			ft_error_exec("mlx_get_data_addr failed\n", c);
		}
		n = n->link;
	}
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
	ft_draw(&cub);
}
