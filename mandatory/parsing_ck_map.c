/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ck_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:22:08 by khanhayf          #+#    #+#             */
/*   Updated: 2024/02/08 15:45:05 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_zero_sides(t_cub *c)
{
	int	i;
	int	j;

	i = -1;
	while (c->map[++i])
	{
		j = -1;
		while (c->map[i][++j])
		{
			if (i == 0 || !c->map[i + 1] || c->map[i][j + 1] == '\0')
				break ;
			if (j == 0)
				j++;
			if (ft_strchr("NSEW0", c->map[i][j])
			&& (ft_strchr(" \t", c->map[i + 1][j])
			|| ft_strchr(" \t", c->map[i - 1][j])
			|| ft_strchr(" \t", c->map[i][j + 1])
			|| ft_strchr(" \t", c->map[i][j - 1])))
				ft_error("Invalid map, space near a char\n", c);
		}
	}
}

void	count_char(char ch, t_cub *c, int i)
{
	if (i == 0)
	{
		c->n_nbr = 0;
		c->s_nbr = 0;
		c->e_nbr = 0;
		c->w_nbr = 0;
	}
	else if (i == 1)
	{
		if (ch == 'N')
			c->n_nbr++;
		else if (ch == 'S')
			c->s_nbr++;
		else if (ch == 'E')
			c->e_nbr++;
		else if (ch == 'W')
			c->w_nbr++;
	}
	else
	{
		if (c->n_nbr + c->s_nbr + c->e_nbr + c->w_nbr != 1)
			ft_error("Invalid map; char prob\n", c);
	}
}

void	fst_lst_line(char *s, t_cub *c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_strchr("1 \t", s[i]))
			ft_error("Invalid map; fst or lst line\n", c);
		i++;
	}
}

void	fst_lst_char(char *s, t_cub *c)
{
	unsigned int	i;

	i = 0;
	while (s[i] && ft_strchr(" \t", s[i]))
		i++;
	if (s[i] == '\0')
		return ;
	if (s[i] != '1')
		ft_error("Strange char starts or ends a line\n", c);
	i = c->col_nb - 1;
	while (i > 0 && (ft_strchr(" \t", s[i])))
		i--;
	if (s[i] != '1')
		ft_error("Strange char starts or ends a line\n", c);
}

void	check_map_char(t_cub *c)
{
	if (!c->map)
		ft_error("Invalid map\n", c);
	count_char('c', c, 0);
	c->i = -1;
	while (c->map && c->map[++c->i])
	{
		c->j = 0;
		if (c->i == 0 || !c->map[c->i + 1])
			fst_lst_line(c->map[c->i], c);
		else
		{
			fst_lst_char(c->map[c->i], c);
			while (c->map[c->i][c->j])
			{
				if (!ft_strchr("01NSEW\n ", c->map[c->i][c->j]))
					ft_error("Invalid map; strange char\n", c);
				if (ft_strchr("NSEW", c->map[c->i][c->j]))
					count_char(c->map[c->i][c->j], c, 1);
				c->j++;
			}
		}
	}
	count_char(c->map[0][0], c, 2);
}
