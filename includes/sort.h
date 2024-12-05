/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:42:08 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/05 13:20:59 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

int		min(int *stack, int len);
int		max(int *stack, int len);

int		first_sort(int **stack_sorted, int *stack_a, int *stack_b, int len);
void	reinit_stack_a(int *stack_a, int argc, char **argv);

#endif