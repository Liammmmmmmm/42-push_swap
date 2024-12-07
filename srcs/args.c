/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:29:23 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/07 17:24:44 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

int	check_arg(char *arg)
{
	int		i;
	long	test;
	int		sign;

	i = -1;
	while (arg[++i])
		if (ft_isdigit(arg[i]) == 0 && arg[i] != '-' && arg[i] != '+')
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

int	check_unique_arg(char *arg)
{
	int		i;
	long	test;
	int		sign;

	i = -1;
	while (arg[++i])
		if (ft_isdigit(arg[i]) == 0 && arg[i] != '-'
			&& arg[i] != '+' && arg[i] != ' ')
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

int	check_args(int argc, char **argv)
{
	if (argc == 2)
		return (check_unique_arg(argv[1]));
	while (argc > 1)
	{
		argc--;
		if (check_arg(argv[argc]) == 0)
			return (0);
	}
	return (1);
}

int	check_duplicates(int *tab, int len)
{
	int	i;
	int	y;

	i = 0;
	while (i < len - 1)
	{
		y = i + 1;
		while (y < len)
		{
			if (tab[y] == tab[i])
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}
