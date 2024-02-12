/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:19:33 by khanhayf          #+#    #+#             */
/*   Updated: 2024/02/06 18:05:58 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	*ft_malloc(size_t size)
{
	void	*p;

	p = NULL;
	p = malloc(size);
	if (!p)
	{
		write(2, "Allocation prob\n", 16);
		exit (1);
	}
	return (p);
}

void	free_tab(char **tab)
{
	int	i;

	if (tab != NULL)
	{
		i = 0;
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

void	ft_error(char *msg, t_cub *c)
{
	int	i;

	i = 0;
	write(2, "Error: ", 7);
	while (msg[i])
		write(2, &msg[i++], 1);
	free_tab(c->directions);
	free_tab(c->cf);
	free_tab(c->map);
	exit(1);
}

void	_is_empty(char *s, t_cub *c)
{
	if (s[0] == '\n')
		ft_error("Invalid map; empty line\n", c);
}
