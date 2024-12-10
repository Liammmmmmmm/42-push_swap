/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:48:12 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/10 17:02:06 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args_splited(int word_count, char **splited)
{
	int	i;

	i = 0;
	while (i < word_count)
	{
		if (check_arg(splited[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	init_split(int **stack_a, int **stack_b, char **argv)
{
	int		word_count;
	int		i;
	char	**splited;

	word_count = ft_count_words(argv[1], ' ');
	*stack_a = malloc(sizeof(int) * (word_count));
	if (!*stack_a)
		return (0);
	*stack_b = malloc(sizeof(int) * (word_count));
	if (!*stack_b)
		return (free(*stack_a), 0);
	splited = ft_split(argv[1], ' ');
	if (!splited)
		return (clear_stacks(*stack_a, *stack_b), 0);
	if (check_args_splited(word_count, splited) == 0)
		return (ft_free_tab(splited, word_count),
			clear_stacks(*stack_a, *stack_b), 0);
	i = -1;
	while (++i < word_count)
		(*stack_a)[i] = ft_atoi(splited[i]);
	ft_free_tab(splited, word_count);
	len_a(word_count);
	return (1);
}

int	init_stacks(int **stack_a, int **stack_b, int argc, char **argv)
{
	int	i;

	len_b(0);
	pos_a(0);
	pos_b(0);
	if (argc == 2)
		return (init_split(stack_a, stack_b, argv));
	*stack_a = malloc(sizeof(int) * (argc - 1));
	if (!*stack_a)
		return (0);
	*stack_b = malloc(sizeof(int) * (argc - 1));
	if (!*stack_b)
		return (free(*stack_a), 0);
	i = -1;
	while (++i < argc - 1)
		(*stack_a)[i] = ft_atoi(argv[i + 1]);
	len_a(i);
	return (1);
}

void	reinit_split(int *stack_a, int *stack_b, char **argv)
{
	int		word_count;
	int		i;
	char	**splited;

	word_count = ft_count_words(argv[1], ' ');
	splited = ft_split(argv[1], ' ');
	if (!splited)
		return (clear_stacks(stack_a, stack_b));
	i = 0;
	while (i < word_count)
	{
		stack_a[i] = ft_atoi(splited[i]);
		i++;
	}
	ft_free_tab(splited, word_count);
	len_a(word_count);
}

void	reinit_stack_a(int *stack_a, int *stack_b, int argc, char **argv)
{
	int	i;

	i = 0;
	pos_a(0);
	if (argc == 2)
		return (reinit_split(stack_a, stack_b, argv));
	while (i < argc - 1)
	{
		stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	len_a(i);
}
