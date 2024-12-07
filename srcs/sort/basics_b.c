/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:45:30 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/07 13:10:05 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_b(int *stack_b)
{
	if (get_number_b(stack_b, 0) < get_number_b(stack_b, 1))
		return (sb(stack_b, 1));
}

void	sort_three_b(int *stack_b)
{
	if (get_number_b(stack_b, 0) > get_number_b(stack_b, 1)
		&& get_number_b(stack_b, 1) > get_number_b(stack_b, 2))
		return ;
	if (get_number_b(stack_b, 0) < get_number_b(stack_b, 1))
		sb(stack_b, 1);
	if (get_number_b(stack_b, 1) < get_number_b(stack_b, 2))
	{
		rb(1);
		sb(stack_b, 1);
		rrb(1);
	}
	if (get_number_b(stack_b, 0) < get_number_b(stack_b, 1))
		sb(stack_b, 1);
}

void	sort_four_b(int *stack_b)
{
	if (get_number_b(stack_b, 0) > get_number_b(stack_b, 1)
		&& get_number_b(stack_b, 1) > get_number_b(stack_b, 2)
		&& get_number_b(stack_b, 2) > get_number_b(stack_b, 3))
		return ;
	sort_three_b(stack_b);
	if (!(get_number_b(stack_b, 1) > get_number_b(stack_b, 2)
			&& get_number_b(stack_b, 2) > get_number_b(stack_b, 3)))
	{
		rb(1);
		sort_three_b(stack_b);
		rrb(1);
	}
	sort_three_b(stack_b);
}
