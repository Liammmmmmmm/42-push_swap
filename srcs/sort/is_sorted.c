/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:55:08 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/10 16:50:14 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *stack_a)
{
	int	i;

	i = 0;
	while (i < len_a(-1) - 1)
	{
		if (get_number_a(stack_a, i) > get_number_a(stack_a, i + 1))
			return (0);
		i++;
	}
	return (1);
}
