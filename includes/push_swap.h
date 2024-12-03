/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:20:36 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/03 13:30:46 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/* ************************************************************************** */
/*                                    ARGS                                    */
/* ************************************************************************** */
void	print_error(void);
int		check_args(int argc, char **argv);
int		check_duplicates(int *tab, int len);

/* ************************************************************************** */
/*                                   STACKS                                   */
/* ************************************************************************** */
int		init_stacks(int **stack_a, int **stack_b, int argc, char **argv);
void	clear_stacks(int *stack_a, int *stack_b);

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

int	len_a(int init);

int	len_b(int init);


#endif