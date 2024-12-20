/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbeg_from_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:03:16 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/10 12:08:57 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_half_from_b(t_bbeg	*ctn, int *stk_a, int *stk_b, int alone)
{
	int		i;
	int		y;
	int		x;

	y = 0;
	x = 0;
	i = -1;
	while (++i < ctn->size && x < ctn->size - ctn->size / 2)
	{
		if (get_number_b(stk_b, 0) >= ctn->min
			&& get_number_b(stk_b, 0) < ctn->min
			+ (ctn->size - (ctn->size / 2)))
		{
			y++;
			rb(1);
		}
		else
		{
			x++;
			pa(stk_a, stk_b, 1);
		}
	}
	if (!alone)
		while (y-- > 0)
			rrb(1);
}

static void	push_x_nb_to_a(int *stack_a, int *stack_b, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		pa(stack_a, stack_b, 1);
		i++;
	}
}

void	sort_from_b(t_list **first, t_list *elem, int *stack_a, int *stack_b)
{
	t_bbeg	*content;
	int		i;

	content = elem->content;
	if (content->size <= 4)
		return (select_good_sort_b(stack_a, stack_b, content->size),
			push_x_nb_to_a(stack_a, stack_b, content->size),
			ft_lstdelmiddle(first, elem));
	push_half_from_b(content, stack_a, stack_b, is_alone_in_b(first));
	if (content->size % 2 == 0)
		parallel_bubble_limit(stack_a, stack_b, content->size / 2);
	else
		parallel_bubble_limit_odd(stack_a, stack_b, content->size / 2);
	i = -1;
	while (++i < content->size - content->size / 2)
		pa(stack_a, stack_b, 1);
	ft_lstdelmiddle(first, elem);
}
