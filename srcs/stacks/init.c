/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:48:12 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/03 12:07:29 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(int **stack_a, int **stack_b, int argc, char **argv)
{
	*stack_a = malloc(sizeof(int) * (argc - 1));
	if (!*stack_a)
		return (0);
	*stack_b = malloc(sizeof(int) * (argc - 1));
	if (!*stack_b)
	{
		free(*stack_a);
		return (0);
	}
	while (argc > 0)
	{
		*stack_a[argc - 1] = ft_atoi(argv[argc]);
		argc--;
	}
	return (1);
}

void	clear_stacks(int *stack_a, int *stack_b)
{
	free(stack_a);
	free(stack_b);
}
