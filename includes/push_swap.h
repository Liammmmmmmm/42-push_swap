/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:20:36 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/05 11:42:04 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stacks.h"
# include "sort.h"

void	print_error(void);
int		check_args(int argc, char **argv);
int		check_duplicates(int *tab, int len);

void	sort(int *stack_a, int *stack_b);

#endif