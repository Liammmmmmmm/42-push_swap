/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:28:28 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/28 17:27:49 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_nl_pos(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] && str[pos] != '\n')
		pos++;
	if (str[pos] == 0)
		return (-1);
	return (pos);
}

static char	*joinbuffer(char *actual, char *buffer, int *stop)
{
	int		nl;
	char	*res;

	if (ft_sstrlen(buffer) == 0)
		return (NULL);
	nl = get_nl_pos(buffer);
	if (nl == -1)
		return (ft_strjoin_limited(actual, buffer, ft_sstrlen(buffer)));
	else
	{
		res = ft_strjoin_limited(actual, buffer, nl + 1);
		if (!res)
			return (NULL);
		ft_memmove(buffer, buffer + nl + 1, ft_sstrlen(buffer + nl + 1) + 1);
		*stop = 1;
		return (res);
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];
	char		*res;
	int			count;
	int			stop;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	count = -1;
	stop = 0;
	res = joinbuffer(NULL, buffer[fd], &stop);
	while (count != 0 && stop == 0)
	{
		count = read(fd, buffer[fd], BUFFER_SIZE);
		if (count < 0)
			buffer[fd][0] = 0;
		if (count < 0)
			return (free(res), NULL);
		buffer[fd][count] = 0;
		if (count == 0)
			return (res);
		res = joinbuffer(res, buffer[fd], &stop);
		if (!res)
			return (NULL);
	}
	return (res);
}
