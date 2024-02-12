/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:15:13 by iassafe           #+#    #+#             */
/*   Updated: 2024/01/24 20:10:23 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_memcmp(void *ptr1, void *ptr2, int s)
{
	char	*p1;
	char	*p2;

	p1 = (char *)ptr1;
	p2 = (char *)ptr2;
	if (s == 0)
		return (0);
	while (s-- > 1)
	{
		if (*p1 == *p2)
		{
			p1++;
			p2++;
		}
	}
	return (*p1 - *p2);
}

void	*ft_memcpy(void *dest, const void *src, int n)
{
	char	*d;
	char	*s;
	int		i;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

long	ft_atoi(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	if (str[i] == '\0')
		return (-1);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '\0')
		return (-1);
	while (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		r = (r * 10) + (str[i++] - 48);
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] || r > 255)
		return (-1);
	return (r);
}
