/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:21:35 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/10 15:12:23 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_sorted;
	int	*stack_a;
	int	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_sorted = NULL;
	if (check_args(argc, argv) == 0)
		return (print_error(), 1);
	if (init_stacks(&stack_a, &stack_b, argc, argv) == 0)
		return (print_error(), 1);
	if (check_duplicates(stack_a, argc - 1))
		return (clear_stacks(stack_a, stack_b), print_error(), 1);
	if (first_sort(&stack_sorted, stack_a, stack_b, len_a(-1)) == 0)
		return (print_error(), 1);
	reinit_stack_a(stack_a, stack_b, argc, argv);
	replace_nb_by_index(stack_a, stack_sorted, len_a(-1));
	sort(stack_a, stack_b, stack_sorted);
	return (clear_stacks(stack_a, stack_b), free(stack_sorted), 0);
}
