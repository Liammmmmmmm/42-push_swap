/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysort_little.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:55:17 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/09 17:59:44 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mysort_little(int *stack_a, int *stack_b, int *stack_sorted)
{
	int	parts;

	parts = root(len_a(-1)) / 2;
	i_to_b(stack_a, stack_b, stack_sorted, parts);
	full_insert_sort(stack_a, stack_b, stack_sorted);
	while (len_b(-1))
		pa(stack_a, stack_b, 1);
}
