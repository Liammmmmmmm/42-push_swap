/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:50:04 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/03 13:41:39 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instr_rra(int len)
{
	int	pos;
	
	pos = pos_a(-1);
	if(pos > 0)
		pos_a(pos - 1);
	else
		pos_a(len - 1);
}

void	instr_rrb(int len)
{
	int	pos;
	
	pos = pos_b(-1);
	if(pos > 0)
		pos_b(pos - 1);
	else
		pos_b(len - 1);
}

void	rra(void)
{
	instr_rra(len_a(-1));
	ft_putstr_fd("rra\n", 1);
}

void	rrb(void)
{
	instr_rrb(len_b(-1));
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(void)
{
	instr_rra(len_a(-1));
	instr_rrb(len_b(-1));
	ft_putstr_fd("rrr\n", 1);
}
