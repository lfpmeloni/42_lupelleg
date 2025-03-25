/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:14:34 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/24 11:36:41 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  The functions in the printf() family produce output according to a format.
 *  the function returns the number of characters printed (excluding the null
 *  byte used to end output to strings).
 *  Note: A variadic function can take a variable number of arguments (including
 *  zero arguments) of different types.
 */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			i += ft_parse_flags(&flags, &format[i], args);
			count += ft_print_type(&flags, args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
