/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbegsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:56:20 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/09 14:10:49 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_good_sort_b(int *stack_a, int *stack_b, int to_sort)
{
	int	i;

	if (to_sort == 2)
		sort_two_b(stack_b);
	else if (to_sort == 3)
		sort_three_b(stack_b);
	else if (to_sort == 4)
		sort_four_b(stack_b);
	i = -1;
	while (++i < to_sort)
		pa(stack_a, stack_b, 1);
}

void	select_good_sort_a(int *stack_a, int to_sort)
{
	if (to_sort == 2)
		sort_two_a(stack_a);
	else if (to_sort == 3)
		sort_three_a(stack_a);
	else if (to_sort == 4)
		sort_four_a(stack_a);
	else
		bubble_sort(stack_a);
}

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

void	sort_from_a(t_list **first, t_list *elem, int *stack_a, int *stack_b)
{
	t_bbeg	*content;
	int		i;

	content = elem->content;
	if (content->size <= 4)
		return (select_good_sort_a(stack_a, content->size), ft_lstdelmiddle(first, elem));
	i = -1;
	while (++i < content->size) // petite opti possible ici en s'arretant si y'en a pas d'autres a push
	{
		if (get_number_a(stack_a, 0) >= content->min && get_number_a(stack_a, 0) < content->min  + (content->size - (content->size / 2)))
			pb(stack_a, stack_b, 1);
		else
			ra(1);
	}
	i = -1;
	while (++i < content->size / 2)
		rra(1);
	if (content->size % 2 == 0)
		parallel_bubble_limit(stack_a, stack_b, content->size / 2);
	else
		parallel_bubble_limit_odd(stack_a, stack_b, content->size / 2);
	i = -1;
	while (++i < content->size - content->size / 2)
		pa(stack_a, stack_b, 1);
	ft_lstdelmiddle(first, elem);
}

void	push_x_nb_to_a(int *stack_a, int *stack_b, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		pa(stack_a, stack_b, 1);
		i++;
	}
}

void	sort_from_b(t_list **first, t_list *elem, int *stack_a, int *stack_b) // y'a une couille qq part y skip une valeur
{
	t_bbeg	*content;
	int		i;

	content = elem->content;
	if (content->size <= 4)
		return (select_good_sort_b(stack_a, stack_b, content->size), push_x_nb_to_a(stack_a, stack_b, content->size), ft_lstdelmiddle(first, elem));
	i = -1;
	while (++i < content->size) // petite opti possible ici en s'arretant si y'en a pas d'autres a push
	{
		if (get_number_b(stack_b, 0) >= content->min && get_number_b(stack_b, 0) < content->min  + (content->size - (content->size / 2)))
			rb(1);
		else
			pa(stack_a, stack_b, 1);
	}
	i = -1;
	while (++i < content->size - content->size / 2)
		rrb(1);
	if (content->size % 2 == 0)
		parallel_bubble_limit(stack_a, stack_b, content->size / 2);
	else
		parallel_bubble_limit_odd(stack_a, stack_b, content->size / 2);
	i = -1;
	while (++i < content->size - content->size / 2)
		pa(stack_a, stack_b, 1);
	ft_lstdelmiddle(first, elem);
}

void	go_back_if(int direction, int rotations)
{
	if (direction == 0)
	{
		while (rotations > 0)
		{
			rra(1);
			rotations--;
		}
	}
}

void	push_to_b(int direction, t_bbeg *content, int *stack_a, int *stack_b)
{
	int	i;

	i = 0;
	while (i < content->size)
	{
		if (get_number_a(stack_a, 0) >= content->min && get_number_a(stack_a, 0) < content->min  + (content->size - (content->size / 2)))
		{
			pb(stack_a, stack_b, 1);
			if (!direction)
				rra(1);
		}
		else
		{
			if (direction)
				ra(1);
			else
				rra(1);
		}
		i++;
	}
}

void	push_to_a(t_bbeg *content, int *stack_a, int *stack_b)
{
	int	i;

	i = 0;
	while (i < content->size)
	{
		if (get_number_a(stack_a, 0) >= content->min && get_number_a(stack_a, 0) < content->min  + (content->size - (content->size / 2)))
			rb(1);
		else
			pa(stack_a, stack_b, 1);
		i++;
	}
	i = -1;
	while (++i < content->size - content->size / 2)
		rrb(1);
}

void	split_from_a(t_list **first, int *stack_a, int *stack_b, int *stack_s);

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
	if (add_node(first, 'a', content->size / 2, content->min + (content->size - (content->size / 2))) == 0)
		return (cancel_everything(first, stack_a, stack_b, stack_s));
	if (add_node(first, 'b', (content->size - (content->size / 2)), content->min) == 0)
		return (cancel_everything(first, stack_a, stack_b, stack_s));
	push_to_a(content, stack_a, stack_b);
	ft_lstdelmiddle(first, element);
	split_from_a(first, stack_a, stack_b, stack_s);
}

void	split_from_a(t_list **first, int *stack_a, int *stack_b, int *stack_s) // opti en faisant une fonction specifique au depart car le retours prends plus de temps
{
	static int	direction = 1;
	t_list		*element;
	t_bbeg		*content;

	element = search_for_a(first);
	if (element == NULL)
		return (split_from_b(first, stack_a, stack_b, stack_s));
	content = element->content;
	if (content->size <= 10)
		return (go_back_if(direction, content->size),
			sort_from_a(first, element, stack_a, stack_b), split_from_b(first, stack_a, stack_b, stack_s));
	if (add_node(first, 'a', content->size / 2, content->min + (content->size - (content->size / 2))) == 0)
		return (cancel_everything(first, stack_a, stack_b, stack_s));
	if (add_node(first, 'b', (content->size - (content->size / 2)), content->min) == 0)
		return (cancel_everything(first, stack_a, stack_b, stack_s));
	push_to_b(direction, content, stack_a, stack_b);
	if (direction)
		direction = 0;
	else
		direction = 1;
	ft_lstdelmiddle(first, element);
	split_from_a(first, stack_a, stack_b, stack_s);
}

void	bbeg_sort(int *stack_a, int *stack_b, int *stack_sorted)
{
	t_list	*first;

	first = NULL;
	if (add_node(&first, 'a', len_a(-1), 0) == 0)
		return (cancel_everything(&first, stack_a, stack_b, stack_sorted));
	split_from_a(&first, stack_a, stack_b, stack_sorted);
}
