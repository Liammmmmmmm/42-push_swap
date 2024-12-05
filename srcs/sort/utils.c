/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:40:03 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/05 11:41:25 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	min(int *stack, int len)
{
	int i;
	int minv = 2147483647;

	i = 0;
	while (i < len)
	{
		if (stack[i] < minv)
			minv = stack[i];
		i++;
	}
	return (minv);
}

int	max(int *stack, int len)
{
	int i;
	int maxv = -2147483648;

	i = 0;
	while (i < len)
	{
		if (stack[i] < maxv)
			maxv = stack[i];
		i++;
	}
	return (maxv);
}
