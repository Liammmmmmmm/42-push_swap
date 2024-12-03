/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:18:11 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/03 16:39:06 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int *stack)
{
	int i;
	int min = 2147483647;

	i = 0;
	while (i < len_a(-1))
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

void	sort(int *stack_a, int *stack_b)
{
	int minv;

	while (len_a(-1) > 0)
	{
		minv = min(stack_a);
		while (stack_a[pos_a(-1)] != minv)
			ra();
		pb(stack_a, stack_b);
	}
	while (len_b(-1) > 0){
		pa(stack_a, stack_b);
	}
}