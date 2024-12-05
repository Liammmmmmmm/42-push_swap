/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:50:23 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/05 17:07:24 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_to_shortest_inferior_a(int *stack_a, int limit)
{
	int	quickest;

	quickest = find_quickest_inferior_a(stack_a, limit);
	if (quickest == RA)
		while (get_number_a(stack_a, 0) > limit)
			ra(1);
	else if (quickest == RRA)
		while (get_number_a(stack_a, 0) > limit)
			rra(1);
	if (quickest == 0)
		return (0);
	return (1);
}

int	rotate_to_shortest_supperior_b(int *stack_b, int limit)
{
	int	quickest;

	quickest = find_quickest_supperior_b(stack_b, limit);
	if (quickest == RB)
		while (get_number_b(stack_b, 0) <= limit)
			rb(1);
	else if (quickest == RRB)
		while (get_number_b(stack_b, 0) <= limit)
			rrb(1);
	if (quickest == 0)
		return (0);
	return (1);
}
