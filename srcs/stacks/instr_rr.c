/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:50:04 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/06 13:50:35 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instr_rra(int len)
{
	int	pos;

	pos = pos_a(-1);
	if (pos > 0)
		pos_a(pos - 1);
	else
		pos_a(len - 1);
}

void	instr_rrb(int len)
{
	int	pos;

	pos = pos_b(-1);
	if (pos > 0)
		pos_b(pos - 1);
	else
		pos_b(len - 1);
}

void	rra(int print)
{
	instr_rra(len_a(-1));
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(int print)
{
	instr_rrb(len_b(-1));
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(int print)
{
	instr_rra(len_a(-1));
	instr_rrb(len_b(-1));
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
