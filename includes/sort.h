/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:42:08 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/08 17:20:50 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

int		min(int *stack, int len);
int		max(int *stack, int len);

void	sort(int *stack_a, int *stack_b, int *stack_sorted);
void	mysort(int *stack_a, int *stack_b, int *stack_sorted);
void	mysort_little(int *stack_a, int *stack_b, int *stack_sorted);
void	radix_sort_base(int *stack_a, int *stack_b, int *stack_sorted, int b);
void	bbeg_sort(int *stack_a, int *stack_b, int *stack_sorted);
void	bubble_sort(int	*stack_a);

int		first_sort(int **stack_sorted, int *stack_a, int *stack_b, int len);
int		find_quickest_b(int *stack_b, int actual_index, int number);
int		find_quickest_inferior_a(int *stack_a, int number);
int		find_quickest_supperior_b(int *stack_b, int number);

int		rotate_to_shortest_inferior_a(int *stack_a, int limit);
int		rotate_to_shortest_supperior_b(int *stack_b, int limit);

void	sort_two_a(int *stack_a);
void	sort_three_a(int *stack_a);
void	sort_four_a(int *stack_a);

void	sort_two_b(int *stack_b);
void	sort_three_b(int *stack_b);
void	sort_four_b(int *stack_b);

void	move_to_b(int *stack_a, int *stack_b, int limit);

/*    MY SORT     */
void	i_to_b_first(int *stack_a, int *stack_b, int *stack_sorted, int parts);
void	i_to_b(int *stack_a, int *stack_b, int *stack_sorted, int parts);
void	i_to_a(int *stack_a, int *stack_b, int *stack_sorted, int parts);
void	full_insert_sort(int *stack_a, int *stack_b, int *stack_sorted);

/*    BOTBEG     */
void	parallel_bubble_limit(int *stack_a, int *stack_b, int limit);
void	parallel_bubble_limit_odd(int *stack_a, int *stack_b, int limit);

#endif