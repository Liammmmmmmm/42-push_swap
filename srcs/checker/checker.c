/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:07:48 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/10 17:18:25 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_actions	get_action(char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		return (SA);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		return (SB);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		return (SS);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		return (PA);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		return (PB);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		return (RA);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		return (RB);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		return (RR);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		return (RRA);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		return (RRB);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		return (RRR);
	else
		return (UNKNOWN);
}

void	execute_action(int *stack_a, int *stack_b, t_actions action)
{
	if (action == SA)
		return (sa(stack_a, 0));
	else if (action == SB)
		return (sb(stack_b, 0));
	else if (action == SS)
		return (ss(stack_a, stack_b, 0));
	else if (action == PA)
		return (pa(stack_a, stack_b, 0));
	else if (action == PB)
		return (pb(stack_a, stack_b, 0));
	else if (action == RA)
		return (ra(0));
	else if (action == RB)
		return (rb(0));
	else if (action == RR)
		return (rr(0));
	else if (action == RRA)
		return (rra(0));
	else if (action == RRB)
		return (rrb(0));
	else if (action == RRR)
		return (rrr(0));
}

t_checker	execute_instructions(int *stack_a, int *stack_b)
{
	char		*line;
	t_actions	action;

	line = get_next_line(0);
	while (line)
	{
		action = get_action(line);
		if (action == UNKNOWN)
			return (ERROR_UNKNOWN);
		execute_action(stack_a, stack_b, action);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(stack_a) && len_b(-1) == 0)
		return (OK);
	return (KO);
}

int	main(int argc, char **argv)
{
	int			*stack_a;
	int			*stack_b;
	t_checker	checker_result;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (check_args(argc, argv) == 0)
		return (print_error(), 1);
	if (init_stacks(&stack_a, &stack_b, argc, argv) == 0)
		return (print_error(), 1);
	if (check_duplicates(stack_a, argc - 1))
		return (clear_stacks(stack_a, stack_b), print_error(), 1);
	checker_result = execute_instructions(stack_a, stack_b);
	if (checker_result == ERROR_UNKNOWN)
		print_error();
	else if (checker_result == OK)
		ft_putstr_fd("OK\n", 1);
	else if (checker_result == KO)
		ft_putstr_fd("KO\n", 1);
	return (clear_stacks(stack_a, stack_b), 0);
}
