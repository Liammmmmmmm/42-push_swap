/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:18:11 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/06 15:20:05 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int *stack_a, int *stack_b, int *stack_sorted)
{
	int	len;

	len = len_a(-1);
//	bubble_sort(stack_a);
//	mysort(stack_a, stack_b, stack_sorted);
	bbeg_sort(stack_a, stack_b, stack_sorted);
}
