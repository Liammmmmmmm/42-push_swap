/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:20:36 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/10 16:00:06 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stacks.h"
# include "sort.h"

typedef enum e_actions {
	UNKNOWN,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
} t_actions;

# ifndef ALGO
#  define ALGO 0
# endif

void	print_error(void);
int		check_args(int argc, char **argv);
int		check_duplicates(int *tab, int len);

int		root(int n);
int		power(int nb, int exponent);

#endif