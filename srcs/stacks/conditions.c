/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:34:13 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/04 16:55:03 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	is_sorted(int *stack, int pos, int len)
{
	int	i;
	int last;

	if (len == 0)
		return (-1);
	i = pos + 1;
	last = stack[pos];
	while (i < len)
	{
		if (stack[i] < last)
			return (0);
		last = stack[i];
		i++;
	}
	i = 0;
	while (i < pos)
	{
		if (stack[i] < last)
			return (0);
		last = stack[i];
		i++;
	}
	return (1);
}

int	is_sorted_reverse(int *stack, int pos, int len)
{
	int	i;
	int last;

	if (len == 0)
		return (-1);
	i = pos + 1;
	last = stack[pos];
	while (i < len)
	{
		if (stack[i] > last)
			return (0);
		last = stack[i];
		i++;
	}
	i = 0;
	while (i < pos)
	{
		if (stack[i] > last)
			return (0);
		last = stack[i];
		i++;
	}
	return (1);
}

int	sorted_if_rotated(int *stack, int pos, int len)
{
	int	i;

	i = 0;	
	while (i < len)
	{
		if (is_sorted(stack, i, len))
			return (i - pos);
		i++;
	}
	return (len);
}
