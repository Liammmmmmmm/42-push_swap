/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbegsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:56:20 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/07 14:38:56 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	push_b_start(int *stack_a, int *stack_b, int *stack_s)
{
	int	i;
	int	len;
	int	divider;
	int	initial_len;
	int	res;

	initial_len = len_a(-1);
	while (len_a(-1) > 4)
	{
		i = -1;
		len = len_a(-1);
		divider = len / 2;
		res = 0;
		while (++i < len)
		{
			if (get_number_a(stack_a, 0) < stack_s[initial_len - divider])
			{
				pb(stack_a, stack_b, 1);
				res++;
			}
			else
				ra(1);
		}
	}
	return (res);
}

int	push_a_limit(int *stack_a, int *stack_b, int *stack_s, int limit)
{
	// faire exactement comme push b start mais on 
	(void)*stack_a;
	(void)*stack_b;
	(void)*stack_s;
	(void)limit;
	return (0);
}

void	bbeg_sort(int *stack_a, int *stack_b, int *stack_sorted)
{
	int	to_sort;

	to_sort = push_b_start(stack_a, stack_b, stack_sorted);
	select_good_sort_a(stack_a, to_sort);
	select_good_sort_b(stack_a, stack_b, to_sort);
}
