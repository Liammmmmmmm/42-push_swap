/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:40:03 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/05 15:15:22 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int *stack, int len)
{
	int i;
	int minv = 2147483647;

	i = 0;
	while (i < len)
	{
		if (stack[i] < minv)
			minv = stack[i];
		i++;
	}
	return (minv);
}

int	max(int *stack, int len)
{
	int i;
	int maxv = -2147483648;

	i = 0;
	while (i < len)
	{
		if (stack[i] < maxv)
			maxv = stack[i];
		i++;
	}
	return (maxv);
}

int	find_quickest_b(int *stack_b, int actual_index, int number)
{
	int	up;
	int	down;

	up = 0;
	down = 0;
	while (get_number_b(stack_b, actual_index + up) != number)
	{
		if (up > len_b(-1))
			return (0);
		up++;
	}
	while (get_number_b(stack_b, actual_index - down) != number)
	{
		if (down > len_b(-1))
			return (0);
		down++;
	}
	if (down < up)
		return (RRB);
	return (RB);
}
