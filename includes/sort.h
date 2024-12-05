/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:42:08 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/05 17:10:00 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

int		min(int *stack, int len);
int		max(int *stack, int len);

void	sort(int *stack_a, int *stack_b, int *stack_sorted);

int		first_sort(int **stack_sorted, int *stack_a, int *stack_b, int len);
void	reinit_stack_a(int *stack_a, int argc, char **argv);
int		find_quickest_b(int *stack_b, int actual_index, int number);
int		find_quickest_inferior_a(int *stack_a, int number);
int		find_quickest_supperior_b(int *stack_b, int number);

int		rotate_to_shortest_inferior_a(int *stack_a, int limit);
int		rotate_to_shortest_supperior_b(int *stack_b, int limit);

#endif