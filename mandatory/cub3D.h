/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:10:24 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/10 20:28:41 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"
# include <math.h>
# include <stdbool.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# define WIDTH 1200
# define HEIGHT 720
# define TILE_SIZE 32
# define MOVE_SPEED 2
# define WALL_STRIP_WIDTH 1
# define FOV_ANGLE 60

typedef struct texture_s
{
	char				**path;
	void				*img_ptr;
	int					*pxl_data;
	int					bpp;
	int					size_line;
	int					endian;
	int					w;
	int					h;
	struct texture_s	*link;
}	t_tx;

typedef struct s_cub
{
	float	correct_wall_dist;
	float	dist_proj_plane;
	float	wall_strip_height;

	bool	right;
	bool	left;
	bool	up;
	bool	down;

	float	num_rays;
	bool	was_vertical;
	float	wall_x;
	float	wall_y;
	float	distance;
	float	horz_wall_x;
	float	horz_wall_y;
	float	vert_wall_x;
	float	vert_wall_y;
	float	x_step;
	float	y_step;
	bool	found_horz_wall;
	bool	found_vert_wall;
	double	ray_angle;

	bool	rl;
	bool	ud;
	bool	r;

	int		bpp;
	int		size_line;
	int		endian;

	int		rl_move;
	int		fb_move;
	int		rotate;
	double	rotationangle;
	double	rotationspeed;

	char	p_direction;
	float	p_x;
	float	p_y;

	void	*win;
	void	*mlx;
	void	*img_ptr;
	char	*img_data;

	char	**directions;
	int		n_nbr;
	int		s_nbr;
	int		e_nbr;
	int		w_nbr;

	char	**map;
	int		row_nb;
	int		col_nb;

	char	**cf;
	int		f_rgb;
	int		c_rgb;

	int		tex_offsetx;
	int		tex_offsety;
	t_tx	*tx;

	int		i;
	int		j;
	float	y_start;
	float	y_end;
	int		fd;
}			t_cub;

//parsing
char	**ft_split(char *s, char c);
long	ft_atoi(char *str);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, int c);
char	*ft_substr(char *s, unsigned int first, size_t len);
int		ft_memcmp(void *ptr1, void *ptr2, int s);
void	*ft_memcpy(void *dest, const void *src, int n);
void	*ft_malloc(size_t size);
void	ft_read_map(t_cub *cub);
void	check_dir(t_cub *c);
void	check_cf(t_cub *c);
void	check_map_char(t_cub *c);
void	check_zero_sides(t_cub *c);
void	get_rgb(t_cub *c, char **cf);
void	free_tab(char **tab);
void	ft_error(char *msg, t_cub *c);
void	ft_error_exec(char *msg, t_cub *c);
bool	check_extension(char *s, char *ext);
void	tab_null_init(char **tab, int nb);
void	tab2map(char **tab, t_cub *c);
void	_is_empty(char *s, t_cub *c);
t_tx	*get_tex(t_cub *c, t_tx	**t);
void	alloc2_dircf(t_cub *c);
int		map_line_nb(char **tab, t_cub *c);
bool	has_newline(char *s);

//draw
void	put_image(t_cub *c);
void	my_pixel_put(t_cub *cub, int y, int x, int color);

//init 
void	init_var(t_cub *cub);
double	get_angle(t_cub *cub);

//moves
int		keyreleased(int keycode, t_cub *cub);
int		keypressed(int keycode, t_cub *cub);
int		update(t_cub *cub);

//player
void	pos_player(t_cub *cub);
void	direction_player(t_cub *cub);

//exit
int		ft_exit(t_cub *cub);
void	ft_esc(t_cub *cub);

//raycasting
void	ft_raycasting(t_cub *cub, int i);
void	intersection_horizontal(t_cub *c);
void	intersection_vertical(t_cub *c);
void	init_var_intercept(t_cub *cub);
double	normalize_angle(double angle);
void	init_var_raycasting(t_cub *cub);
void	smallest_value(t_cub *cub);
bool	has_wall(t_cub *cub, float x, float y);
bool	has_wall_coll(t_cub *cub, float x, float y);

//walls
void	rendering_walls(t_cub *c, float x);

#endif
