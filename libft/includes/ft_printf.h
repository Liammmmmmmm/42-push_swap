/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:34:27 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/28 17:08:23 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>

/**
 * @brief A custom implementation of printf function.
 * 
 * This function provides a simplified version of the standard printf function,
 * handling a subset of format specifiers. It supports printing characters, 
 * strings, pointers, integers, unsigned integers, and hexadecimal numbers 
 * in both lowercase and uppercase formats.
 *
 * It does not implement internal buffer management like the original printf 
 * function and only handles the following format specifiers:
 * 
 *  - `%c`: Prints a single character.
 * 
 *  - `%s`: Prints a string (null-terminated).
 * 
 *  - `%p`: Prints a pointer in hexadecimal format.
 * 
 *  - `%d`: Prints a signed decimal (base 10) number.
 * 
 *  - `%i`: Prints a signed integer (base 10) number (same as `%d`).
 * 
 *  - `%u`: Prints an unsigned decimal (base 10) number.
 * 
 *  - `%x`: Prints a number in hexadecimal (base 16) lowercase format.
 * 
 *  - `%X`: Prints a number in hexadecimal (base 16) uppercase format.
 * 
 *  - `%%`: Prints a literal percent sign.
 *
 * @param format A string that specifies the format of the output. It can
 *               contain text and format specifiers (preceded by '%') to 
 *               format the output accordingly.
 * 
 * @return - The total number of characters printed, excluding the terminating
 *         null byte.
 *   
 *         - If an invalid format specifier is encountered, behavior is
 *         undefined, but no characters will be printed for that specifier.
 */
int		ft_printf(const char *str, ...);

void	ft_printchar_count(int c, int *counter);
void	ft_print_s(const char *str, int *counter);
void	ft_print_p(void *p, int *counter);
void	ft_print_i(int n, int *counter);
void	ft_print_base(unsigned int n, char *base, int *counter);

#endif