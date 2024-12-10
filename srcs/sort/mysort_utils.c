/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysort_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:59:56 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/10 12:31:31 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(int *stack_a, int *stack_b, int limit)
{
	int	total_len;
	int	i;

	total_len = len_a(-1);
	i = -1;
	while (++i < total_len)
	{
		if (get_number_a(stack_a, 0) < limit)
			pb(stack_a, stack_b, 1);
		else
			ra(1);
	}
}

void	move_to_b_bounded(int *stack_a, int *stack_b, int min, int max)
{
	int	total_len;
	int	i;

	total_len = len_a(-1);
	i = -1;
	while (++i < total_len)
	{
		if (get_number_a(stack_a, 0) < max && get_number_a(stack_a, 0) >= min)
		{
			pb(stack_a, stack_b, 1);
			rb(1);
		}
		else if (get_number_a(stack_a, 0) < min)
			pb(stack_a, stack_b, 1);
		else
			ra(1);
	}
}

void	rotate_and_push(int *i, int *stack_a, int *stack_b, void (*rota)(int))
{
	if (*i - 1 >= 0)
	{
		while (stack_b[pos_b(-1)] != *i && stack_b[pos_b(-1)] != *i - 1)
			rota(1);
		pa(stack_a, stack_b, 1);
	}
	if (*i - 1 < 0)
		pa(stack_a, stack_b, 1);
	else if (get_number_a(stack_a, 0) == *i - 1)
	{
		while (stack_b[pos_b(-1)] != *i)
			rota(1);
		pa(stack_a, stack_b, 1);
		sa(stack_a, 1);
		(*i)--;
	}
}
