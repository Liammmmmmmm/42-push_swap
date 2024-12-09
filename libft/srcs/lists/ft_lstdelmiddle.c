/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelmiddle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:58:19 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/09 14:11:09 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelmiddle(t_list **first, t_list *lst)
{
    t_list	*current;
    t_list	*prev;

    if (!first || !*first || !lst)
        return ;
    if (*first == lst)
    {
        *first = lst->next;
        free(lst->content);
        free(lst);
		lst = NULL;
    }
    else
    {
        current = *first;
        prev = NULL;
        while (current)
        {
            if (current == lst)
            {
                if (prev)
                    prev->next = current->next;
                free(current->content);
                free(current);
                break;
            }
            prev = current;
            current = current->next;
        }
    }
}
