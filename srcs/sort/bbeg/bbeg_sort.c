/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbeg_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:56:20 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/09 17:09:16 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_from_b(t_list **first, int *stack_a, int *stack_b, int *stack_s)
{
	t_list		*element;
	t_bbeg		*content;

	element = *first;
	if (element == NULL)
		return ;
	content = element->content;
	if (content->size <= 10)
	{
		sort_from_b(first, element, stack_a, stack_b);
		return (split_from_a(first, stack_a, stack_b, stack_s));
	}
	if (add_node(first, 'a', content->size / 2,
			content->min + (content->size - (content->size / 2))) == 0)
		return (cancel_everything(first, stack_a, stack_b, stack_s));
	if (add_node(first, 'b',
			(content->size - (content->size / 2)), content->min) == 0)
		return (cancel_everything(first, stack_a, stack_b, stack_s));
	push_to_a(content, stack_a, stack_b);
	ft_lstdelmiddle(first, element);
	split_from_a(first, stack_a, stack_b, stack_s);
}

void	split_from_a(t_list **first, int *stack_a, int *stack_b, int *sks)
{
	static int	direction = 1;
	t_list		*element;
	t_bbeg		*ctn;

	element = search_for_a(first);
	if (element == NULL)
		return (split_from_b(first, stack_a, stack_b, sks));
	ctn = element->content;
	if (ctn->size <= 10)
	{
		return (go_back_if(&direction, ctn->size), sort_from_a(first, element,
				stack_a, stack_b), split_from_b(first, stack_a, stack_b, sks));
	}
	if (add_node(first, 'a', ctn->size / 2,
			ctn->min + (ctn->size - (ctn->size / 2))) == 0)
		return (cancel_everything(first, stack_a, stack_b, sks));
	if (add_node(first, 'b', (ctn->size - (ctn->size / 2)), ctn->min) == 0)
		return (cancel_everything(first, stack_a, stack_b, sks));
	push_to_b(direction, ctn, stack_a, stack_b);
	if (direction)
		direction = 0;
	else
		direction = 1;
	ft_lstdelmiddle(first, element);
	split_from_a(first, stack_a, stack_b, sks);
}

void	split_first(t_list **first, int *stack_a, int *stack_b, int *stack_s)
{
	t_list		*element;
	t_bbeg		*content;

	element = search_for_a(first);
	if (element == NULL)
		return (split_from_b(first, stack_a, stack_b, stack_s));
	content = element->content;
	if (content->size <= 10)
	{
		return (sort_from_a(first, element, stack_a, stack_b),
			split_from_b(first, stack_a, stack_b, stack_s));
	}
	if (add_node(first, 'a', content->size / 2,
			content->min + (content->size - (content->size / 2))) == 0)
		return (cancel_everything(first, stack_a, stack_b, stack_s));
	if (add_node(first, 'b',
			(content->size - (content->size / 2)), content->min) == 0)
		return (cancel_everything(first, stack_a, stack_b, stack_s));
	push_to_b(1, content, stack_a, stack_b);
	ft_lstdelmiddle(first, element);
	split_first(first, stack_a, stack_b, stack_s);
}

void	bbeg_sort(int *stack_a, int *stack_b, int *stack_sorted)
{
	t_list	*first;

	first = NULL;
	if (add_node(&first, 'a', len_a(-1), 0) == 0)
		return (cancel_everything(&first, stack_a, stack_b, stack_sorted));
	split_first(&first, stack_a, stack_b, stack_sorted);
}
