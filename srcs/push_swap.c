/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:21:35 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/02 12:24:36 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	ft_printf("arg amount : %d\n", argc - 1);
	while (argc > 1)
	{
		ft_printf("arg %d : %s\n", argc - 1, argv[argc - 1]);
		argc--;
	}
}