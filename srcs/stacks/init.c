/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:48:12 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/05 13:20:43 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(int **stack_a, int **stack_b, int argc, char **argv)
{
	int	i;
	
	*stack_a = malloc(sizeof(int) * (argc - 1));
	if (!*stack_a)
		return (0);
	*stack_b = malloc(sizeof(int) * (argc - 1));
	if (!*stack_b)
		return (free(*stack_a), 0);
	i = 0;
	while (i < argc - 1)
	{
		(*stack_a)[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	len_a(i);
	len_b(0);
	pos_a(0);
	pos_b(0);
	return (1);
}

void	reinit_stack_a(int *stack_a, int argc, char **argv)
{
	int	i;
	
	i = 0;
	while (i < argc - 1)
	{
		stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	len_a(i);
	pos_a(0);
}

void	clear_stacks(int *stack_a, int *stack_b)
{
	free(stack_a);
	free(stack_b);
}
