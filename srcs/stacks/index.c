/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:21:10 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/06 13:51:41 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int *stack_sorted, int number)
{
	int	i;

	i = 0;
	while (stack_sorted[i] != number)
		i++;
	return (i);
}

void	replace_nb_by_index(int *stack_a, int *stack_sorted, int stack_len)
{
	int	i;

	i = 0;
	while (i < stack_len)
	{
		stack_a[i] = get_index(stack_sorted, stack_a[i]);
		i++;
	}
}
