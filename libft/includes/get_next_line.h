/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:15:57 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/02 11:35:02 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef MAX_FD
#  define MAX_FD 128
# endif

# include "libft.h"

/**
 * @brief Get the next line from a file descriptor
 * 
 * The get next line function reads at each call the next line from a given file
 * descriptor. It can manage multiple file descriptors at the same time, 
 * limited by the MAX_FD macro. The function have an undefined behaviour if the
 * file is closed without have been totaly read.
 * 
 * @param fd The file descriptor to read from
 * @return char* The next line read from the file descriptor
 */
char	*get_next_line(int fd);

char	*ft_strjoin_limited(char *s1, char *s2, size_t s2limit);

#endif