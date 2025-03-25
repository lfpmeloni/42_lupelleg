/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:34:32 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/24 11:36:38 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_type(t_flags *flags, va_list args)
{
	int	count;

	count = 0;
	if (flags->type == 'c')
		count += ft_print_char(flags, va_arg(args, int));
	else if (flags->type == 's')
		count += ft_print_string(flags, va_arg(args, char *));
	else if (flags->type == 'p')
		count += ft_print_pointer(flags, va_arg(args, unsigned long long));
	else if (flags->type == 'd' || flags->type == 'i')
		count += ft_print_int(flags, va_arg(args, int));
	else if (flags->type == 'u')
		count += ft_print_unsigned_int(flags, va_arg(args, unsigned int));
	else if (flags->type == 'x' || flags->type == 'X')
		count += ft_print_hex(flags, va_arg(args, unsigned int));
	else if (flags->type == '%')
		count += ft_print_percent(flags);
	return (count);
}
