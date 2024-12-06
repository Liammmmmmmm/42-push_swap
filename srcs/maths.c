/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:34:04 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/06 15:03:08 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	root(int n)
{
	int	res;

	res = 0;
	if (n < 0)
		return (-1);
	while ((res + 1) * (res + 1) <= n)
		res++;
	return (res);
}

int	power(int nb, int exponent)
{
    int result;
    int i;

	result = 1;
	i = 0;
	while (i < exponent)
	{
		result *= nb;
		i++;
	}
	return (result);
}
