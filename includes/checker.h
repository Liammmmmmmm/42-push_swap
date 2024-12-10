/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:49:02 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/10 16:50:05 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

typedef enum e_checker
{
	ERROR_UNKNOWN,
	OK,
	KO
}	t_checker;

void	print_error(void);
int		check_args(int argc, char **argv);
int		check_duplicates(int *tab, int len);

int		root(int n);
int		power(int nb, int exponent);

#endif