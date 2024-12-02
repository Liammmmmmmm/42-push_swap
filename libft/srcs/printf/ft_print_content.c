/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:40:19 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/28 17:07:55 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_i(int n, int *counter)
{
	if (n == -2147483648)
		return (ft_print_s("-2147483648", counter));
	else if (n < 0)
	{
		n = -n;
		ft_printchar_count('-', counter);
	}
	if (n <= 9)
		ft_printchar_count("0123456789"[n], counter);
	else
	{
		ft_print_i(n / 10, counter);
		ft_printchar_count("0123456789"[n % 10], counter);
	}
}

void	ft_print_base(unsigned int n, char *base, int *counter)
{
	size_t	baselen;

	baselen = ft_strlen(base);
	if (n <= baselen - 1)
		ft_printchar_count(base[n], counter);
	else
	{
		ft_print_base(n / baselen, base, counter);
		ft_printchar_count(base[n % baselen], counter);
	}
}

void	ft_print_x_long(unsigned long long n, int *counter)
{
	if (n <= 15)
		ft_printchar_count("0123456789abcdef"[n], counter);
	else
	{
		ft_print_x_long(n / 16, counter);
		ft_printchar_count("0123456789abcdef"[n % 16], counter);
	}
}

void	ft_print_p(void *p, int *counter)
{
	unsigned long long	pointer_long;

	pointer_long = (unsigned long long)p;
	if (pointer_long == 0)
		return (ft_print_s("(nil)", counter));
	ft_print_s("0x", counter);
	ft_print_x_long(pointer_long, counter);
}

void	ft_print_s(const char *str, int *counter)
{
	size_t	i;

	if (str == NULL)
		return (ft_print_s("(null)", counter));
	i = 0;
	while (str[i])
	{
		ft_printchar_count(str[i], counter);
		i++;
	}
}
