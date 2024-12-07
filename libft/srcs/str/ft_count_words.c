/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:48:39 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/07 16:48:45 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *str, char c)
{
	int		is_new_word;
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	is_new_word = 1;
	while (str[i])
	{
		if (str[i] == c && is_new_word == 0)
			is_new_word = 1;
		else if (str[i] != c && is_new_word == 1)
		{
			is_new_word = 0;
			count++;
		}
		i++;
	}
	return (count);
}
