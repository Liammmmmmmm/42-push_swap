/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:56:13 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/03 12:58:49 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	pos_a(int init)
{
	static int	posa;
	if (init >= 0)
		posa = init;
	return (posa);
}

int	pos_b(int init)
{
	static int	posb;
	if (init >= 0)
		posb = init;
	return (posb);
}

int	len_a(int init)
{
	static int	lena;
	if (init >= 0)
		lena = init;
	return (lena);
}

int	len_b(int init)
{
	static int	lenb;
	if (init >= 0)
		lenb = init;
	return (lenb);
}
