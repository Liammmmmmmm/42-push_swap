/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:18:11 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/04 12:41:09 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Simplest sort possible
int	min(int *stack)
{
	int i;
	int min = 2147483647;

	i = 0;
	while (i < len_a(-1))
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

void	sort(int *stack_a, int *stack_b)
{
	int minv;

	while (len_a(-1) > 0)
	{
		minv = min(stack_a);
		while (stack_a[pos_a(-1)] != minv)
			ra();
		pb(stack_a, stack_b);
	}
	while (len_b(-1) > 0){
		pa(stack_a, stack_b);
	}
}
*/

void	sort(int *stack_a, int *stack_b)
{
	
}

/*

int is_sort(stack a, stack b)
{
if (stack a == sort && stack b == reverse sort)
tout push dans a et hop fini

if (stack a == sort && stack b == sort)
tout push dans a a l'envers et hop fini

if (stack a == reverse sort && stack b == sort)
tout push dans b a l'envers, tout repush dans a a l'envers et hop fini

if (stack a == reverse sort && stack b == reverse sort)
tout push dans b a l'envers, tout repush dans a et hop fini

if (stack a == sort && stack b == vide)
fini

if (stock a == sors si rotate de x && stack b == vide)
rotate de x puis fini

}
void quick_sort_b(int *stack_a, int *stack_b, int len)
{
	if(is_sort(stack a, stack b))
		return ;
	if(len == 2)
		if(unsort)
			sb();
	choisir un pivot dans b

	balancer dans a tous les elements inferieurs au pivot (dans la limite de len)
	
	les rebalancer dans B
	
	quick_sort_b(stack_a, stack_b, nb elements reenvoye dans b)
	
	rotate de (nb elements reenvoye dans b)

	quick_sort_b(stack_a, stack_b, len - nb elements reenvoye dans b)

	rotate de (len - nb elements reenvoye dans b)
}

void quick_sort_a(int *stack_a, int *stack_b, int len)
{
	if(is_sort(stack a, stack b))
		return ;
	if(len == 2)
		if(unsort)
			sb();
	choisir un pivot dans a

	balancer dans b tous les elements inferieurs au pivot (dans la limite de len)
	
	quick_sort_b(stack_a, stack_b, nb elements envoye dans b)
	
	quick_sort_a(stack_a, stack_b, len - nb elements reenvoye dans a)
}


*/
