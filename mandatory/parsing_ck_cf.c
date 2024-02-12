/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ck_cf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:07:03 by khanhayf          #+#    #+#             */
/*   Updated: 2024/02/08 15:45:46 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_rgb(t_cub *c, char **cf)
{
	int		i;
	char	*s;
	char	**t;

	i = 0;
	while (i < 2 && cf[i])
	{
		s = ft_substr(cf[i], 2, ft_strlen(cf[i]));
		t = ft_split(s, ',');
		if (cf[i][0] == 'F')
			c->f_rgb = ft_atoi(t[0]) << 16 | ft_atoi(t[1]) << 8 | ft_atoi(t[2]);
		else
			c->c_rgb = ft_atoi(t[0]) << 16 | ft_atoi(t[1]) << 8 | ft_atoi(t[2]);
		free(s);
		free_tab(t);
		i++;
	}
}

void	count_comma(char *s, t_cub *cub)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (s && s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i] == ',')
			c++;
		i++;
	}
	if (!s || c != 2)
		ft_error("Invalid F or C identifier\n", cub);
}

void	check_cf(t_cub *c)
{
	int		i;
	int		j;
	char	*s;
	char	**rgb;

	i = -1;
	while (c->cf && c->cf[++i])
	{
		if ((ft_memcmp(c->cf[i], "C ", 2) && ft_memcmp(c->cf[i], "F ", 2))
			|| (i == 0 && !ft_memcmp(c->cf[i], c->cf[i + 1], 2)))
			ft_error("Invalid F or C identifier\n", c);
		count_comma(c->cf[i], c);
		s = ft_substr(c->cf[i], 2, (ft_strlen(c->cf[i])));
		rgb = ft_split(s, ',');
		j = 0;
		while (j < 3)
		{
			if (!rgb[j] || ft_atoi(rgb[j++]) == -1)
				return (free(s), free_tab(rgb), \
				ft_error("Invalid F or C id\n", c));
		}
		free(s);
		free_tab(rgb);
	}
}
