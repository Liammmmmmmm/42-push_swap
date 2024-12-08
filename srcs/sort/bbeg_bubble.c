/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbeg_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:12:23 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/08 17:27:00 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chose_better_swap(int *stack_a, int *stack_b)
{
	if (get_number_a(stack_a, 0) > get_number_a(stack_a, 1)
		&& get_number_b(stack_b, 0) < get_number_b(stack_b, 1))
		ss(stack_a, stack_b, 1);
	else if (get_number_a(stack_a, 0) > get_number_a(stack_a, 1))
		sa(stack_a, 1);
	else if (get_number_b(stack_b, 0) < get_number_b(stack_b, 1))
		sb(stack_b, 1);
}

void	parallel_bubble_limit(int *stack_a, int *stack_b, int limit)
{
	int	i;
	int	y;

	i = limit - 1;
	while (--i >= 0)
	{
		y = i + 1;
		while (--y > 0)
		{
			chose_better_swap(stack_a, stack_b);
			rr(1);
		}
		chose_better_swap(stack_a, stack_b);
		y = i + 1;
		while (--y > 0)
			rrr(1);
	}
}

void	parallel_bubble_limit_odd(int *stack_a, int *stack_b, int limit)
{
	int	i;
	int	y;

	i = limit - 1;
	while (--i >= 0)
	{
		y = i + 1;
		while (--y > 0)
		{
			chose_better_swap(stack_a, stack_b);
			rr(1);
		}
		chose_better_swap(stack_a, stack_b);
		rb(1);
		chose_better_swap(stack_a, stack_b);
		y = i + 1;
		while (--y > 0)
			rrr(1);
		rrb(1);
		chose_better_swap(stack_a, stack_b);
	}
}