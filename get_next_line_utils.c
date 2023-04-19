/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:55:31 by araymond          #+#    #+#             */
/*   Updated: 2023/02/16 11:30:47 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char *s, size_t n)
{
	size_t	i;
	char	*str;

	if (!s)
		return ;
	i = 0;
	str = s;
	while (i < n)
	{
		if (str[i] != 0)
			str[i] = 0;
		i++;
	}
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*s;

	s = (char *)malloc(count * size);
	if (!s)
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}

char	*ft_strchr(char *s, int c)
{
	char	a;

	if (!s)
		return (NULL);
	a = c;
	while (*s && *s != a)
		s++;
	if (*s == a)
		return (s);
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	if (!s2 || !s1)
	{
		if (s1)
			free(s1);	
		return (NULL);
	}
	new = ft_calloc(sizeof(*new), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	free(s1);
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
