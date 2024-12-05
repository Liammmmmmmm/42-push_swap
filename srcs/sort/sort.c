/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:18:11 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/05 17:05:53 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	root(int n) {
	int res;
	
	res = 0;
	if (n < 0)
		return (-1);
	while ((res + 1) * (res + 1) <= n)
		res++;
	return res;
}

void	part_insert_sort_to_b(int *stack_a, int *stack_b, int *stack_sorted, int parts)
{
	int	part;
	int	total_len;
	int	initial_len;
	int	i;

	part = 1;
	initial_len = len_a(-1);
	while (part < parts)
	{
		total_len = len_a(-1);
		i = 0;
		while (i < total_len)
		{
			if(rotate_to_shortest_inferior_a(stack_a, stack_sorted[(part) * (initial_len / parts)]))
				pb(stack_a, stack_b, 1);
			i++;
		}
		part++;
	}
	while (len_a(-1) > 0)
		pb(stack_a, stack_b, 1);
}

void	part_insert_sort_to_a(int *stack_a, int *stack_b, int *stack_sorted, int parts)
{
	int	part;
	int	total_len;
	int	initial_len;
	int	i;

	part = 1;
	initial_len = len_b(-1);
	while (part < parts)
	{
		total_len = len_b(-1);
		i = 0;
		while (i < total_len)
		{
			if(rotate_to_shortest_supperior_b(stack_b, stack_sorted[(parts - part) * (initial_len / parts)]))
				pa(stack_a, stack_b, 1);
			i++;
		}
		part++;
	}
	while (len_b(-1) > 0)
		pa(stack_a, stack_b, 1);
}


void	full_insert_sort(int *stack_a, int *stack_b, int *stack_sorted)
{
	int	i;
	int	quickest;
	
	i = len_b(-1) - 1;
	while (i >= 0)
	{
		quickest = find_quickest_b(stack_b, 0, stack_sorted[i]);
		if (quickest == RB)
		{
			while (stack_b[pos_b(-1)] != stack_sorted[i])
				rb(1);
			pa(stack_a, stack_b, 1);
		}
		else if (quickest == RRB)
		{
			while (stack_b[pos_b(-1)] != stack_sorted[i])
				rrb(1);
			pa(stack_a, stack_b, 1);
		}
		i--;
	}
}

void	sort(int *stack_a, int *stack_b, int *stack_sorted)
{
	int	parts;
	
	parts = root(len_a(-1)) / 2;
	part_insert_sort_to_b(stack_a, stack_b, stack_sorted, parts / 3);
	part_insert_sort_to_a(stack_a, stack_b, stack_sorted, parts);
	part_insert_sort_to_b(stack_a, stack_b, stack_sorted, parts * 2);
	full_insert_sort(stack_a, stack_b, stack_sorted);
}
