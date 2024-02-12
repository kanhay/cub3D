/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:13:12 by khanhayf          #+#    #+#             */
/*   Updated: 2024/02/06 13:39:37 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	tab_null_init(char **tab, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
		tab[i++] = NULL;
}

void	ft_error_exec(char *msg, t_cub *c)
{
	int	i;

	i = 0;
	write(2, "Error: ", 7);
	while (msg && msg[i])
		write(2, &msg[i++], 1);
	free_tab(c->map);
	while (c->tx && c->tx->link)
	{
		free_tab(c->tx->path);
		c->tx = c->tx->link;
	}
	mlx_destroy_image(c->mlx, c->img_ptr);
	mlx_destroy_window(c->mlx, c->win);
	exit(1);
}

void	ft_alloc_list(t_tx **t, char **p)
{
	*t = ft_malloc(sizeof(t_tx));
	(*t)->path = p;
	(*t)->img_ptr = NULL;
	(*t)->pxl_data = NULL;
	(*t)->link = NULL;
}

void	ft_add2list(t_tx **t, char **s)
{
	t_tx	*next;
	t_tx	*new;

	next = *t;
	while (next->link)
		next = next->link;
	new = ft_malloc(sizeof(t_tx));
	new->path = s;
	(*t)->img_ptr = NULL;
	new->pxl_data = NULL;
	new->link = NULL;
	next->link = new;
}

t_tx	*get_tex(t_cub *c, t_tx	**t)
{
	int		i;
	char	**tab;

	i = 0;
	*t = NULL;
	while (c->directions[i])
	{
		tab = ft_split(c->directions[i], ' ');
		if (i == 0)
			ft_alloc_list(t, tab);
		else
			ft_add2list(t, tab);
		i++;
	}
	ft_add2list(t, NULL);
	return (*t);
}
