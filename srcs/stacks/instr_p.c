/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:50:07 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/03 14:41:36 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(int *stack_a, int *stack_b)
{
	int temp;
	int	i;

	if (len_b(-1) == 0)
		return ;
	i = pos_b(-1);
	temp = stack_b[i];
	while (i < len_b(-1) - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	len_b(len_b(-1) - 1);
	i = len_a(-1);
	while (pos_a(-1) < i)
	{
		stack_a[i + 1] = stack_a[i];
		i--;
	}
	stack_a[i] = temp;
	len_a(len_a(-1) + 1);
	ft_putstr_fd("pa\n", 1);
}

void	pb(int *stack_a, int *stack_b)
{
	int temp;
	int	i;

	if (len_a(-1) == 0)
		return ;
	i = pos_a(-1);
	temp = stack_a[i];
	while (i < len_a(-1) - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	len_a(len_a(-1) - 1);
	i = len_b(-1);
	while (pos_b(-1) < i)
	{
		stack_b[i + 1] = stack_b[i];
		i--;
	}
	stack_b[i] = temp;
	len_b(len_b(-1) + 1);
	ft_putstr_fd("pb\n", 1);
}
