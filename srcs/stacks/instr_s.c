/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:50:09 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/06 13:49:57 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instr_s(int *tab, int len, int pos)
{
	int	temp;

	if (len < 2)
		return ;
	if (pos < len - 1)
	{
		temp = tab[pos];
		tab[pos] = tab[pos + 1];
		tab[pos + 1] = temp;
	}
	else
	{
		temp = tab[pos];
		tab[pos] = tab[0];
		tab[0] = temp;
	}
}

void	sa(int *stack_a, int print)
{
	instr_s(stack_a, len_a(-1), pos_a(-1));
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(int *stack_b, int print)
{
	instr_s(stack_b, len_b(-1), pos_b(-1));
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(int *stack_a, int *stack_b, int print)
{
	instr_s(stack_a, len_a(-1), pos_a(-1));
	instr_s(stack_b, len_b(-1), pos_b(-1));
	if (print)
		ft_putstr_fd("ss\n", 1);
}
