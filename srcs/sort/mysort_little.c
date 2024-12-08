/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysort_little.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:55:17 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/08 15:40:50 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	i_to_b_little(int *stack_a, int *stack_b, int *stack_sorted, int parts)
{
	int	part;
	int	total_len;
	int	i_len;
	int	i;

	part = 1;
	i_len = len_a(-1);
	if (parts <= 1)
		parts = 2;
	while (part < parts)
	{
		total_len = len_a(-1);
		i = 0;
		while (i < total_len)
		{
			if (rotate_to_shortest_inferior_a(
					stack_a, stack_sorted[(part) * (i_len / parts)]))
				pb(stack_a, stack_b, 1);
			i++;
		}
		part++;
	}
	while (len_a(-1) > 1)
	{
		if (get_number_a(stack_a, 0) == stack_sorted[i_len])
			ra(1);
		else
			pb(stack_a, stack_b, 1);
	}
}

void	mysort_little(int *stack_a, int *stack_b, int *stack_sorted)
{
	int	parts;

	parts = root(len_a(-1)) / 2;
	i_to_b_little(stack_a, stack_b, stack_sorted, parts);
	full_insert_sort(stack_a, stack_b, stack_sorted);
	while (len_b(-1))
		pa(stack_a, stack_b, 1);
}
