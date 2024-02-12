/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:57:15 by khanhayf          #+#    #+#             */
/*   Updated: 2024/02/06 12:05:05 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	alloc2_dircf(t_cub *c)
{
	c->cf = ft_malloc(sizeof(char *) * (3));
	tab_null_init(c->cf, 3);
	c->directions = ft_malloc(sizeof(char *) * (5));
	tab_null_init(c->directions, 5);
}

int	map_line_nb(char **tab, t_cub *c)
{
	c->row_nb = 0;
	while (tab[c->row_nb])
		c->row_nb++;
	return (c->row_nb);
}
