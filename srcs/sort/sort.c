/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:18:11 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/07 16:15:50 by lilefebv         ###   ########lyon.fr   */
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

/*
Others algorithms :
radix_sort_base(stack_a, stack_b, stack_sorted, 2);
bubble_sort(stack_a);
bbeg_sort(stack_a, stack_b, stack_sorted);
*/
void	sort(int *stack_a, int *stack_b, int *stack_sorted)
{
	int	len;

	len = len_a(-1);
	if (is_sorted(stack_a))
		return ;
	if (len == 2)
		return (sort_two_a(stack_a));
	if (len == 3)
		return (sort_three_only(stack_a));
	if (len == 4)
		return (sort_four_a(stack_a));
	if (len == 5)
		return (sort_five_ony(stack_a, stack_b));
	bbeg_sort(stack_a, stack_b, stack_sorted);
}
