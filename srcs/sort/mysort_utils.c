/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysort_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:59:56 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/07 13:00:19 by lilefebv         ###   ########lyon.fr   */
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
