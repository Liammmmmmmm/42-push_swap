/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:39:43 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/06 14:35:08 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort_forward(int *stack_a, int rst, int *sorted)
{
	int	i;

	i = -1;
	while (++i < rst - 1)
	{
		if (get_number_a(stack_a, 0) > get_number_a(stack_a, 1))
		{
			sa(stack_a, 1);
			*sorted = 0;
		}
		ra(1);
	}
}

static void	bubble_sort_backward(int *stack_a, int i, int *sorted)
{
	while (i-- > 0)
	{
		if (get_number_a(stack_a, 0) > get_number_a(stack_a, 1))
		{
			sa(stack_a, 1);
			*sorted = 0;
		}
		rra(1);
	}
}

void	bubble_sort(int *stack_a)
{
	int	rst;
	int	sorted;

	rst = len_a(-1);
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		bubble_sort_forward(stack_a, rst, &sorted);
		bubble_sort_backward(stack_a, rst - 1, &sorted);
		rst--;
	}
}
