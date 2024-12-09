/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbeg_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:12:23 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/09 17:06:35 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chose_better_swap(int *stack_a, int *stack_b)
{
	if (len_b(-1) > 1 && get_number_a(stack_a, 0) > get_number_a(stack_a, 1)
		&& get_number_b(stack_b, 0) < get_number_b(stack_b, 1))
		ss(stack_a, stack_b, 1);
	else if (get_number_a(stack_a, 0) > get_number_a(stack_a, 1))
		sa(stack_a, 1);
	else if (len_b(-1) > 1
		&& get_number_b(stack_b, 0) < get_number_b(stack_b, 1))
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

void	select_good_sort_b(int *stack_a, int *stack_b, int to_sort)
{
	int	i;

	if (to_sort == 2)
		sort_two_b(stack_b);
	else if (to_sort == 3)
		sort_three_b(stack_b);
	else if (to_sort == 4)
		sort_four_b(stack_b);
	i = -1;
	while (++i < to_sort)
		pa(stack_a, stack_b, 1);
}

void	select_good_sort_a(int *stack_a, int to_sort)
{
	if (to_sort == 2)
		sort_two_a(stack_a);
	else if (to_sort == 3)
		sort_three_a(stack_a);
	else if (to_sort == 4)
		sort_four_a(stack_a);
	else
		bubble_sort(stack_a);
}
