/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:50:06 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/03 13:40:05 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instr_ra(int len)
{
	int	pos;
	
	pos = pos_a(-1);
	if(pos < len - 1)
		pos_a(pos + 1);
	else
		pos_a(0);
}

void	instr_rb(int len)
{
	int	pos;
	
	pos = pos_b(-1);
	if(pos < len - 1)
		pos_b(pos + 1);
	else
		pos_b(0);
}

void	ra(void)
{
	instr_ra(len_a(-1));
	ft_putstr_fd("ra\n", 1);
}

void	rb(void)
{
	instr_rb(len_b(-1));
	ft_putstr_fd("rb\n", 1);
}

void	rr(void)
{
	instr_ra(len_a(-1));
	instr_rb(len_b(-1));
	ft_putstr_fd("rr\n", 1);
}
