/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:39:13 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/08 12:41:53 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_sort(int **stack_sorted, int *stack_a, int *stack_b, int len)
{
	int	minv;
	int	i;

	while (len_a(-1) > 0)
	{
		minv = min(stack_a, len_a(-1));
		while (stack_a[pos_a(-1)] != minv)
			ra(0);
		pb(stack_a, stack_b, 0);
	}
	while (len_b(-1) > 0)
		pa(stack_a, stack_b, 0);
	*stack_sorted = malloc(sizeof(int) * (len));
	if (!*stack_sorted)
		return (clear_stacks(stack_a, stack_b), 0);
	i = -1;
	while (++i < len)
		(*stack_sorted)[i] = get_number_a(stack_a, i);
	return (1);
}
