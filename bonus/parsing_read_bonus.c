/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_read_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:39:18 by khanhayf          #+#    #+#             */
/*   Updated: 2024/02/08 10:17:56 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	map_getter(int fd, char *line, t_cub *c)
{
	int		j;
	char	**tab;

	if (!c->cf || !c->directions)
		ft_error("Invalid map\n", c);
	c->col_nb = 0;
	tab = ft_malloc(sizeof(char *) * (257));
	tab_null_init(tab, 257);
	j = 0;
	while (j < 257 && line)
	{
		_is_empty(line, c);
		tab[j] = ft_malloc(sizeof(char) * ft_strlen(line) + 1);
		ft_memcpy(tab[j], line, ft_strlen(line) + 1);
		free(line);
		line = get_next_line(fd);
		j++;
	}
	free(line);
	if (has_newline(tab[j - 1]))
		ft_error("New line ends the map\n", c);
	c->map = ft_malloc(sizeof(char *) * (map_line_nb(tab, c) + 1));
	tab_null_init(c->map, (map_line_nb(tab, c) + 1));
	tab2map(tab, c);
	free_tab(tab);
}

void	alloc2_dircf(t_cub *c)
{
	c->cf = ft_malloc(sizeof(char *) * (3));
	tab_null_init(c->cf, 3);
	c->directions = ft_malloc(sizeof(char *) * (5));
	tab_null_init(c->directions, 5);
}

void	tab2_dir_cf(char **tab, t_cub *c)
{
	int	k;

	c->i = -1;
	c->j = 0;
	k = 0;
	alloc2_dircf(c);
	while (tab && tab[++c->i])
	{
		if (c->j < 4 && ft_strchr("NSEW", tab[c->i][0]))
		{
			c->directions[c->j] = ft_malloc(ft_strlen(tab[c->i]) + 1);
			ft_memcpy(c->directions[c->j], tab[c->i], ft_strlen(tab[c->i]) + 1);
			c->j++;
		}
		else if (k < 2 && ft_strchr("CF", tab[c->i][0]))
		{
			c->cf[k] = ft_malloc(ft_strlen(tab[c->i]) + 1);
			ft_memcpy(c->cf[k], tab[c->i], ft_strlen(tab[c->i]) + 1);
			k++;
		}
		else
			return (free_tab(tab), ft_error("Invalid map\n", c));
	}
	if (c->j != 4 || k != 2)
		return (free_tab(tab), ft_error("Invalid map\n", c));
}

void	getter(int fd, char *line, t_cub *c)
{
	int		j;
	char	**tab;
	int		len;

	tab = ft_malloc(sizeof(char *) * (7));
	tab_null_init(tab, 7);
	j = 0;
	while (j < 6 && line)
	{
		if (line[0] != '\n')
		{
			len = ft_strlen(line);
			if (has_newline(line))
				len--;
			tab[j] = ft_malloc(sizeof(char) * (len + 1));
			ft_memcpy(tab[j], line, len);
			tab[j][len] = '\0';
			j++;
		}
		free(line);
		if (j != 6)
			line = get_next_line(fd);
	}
	tab2_dir_cf(tab, c);
	free_tab(tab);
}

void	ft_read_map(t_cub *cub)
{
	char	*line;
	bool	f;

	f = false;
	line = get_next_line(cub->fd);
	if (!line)
		return (write(2, "Empty file\n", 11), exit(1));
	while (line)
	{
		if (line[0] != '\n')
		{
			if (!f && ft_strchr("NSEWCF", line[0]))
			{
				getter(cub->fd, line, cub);
				f = true;
			}
			else if (ft_strchr("1 ", line[0]))
				map_getter(cub->fd, line, cub);
			else
				return (free(line), ft_error("Invalid map\n", cub));
		}
		else
			free(line);
		line = get_next_line(cub->fd);
	}
}
