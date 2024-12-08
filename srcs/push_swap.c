/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:21:35 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/08 15:51:51 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printstack(int *stack, int pos, int len)
{
	int	i;

	i = pos;
	ft_putstr_fd("START\n", 1);
	while (i < len)
	{
		ft_putnbr_fd(stack[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	i = 0;
	while (i < pos)
	{
		ft_putnbr_fd(stack[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	ft_putstr_fd("END\n", 1);
}

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
