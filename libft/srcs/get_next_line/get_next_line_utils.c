/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:18:36 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/28 17:24:50 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strdup_limited(char *str, size_t max)
{
	size_t	len;
	char	*res;

	len = ft_sstrlen(str);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, str, max + 1);
	return (res);
}

void	ft_strlcat_simplified(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;

	if (size == 0)
		return ;
	dest_len = ft_sstrlen(dest);
	i = 0;
	while (src[i] && dest_len + i < size - 1)
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
}

char	*ft_strjoin_limited(char *s1, char *s2, size_t s2limit)
{
	size_t	s1_len;
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup_limited(s2, s2limit));
	s1_len = ft_sstrlen(s1);
	new_str = malloc(sizeof(char) * (s1_len + s2limit + 1));
	if (!new_str)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcat_simplified(new_str, s2, s1_len + s2limit + 1);
	free(s1);
	return (new_str);
}
