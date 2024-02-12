/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:14:50 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/07 15:12:39 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

char	*ft_strchr(char *str, int c)
{
	char	*p;
	int		i;

	if (!str)
		return (NULL);
	p = (char *)str;
	i = 0;
	while (p[i])
	{
		if (p[i] == (char)c)
			return (&p[i]);
		i++;
	}
	if (p[i] == (char)c)
		return (&p[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		l1;
	int		l2;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!p)
		return (0);
	ft_memcpy(p, s1, l1);
	ft_memcpy(p + l1, s2, l2 + 1);
	free(s1);
	return (p);
}

char	*ft_substr(char *s, unsigned int first, size_t len)
{
	char			*sub;
	size_t			i;
	unsigned int	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (len > l)
		len = l;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (*s && i < len && first <= l)
		sub[i++] = s[first++];
	sub[i] = '\0';
	return (sub);
}

char	*ft_toread(char *str, int fd)
{
	int		nbytes;
	char	*save;

	save = (char *)malloc(BUFFER_SIZE + 1);
	if (!save)
		return (NULL);
	nbytes = 1;
	while (nbytes > 0 && !(ft_strchr(str, '\n')))
	{
		nbytes = read(fd, save, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free (save);
			free (str);
			return (NULL);
		}
		save[nbytes] = '\0';
		if (nbytes == 0)
			break ;
		str = ft_strjoin(str, save);
	}
	free (save);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*s;
	static char		*p;
	char			*line;
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = p;
	s = ft_toread(s, fd);
	if (!s)
		return (p = NULL, NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	line = ft_substr(s, 0, i + 1);
	if (s[i] == '\0' || (s[i] == '\n' && s[i + 1] == '\0'))
		p = NULL;
	else if (s[i++] == '\n')
		p = ft_substr(s, i, ft_strlen(s) - i);
	free (s);
	return (line);
}
