/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:21:35 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/02 16:34:33 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char *arg)
{
	int		i;
	long	test;
	int		sign;
	
	i = -1;
	while (arg[++i])
		if (ft_isdigit(arg[i]) == 0 && (arg[i] != '-' || arg[i] != '+'))
			return (0);
	i = -1;
	sign = 1;
	test = 0;
	if (arg[i + 1] == '-' || arg[i + 1] == '+')
	{
		if (arg[i + 1] == '-')
			sign = -1;
		i++;
	}
	while (arg[++i])
	{
		test = 10 * test + arg[i] - '0';
		if (test * sign < -2147483648 || test * sign > 2147483647)
			return (0);
	}
	return (1);
}

// check_args

// remplir le tableau

// verif les doublons

int main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
}

// Check les args : valide, doublons
// faire un buffer circulaire pour chaque stack, comme ca pas de cassage de cul avec une liste chainee
// remplire les buffer, si possible avec la position trie du truc et pas le vrai chiffre pour simplifier la visu
// faire chaque fonction possible, et quand on l'execute ca write direct l'action dans le term
// faire un bien bel algo de tri
