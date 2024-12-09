/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbeg_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:09:21 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/09 17:09:38 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_back_if(int *direction, int rotations)
{
	if (*direction == 0)
	{
		while (rotations > 0)
		{
			rra(1);
			rotations--;
		}
		*direction = 1;
	}
}

void	push_to_b(int direction, t_bbeg *content, int *stack_a, int *stack_b)
{
	int	i;

	i = 0;
	while (i < content->size)
	{
		if (!direction)
			rra(1);
		if (get_number_a(stack_a, 0) >= content->min
			&& get_number_a(stack_a, 0) < content->min
			+ (content->size - (content->size / 2)))
			pb(stack_a, stack_b, 1);
		else
			if (direction)
				ra(1);
		i++;
	}
}

void	push_to_a(t_bbeg *content, int *stack_a, int *stack_b)
{
	int	i;

	i = 0;
	while (i < content->size)
	{
		if (get_number_b(stack_b, 0) >= content->min
			&& get_number_b(stack_b, 0) < content->min
			+ (content->size - (content->size / 2)))
			rb(1);
		else
			pa(stack_a, stack_b, 1);
		i++;
	}
	i = -1;
	while (++i < content->size - content->size / 2)
		rrb(1);
}
