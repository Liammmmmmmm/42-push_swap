/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:21:35 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/05 13:28:51 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printstack(int *stack, int pos, int len)
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
	if (argc < 2)
		return (print_error(), 1);
	if (check_args(argc, argv) == 0)
		return (print_error(), 1);
	if (init_stacks(&stack_a, &stack_b, argc, argv) == 0)
		return (print_error(), 1);
	if (check_duplicates(stack_a, argc - 1))
		return (clear_stacks(stack_a, stack_b), print_error(), 1);
	if (first_sort(&stack_sorted, stack_a, stack_b, argc - 1) == 0)
		return (print_error(), 1);
	reinit_stack_a(stack_a, argc, argv);
	sort(stack_a, stack_b);
	printstack(stack_a, pos_a(-1), len_a(-1));
	printstack(stack_b, pos_b(-1), len_b(-1));
	printstack(stack_sorted, 0, argc - 1);
	return (clear_stacks(stack_a, stack_b), free(stack_sorted), 0);
}
