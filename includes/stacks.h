/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:21:24 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/08 12:49:24 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

int		init_stacks(int **stack_a, int **stack_b, int argc, char **argv);
void	clear_stacks(int *stack_a, int *stack_b);
void	replace_nb_by_index(int *stack_a, int *stack_sorted, int stack_len);
void	reinit_stack_a(int *stack_a, int *stack_b, int argc, char **argv);

/**
 * @brief Swap the first two elements of stack a.
 *
 * Swaps the positions of the first two elements at the top of stack `a`. 
 * If there are fewer than two elements in the stack, no action is performed.
 *
 * @param stack_a Pointer to the stack `a`.
 */
void	sa(int *stack_a, int print);

/**
 * @brief Swap the first two elements of stack b.
 *
 * Swaps the positions of the first two elements at the top of stack `b`. 
 * If there are fewer than two elements in the stack, no action is performed.
 *
 * @param stack_b Pointer to the stack `b`.
 */
void	sb(int *stack_b, int print);

/**
 * @brief Swap the first two elements of both stacks simultaneously.
 *
 * Executes both `sa` and `sb` operations, swapping the first two elements 
 * of stack `a` and stack `b` simultaneously. If either stack has fewer than
 * two elements, no action is performed on that stack.
 *
 * @param stack_a Pointer to the stack `a`.
 * @param stack_b Pointer to the stack `b`.
 */
void	ss(int *stack_a, int *stack_b, int print);

/**
 * @brief Push the top element of stack b onto stack a.
 *
 * Moves the first element from the top of stack `b` to the top of stack `a`.
 * If stack `b` is empty, no action is performed.
 *
 * @param stack_a Pointer to the stack `a`.
 * @param stack_b Pointer to the stack `b`.
 */
void	pa(int *stack_a, int *stack_b, int print);

/**
 * @brief Push the top element of stack a onto stack b.
 *
 * Moves the first element from the top of stack `a` to the top of stack `b`. 
 * If stack `a` is empty, no action is performed.
 *
 * @param stack_a Pointer to the stack `a`.
 * @param stack_b Pointer to the stack `b`.
 */
void	pb(int *stack_a, int *stack_b, int print);

/**
 * @brief Rotate operations for stacks.
 * 
 * Shifts all elements of stack `a` up by one position.
 * The first element becomes the last.
 */
void	ra(int print);

/**
 * @brief Rotate operations for stacks.
 * 
 * Shifts all elements of stack `b` up by one position.
 * The first element becomes the last.
 */
void	rb(int print);

/**
 * @brief Rotate operations for stacks.
 * 
 * Executes both `ra` and `rb` simultaneously.
 */
void	rr(int print);

/**
 * @brief Reverse rotate operations for stacks.
 * 
 * Shifts all elements of stack `a` down by one position.
 * The last element becomes the first.
 */
void	rra(int print);

/**
 * @brief Reverse rotate operations for stacks.
 * 
 * Shifts all elements of stack `b` down by one position.
 * The last element becomes the first.
 */
void	rrb(int print);

/**
 * @brief Reverse rotate operations for stacks.
 * 
 * Executes both `rra` and `rrb` simultaneously.
 */
void	rrr(int print);

/* ************************************************************************** */

/**
 * Get pos a with pos_a(-1), set pos a with pos_a(number)
 * 
 * @param init Either your number in order to set a number, -1 to get the 
 *             actual pos
 * @return the actual pos a
 */
int		pos_a(int init);

/**
 * Get pos a with pos_b(-1), set pos a with pos_b(number)
 * 
 * @param init Either your number in order to set a number, -1 to get the 
 *             actual pos
 * @return the actual pos b
 */
int		pos_b(int init);

/**
 * Get len a with len_a(-1), set len a with len_a(number)
 * 
 * @param init Either your number in order to set a len, -1 to get the 
 *             actual len
 * @return the actual len a
 */
int		len_a(int init);

/**
 * Get len b with len_b(-1), set len b with len_b(number)
 * 
 * @param init Either your number in order to set a len, -1 to get the 
 *             actual len
 * @return the actual len b
 */
int		len_b(int init);

int		get_number_a(int *stack_a, int index);
int		get_number_b(int *stack_b, int index);

/* ************************************************************************** */

#endif