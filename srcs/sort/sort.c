/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:18:11 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/05 13:27:07 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	insert_sort(int *stack_a, int *stack_b)
// {
// 	int minv;

// 	while (len_a(-1) > 0)
// 	{
// 		minv = min(stack_a);
// 		while (stack_a[pos_a(-1)] != minv)
// 			ra();
// 		pb(stack_a, stack_b);
// 	}
// 	while (len_b(-1) > 0){
// 		pa(stack_a, stack_b);
// 	}
// }

void	sort(int *stack_a, int *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return ;
}

/*
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
    if (is_sorted_a && is_sorted_reverse_b)
	{
        while (len_b(-1) > 0)
			pa(stack_a, stack_b);
        return 1;
    }
    if (is_sorted_a && is_sorted_b)
	{
        while (len_b(-1) > 0)
		{
			rrb();
			pa(stack_a, stack_b);
		}
        return 1;
    }
    if (is_sorted_reverse_a && is_sorted_b)
	{
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
    if (is_sorted_reverse_a && is_sorted_reverse_b)
	{
        while (len_a(-1) > 0)
		{
			rra();
			pb(stack_a, stack_b);
		}
        while (len_b(-1) > 0)
			pa(stack_a, stack_b);
        return 1;
    }
    if (is_sorted_a && len_b(-1) == 0)
        return 1;
    if (is_rotated_sorted_a != len_a(-1) && len_b(-1) == 0)
	{
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
		return ft_putstr_fd("tkt chef c'est trie", 0);
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
	if (count == 0)
	{
		pivot = stack_b[len_b(-1) - 1];
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
	if (count == 0)
	{
		pivot = stack_a[len_a(-1) - 1];
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
	}

    quick_sort_b(stack_a, stack_b, count);
    quick_sort_a(stack_a, stack_b, len - count);
}

void	sort(int *stack_a, int *stack_b)
{
	quick_sort_a(stack_a, stack_b,  len_a(-1));
	// while (len_b(-1) > 0)
	// 		pa(stack_a, stack_b);
}
*/
/*
Par ex 2 3 5 1 4 y pete un cable
*/
