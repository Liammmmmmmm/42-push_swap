/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelmiddle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:58:19 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/10 16:48:26 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelmiddle(t_list **first, t_list *lst)
{
	t_list	*current;

	if (!first || !*first || !lst)
		return ;
	if (*first == lst)
	{
		*first = lst->next;
		free(lst->content);
		free(lst);
	}
	else
	{
		current = *first;
		while (current)
		{
			if (current->next == lst)
			{
				current->next = lst->next;
				free(lst->content);
				free(lst);
			}
			current = current->next;
		}
	}
}
