/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:21:35 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/03 12:43:27 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	
	pos_a(0);
	pos_b(0);
	if (check_args(argc, argv) == 0)
		return (print_error(), 1);
	if (init_stacks(&stack_a, &stack_b, argc, argv) == 0)
		return (print_error(), 1);
	if (check_duplicates(stack_a, argc - 1))
		return (clear_stacks(stack_a, stack_b), print_error(), 1);
	// sort algo
	return (0);
}

// faire un buffer circulaire pour chaque stack, comme ca pas de cassage de cul avec une liste chainee
// faire chaque fonction possible, et quand on l'execute ca write direct l'action dans le term
// faire un bien bel algo de tri
