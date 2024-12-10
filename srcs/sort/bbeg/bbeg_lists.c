/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbeg_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:00:56 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/10 12:06:18 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cancel_everything(t_list **first, int *st_a, int *st_b, int *st_s)
{
	ft_lstclear(first, free);
	while (len_b(-1) > 0)
		pa(st_a, st_b, 1);
	mysort(st_a, st_b, st_s);
}

int	add_node(t_list **first, char stack, int size, int min)
{
	t_bbeg	*content;
	t_list	*node;

	content = malloc(sizeof(t_bbeg));
	if (!content)
		return (0);
	content->stack = stack;
	content->size = size;
	content->min = min;
	node = ft_lstnew(content);
	if (!node)
		return (free(content), 0);
	ft_lstadd_front(first, node);
	return (1);
}

t_list	*search_for_a(t_list **first)
{
	t_bbeg	*temp;
	t_list	*actual;

	if (!*first)
		return (NULL);
	actual = *first;
	while (actual != NULL)
	{
		temp = actual->content;
		if (temp->stack == 'a')
			return (actual);
		actual = actual->next;
	}
	return (NULL);
}

int	is_alone_in_b(t_list **first)
{
	int		count;
	t_bbeg	*temp;
	t_list	*actual;

	if (!*first)
		return (0);
	actual = *first;
	count = 0;
	while (actual != NULL)
	{
		temp = actual->content;
		if (temp->stack == 'b')
			count++;
		actual = actual->next;
	}
	if (count == 1)
		return (1);
	return (0);
}
