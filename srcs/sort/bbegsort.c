/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbegsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:56:20 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/06 15:19:33 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_start(int *stack_a, int *stack_b, int divider)
{
	while (divider > 1)
	{
		if ((get_number_a(stack_a, 0) / (divider)) % 2 == 0)
			pb(stack_a, stack_b, 1);
		else
			ra(1);
		divider = divider / 2;
	}
}

void	bbeg_sort(int *stack_a, int *stack_b, int *stack_sorted)
{
	int	iterations;
	int	largest;

	largest = stack_sorted[len_a(-1) - 1];
	iterations = 0;
	while (largest > 0)
	{
		largest = largest / 2;
		iterations++;
	}

	push_b_start(stack_a, stack_b, power(2, iterations));
}
