/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:45:30 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/07 13:09:44 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(int *stack_a)
{
	if (get_number_a(stack_a, 0) > get_number_a(stack_a, 1))
		return (sa(stack_a, 1));
}

void	sort_three_a(int *stack_a)
{
	if (get_number_a(stack_a, 0) < get_number_a(stack_a, 1)
		&& get_number_a(stack_a, 1) < get_number_a(stack_a, 2))
		return ;
	if (get_number_a(stack_a, 0) > get_number_a(stack_a, 1))
		sa(stack_a, 1);
	if (get_number_a(stack_a, 1) > get_number_a(stack_a, 2))
	{
		ra(1);
		sa(stack_a, 1);
		rra(1);
	}
	if (get_number_a(stack_a, 0) > get_number_a(stack_a, 1))
		sa(stack_a, 1);
}

void	sort_four_a(int *stack_a)
{
	if (get_number_a(stack_a, 0) < get_number_a(stack_a, 1)
		&& get_number_a(stack_a, 1) < get_number_a(stack_a, 2)
		&& get_number_a(stack_a, 2) < get_number_a(stack_a, 3))
		return ;
	sort_three_a(stack_a);
	if (!(get_number_a(stack_a, 1) < get_number_a(stack_a, 2)
			&& get_number_a(stack_a, 2) < get_number_a(stack_a, 3)))
	{
		ra(1);
		sort_three_a(stack_a);
		rra(1);
	}
	sort_three_a(stack_a);
}
