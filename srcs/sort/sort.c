/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:18:11 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/07 13:04:52 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_only(int *stack_a)
{
	if (get_number_a(stack_a, 0) < get_number_a(stack_a, 1)
		&& get_number_a(stack_a, 1) < get_number_a(stack_a, 2))
		return ;
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
		ra(1);
		sa(stack_a, 1);
		rra(1);
	}
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
	if (len == 2)
		return (sort_two_a(stack_a));
	if (len == 3)
		return (sort_three_only(stack_a));
	if (len == 4)
		return (sort_four_a(stack_a));
	mysort(stack_a, stack_b, stack_sorted);
}
