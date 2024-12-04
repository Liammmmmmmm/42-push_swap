/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:18:11 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/04 17:19:40 by lilefebv         ###   ########lyon.fr   */
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

int is_sort(int *stack_a, int *stack_b) {
	int	is_sorted_a;
	int	is_sorted_b;
	int	is_sorted_reverse_a;
	int	is_sorted_reverse_b;
	int	is_rotated_sorted_a;
	int i;

	is_sorted_a = is_sorted(stack_a, pos_a(-1), len_a(-1));
	is_sorted_b = is_sorted(stack_b, pos_b(-1), len_b(-1));
	is_sorted_reverse_a = is_sorted_reverse(stack_a, pos_a(-1), len_a(-1));
	is_sorted_reverse_b = is_sorted_reverse(stack_b, pos_b(-1), len_b(-1));
	is_rotated_sorted_a = sorted_if_rotated(stack_a, pos_a(-1), len_a(-1));
    if (is_sorted_a && is_sorted_reverse(stack_b, pos_b(-1), len_b(-1))) {
        while (len_b(-1) > 0)
			pa(stack_a, stack_b);
        return 1;
    }
    if (is_sorted_a && is_sorted_b) {
        while (len_b(-1) > 0)
		{
			rrb();
			pa(stack_a, stack_b);
		}
        return 1;
    }
    if (is_sorted_reverse_a && is_sorted_b) {
        while (len_a(-1) > 0)
		{
			rra();
			pb(stack_a, stack_b);
		}
        while (len_b(-1) > 0)
		{
			rra();
			pa(stack_a, stack_b);
		}
        return 1;
    }
    if (is_sorted_reverse_a && is_sorted_reverse_b) {
        while (len_a(-1) > 0)
		{
			rra();
			pb(stack_a, stack_b);
		}
        while (len_b(-1) > 0)
			pa(stack_a, stack_b);
        return 1;
    }
    if (is_sorted_a && len_b(-1) == 0) {
        return 1;
    }
    if (is_rotated_sorted_a != len_a(-1)) {
		i = 0;
        if (is_rotated_sorted_a < 0)
		{
			while (i < -is_rotated_sorted_a)
			{
				rra();
				i++;
			}
		}
		else
		{
			while (i < is_rotated_sorted_a)
			{
				rr();
				i++;
			}
		}
        return 1;
    }
    return 0;
}

void quick_sort_a(int *stack_a, int *stack_b,  int len);

void quick_sort_b(int *stack_a, int *stack_b,  int len)
{
    int	pivot;
	int count;
	int i;
	
    if (is_sort(stack_a, stack_b))
		return;
    if (len == 2) {
        if (stack_b[pos_b(-1)] > stack_b[pos_b(-1) + 1]) 
			sb(stack_a);
        return (rb(), rb());
    }
	else if (len <= 1)
		return rb();
    pivot = stack_b[pos_b(-1)];
	count = 0;
	i = 0;
    while (i < len) {
        if (stack_b[pos_b(-1)] < pivot) {
            pa(stack_a, stack_b);
            count++;
        } else {
            rb();
        }
		i++;
    }
    quick_sort_a(stack_a, stack_b, count);
    i = 0;
	while (i < count)
	{
		rb();
		i++;
	}
    quick_sort_b(stack_a, stack_b, len - count);
    i = 0;
	while (i < len - count)
	{
		rb();
		i++;
	}
}

void quick_sort_a(int *stack_a, int *stack_b, int len)
{
	int	pivot;
	int count;
	int i;
	
    if (is_sort(stack_a, stack_b))
		return;
    if (len == 2) {
        if (stack_a[pos_a(-1)] > stack_a[pos_a(-1) + 1]) 
			sa(stack_a);
        return (ra(), ra());
    }
	else if (len <= 1)
		return (ra());
    pivot = stack_a[pos_a(-1)];
    count = 0;
	i = 0;
    while (i < len) {
        if (stack_a[pos_a(-1)] < pivot) {
            pb(stack_a, stack_b);
            count++;
        } else {
            ra();
        }
		i++;
    }

    quick_sort_b(stack_a, stack_b, count);
    quick_sort_a(stack_a, stack_b, len - count);
}

void	sort(int *stack_a, int *stack_b)
{
	quick_sort_a(stack_a, stack_b,  len_a(-1));
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
