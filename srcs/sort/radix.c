/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:43:22 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/06 13:54:34 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_push_base(int *stack_a, int *stack_b, int *base_divide, int base)
{
	int	len;
	int	i;
	int	y;

	y = 0;
	while (y < base - 1)
	{
		i = 0;
		len = len_a(-1);
		while (i < len)
		{
			if ((get_number_a(stack_a, 0) / (*base_divide)) % base == y)
				pb(stack_a, stack_b, 1);
			else
				ra(1);
			i++;
		}
		y++;
	}
	while (len_b(-1) > 0)
		pa(stack_a, stack_b, 1);
	*base_divide = *base_divide * base;
}

void	radix_sort_base(int *stack_a, int *stack_b, int *stack_sorted, int b)
{
	int	bin_divide;
	int	iterations;
	int	largest;

	bin_divide = 1;
	largest = stack_sorted[len_a(-1) - 1];
	iterations = 0;
	while (largest > 0)
	{
		largest = largest / b;
		iterations++;
	}
	while (iterations > 0)
	{
		radix_push_base(stack_a, stack_b, &bin_divide, b);
		iterations--;
	}
}
