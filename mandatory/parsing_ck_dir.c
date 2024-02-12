/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ck_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:02:19 by khanhayf          #+#    #+#             */
/*   Updated: 2024/02/08 15:46:29 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_extension(char *s, char *ext)
{
	int		len;
	char	*s1;

	len = ft_strlen(s);
	s1 = ft_substr(s, len - 4, 4);
	if (len <= 4 || ft_memcmp(s1, ext, 5))
		return (free(s1), 1);
	return (free(s1), 0);
}

void	check_path(char *path, t_cub *c)
{
	char	*p;

	if (!path)
		ft_error("Invalid Dir identifiers\n", c);
	p = ft_substr(path, 0, ft_strlen(path));
	if (check_extension(path, ".xpm") || !p || open(p, O_RDONLY) < 0)
		return (free(p), ft_error("The texture path is not valid\n", c));
	free(p);
}

void	tab_comp(t_cub *c)
{
	int	i;
	int	j;

	i = -1;
	while (c->directions[++i])
	{
		j = -1;
		while (++j < 4)
		{
			if (j != i && !ft_memcmp(c->directions[i], c->directions[j], 3))
				ft_error("Invalid Dir identifiers\n", c);
		}
	}
}

void	check_dir(t_cub *c)
{
	char	*s;
	char	**dir;

	c->i = -1;
	while (c->directions && c->directions[++c->i])
	{
		tab_comp(c);
		s = ft_substr(c->directions[c->i], 0, 3);
		dir = ft_split(c->directions[c->i], ' ');
		if (!ft_memcmp(s, "NO ", 3) || !ft_memcmp(s, "N ", 2))
			check_path(dir[1], c);
		else if (!ft_memcmp(s, "SO ", 3) || !ft_memcmp(s, "S ", 2))
			check_path(dir[1], c);
		else if (!ft_memcmp(s, "WE ", 3) || !ft_memcmp(s, "W ", 2))
			check_path(dir[1], c);
		else if (!ft_memcmp(s, "EA ", 3) || !ft_memcmp(s, "E ", 2))
			check_path(dir[1], c);
		else
			return (free(s), free_tab(dir), ft_error("Invalid Dir id\n", c));
		free(s);
		free_tab(dir);
	}
}

void	tab2map(char **tab, t_cub *c)
{
	int	len;

	c->j = -1;
	while (tab[++c->j])
	{
		if (((int)ft_strlen(tab[c->j]) - 1) > c->col_nb)
		{
			c->col_nb = ft_strlen(tab[c->j]);
			if (has_newline(tab[c->j]))
				c->col_nb--;
		}
	}
	c->j = 0;
	while (tab[c->j])
	{
		len = ft_strlen(tab[c->j]);
		if (!tab[c->j + 1])
			len = ft_strlen(tab[c->j]) + 1;
		c->map[c->j] = ft_malloc(c->col_nb + 1);
		ft_memcpy(c->map[c->j], tab[c->j], len - 1);
		c->i = len - 1;
		while (c->i < c->col_nb)
			c->map[c->j][c->i++] = ' ';
		c->map[c->j++][c->col_nb] = '\0';
	}
}
