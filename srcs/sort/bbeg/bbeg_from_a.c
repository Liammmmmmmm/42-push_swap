/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbeg_from_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:07:09 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/09 17:07:13 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_half_from_a(t_bbeg	*content, int *stack_a, int *stack_b)
{
	int		i;
	int		y;
	int		x;

	y = 0;
	x = 0;
	i = -1;
	while (++i < content->size && x < content->size - content->size / 2)
	{
		if (get_number_a(stack_a, 0) >= content->min
			&& get_number_a(stack_a, 0) < content->min
			+ (content->size - (content->size / 2)))
		{
			x++;
			pb(stack_a, stack_b, 1);
		}
		else
		{
			y++;
			ra(1);
		}
	}
	while (y-- > 0)
		rra(1);
}

void	sort_from_a(t_list **first, t_list *elem, int *stack_a, int *stack_b)
{
	t_bbeg	*content;
	int		i;

	content = elem->content;
	if (content->size <= 4)
		return (select_good_sort_a(stack_a, content->size),
			ft_lstdelmiddle(first, elem));
	i = -1;
	push_half_from_a(content, stack_a, stack_b);
	if (content->size % 2 == 0)
		parallel_bubble_limit(stack_a, stack_b, content->size / 2);
	else
		parallel_bubble_limit_odd(stack_a, stack_b, content->size / 2);
	i = -1;
	while (++i < content->size - content->size / 2)
		pa(stack_a, stack_b, 1);
	ft_lstdelmiddle(first, elem);
}
