/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:24:32 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/05 17:39:08 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**free_memory(char **p)
{
	size_t	n;

	n = 0;
	while (p[n])
	{
		free(p[n]);
		n++;
	}
	free(p);
	return (NULL);
}

static size_t	nbword(char const *str, char c)
{
	int		i;
	size_t	counter;

	counter = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i + 1] == '\0' || (str[i] == c && str[i + 1] != c))
			counter++;
		i++;
	}
	return (counter);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	char	**split;
	size_t	k;
	size_t	start;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	split = (char **)malloc((nbword(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (i < nbword(s, c) && s[k])
	{
		while (s[k] == c)
			k++;
		start = k;
		while (s[k] != c && s[k])
			k++;
		split[i] = ft_substr(s, start, k - start);
		if (split[i++] == NULL)
			return (free_memory(split));
	}
	split[i] = NULL;
	return (split);
}
