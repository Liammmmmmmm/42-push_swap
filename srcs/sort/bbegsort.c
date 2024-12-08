/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbegsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:56:20 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/08 17:32:38 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_good_sort_b(int *stack_a, int *stack_b, int to_sort)
{
	int	i;

	if (to_sort == 2)
		sort_two_b(stack_b);
	else if (to_sort == 3)
		sort_three_b(stack_b);
	else if (to_sort == 4)
		sort_four_b(stack_b);
	i = -1;
	while (++i < to_sort)
		pa(stack_a, stack_b, 1);
}

void	select_good_sort_a(int *stack_a, int to_sort)
{
	if (to_sort == 2)
		sort_two_a(stack_a);
	else if (to_sort == 3)
		sort_three_a(stack_a);
	else if (to_sort == 4)
		sort_four_a(stack_a);
	else
		bubble_sort(stack_a);
}



void	bbeg_sort(int *stack_a, int *stack_b, int *stack_sorted)
{
	
}
