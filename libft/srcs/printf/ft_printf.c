/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:37:16 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/28 17:07:05 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar_count(int c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

static void	ft_print_param(char type, va_list args, int *counter)
{
	if (type == 'c')
		ft_printchar_count(va_arg(args, int), counter);
	else if (type == 's')
		ft_print_s(va_arg(args, char *), counter);
	else if (type == 'p')
		ft_print_p(va_arg(args, void *), counter);
	else if (type == 'i' || type == 'd')
		ft_print_i(va_arg(args, int), counter);
	else if (type == 'u')
		ft_print_base(va_arg(args, unsigned int), "0123456789", counter);
	else if (type == 'x')
		ft_print_base(va_arg(args, unsigned int), "0123456789abcdef", counter);
	else if (type == 'X')
		ft_print_base(va_arg(args, unsigned int), "0123456789ABCDEF", counter);
	else if (type == '%')
		ft_printchar_count('%', counter);
}

static int	is_valid_conversion(char c)
{
	size_t	i;

	i = 0;
	while ("cspdiuxX%\0"[i])
	{
		if ("cspdiuxX%"[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_print_all(const char *str, int *counter, va_list args)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_valid_conversion(str[i + 1]))
		{
			ft_print_param(str[i + 1], args, counter);
			i++;
		}
		else
			ft_printchar_count(str[i], counter);
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		char_counter;

	char_counter = 0;
	va_start(args, str);
	ft_print_all(str, &char_counter, args);
	va_end(args);
	return (char_counter);
}
