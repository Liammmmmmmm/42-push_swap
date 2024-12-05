/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:48:02 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/05 11:56:05 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_number_a(int *stack_a, int index)
{
	if (index + pos_a(-1) < len_a(-1))
		return (stack_a[index + pos_a(-1)]);
	else
		return (stack_a[pos_a(-1) - len_a(-1) + index]);
}

int	get_number_b(int *stack_b, int index)
{
	if (index + pos_b(-1) < len_b(-1))
		return (stack_b[index + pos_b(-1)]);
	else
		return (stack_b[pos_b(-1) - len_b(-1) + index]);
}
