/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:18:11 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/10 16:08:11 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_only(int *stack_a)
{
	if (get_number_a(stack_a, 0) == 2 && get_number_a(stack_a, 1) == 0
		&& get_number_a(stack_a, 2) == 1)
		return (ra(1));
	if (get_number_a(stack_a, 0) > get_number_a(stack_a, 1))
		sa(stack_a, 1);
	if (get_number_a(stack_a, 0) == 1 && get_number_a(stack_a, 1) == 2
		&& get_number_a(stack_a, 2) == 0)
		return (rra(1));
	if (get_number_a(stack_a, 1) > get_number_a(stack_a, 2))
	{
		rra(1);
		sa(stack_a, 1);
	}
}

void	sort_three_from_five(int *stack_a)
{
	if (get_number_a(stack_a, 0) == 4 && get_number_a(stack_a, 1) == 2
		&& get_number_a(stack_a, 2) == 3)
		return (ra(1));
	if (get_number_a(stack_a, 0) > get_number_a(stack_a, 1))
		sa(stack_a, 1);
	if (get_number_a(stack_a, 0) == 3 && get_number_a(stack_a, 1) == 4
		&& get_number_a(stack_a, 2) == 2)
		return (rra(1));
	if (get_number_a(stack_a, 1) > get_number_a(stack_a, 2))
	{
		rra(1);
		sa(stack_a, 1);
	}
}

void	sort_five_ony(int *stack_a, int *stack_b)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (get_number_a(stack_a, 0) == 0 || get_number_a(stack_a, 0) == 1)
			pb(stack_a, stack_b, 1);
		else
			ra(1);
		if (len_a(-1) == 3)
			break ;
	}
	sort_three_from_five(stack_a);
	sort_two_b(stack_b);
	while (len_b(-1) > 0)
		pa(stack_a, stack_b, 1);
}

void	sort_choose_algo(int *stack_a, int *stack_b, int *stack_sorted)
{
	if (ALGO == 1)
		return (radix_sort_base(stack_a, stack_b, stack_sorted, 2));
	else if (ALGO == 2)
		return (mysort(stack_a, stack_b, stack_sorted));
	else if (ALGO == 3)
		return (mysort_little(stack_a, stack_b, stack_sorted));
	else if (ALGO == 4)
		return (bbeg_sort(stack_a, stack_b, stack_sorted));
	else if (ALGO == 5)
		return (bubble_sort(stack_a));
	return (bbeg_sort(stack_a, stack_b, stack_sorted));
}

void	sort(int *stack_a, int *stack_b, int *stack_sorted)
{
	int	len;

	len = len_a(-1);
	if (is_sorted(stack_a))
		return ;
	if (ALGO != 0)
		return (sort_choose_algo(stack_a, stack_b, stack_sorted));
	if (len == 2)
		return (sort_two_a(stack_a));
	else if (len == 3)
		return (sort_three_only(stack_a));
	else if (len == 4)
		return (sort_four_a(stack_a));
	else if (len == 5)
		return (sort_five_ony(stack_a, stack_b));
	else if (len < 110)
		return (mysort_little(stack_a, stack_b, stack_sorted));
	else if (len < 400)
		return (mysort(stack_a, stack_b, stack_sorted));
	bbeg_sort(stack_a, stack_b, stack_sorted);
}
