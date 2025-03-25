/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:35:39 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/24 11:36:33 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->star = 0;
	flags->type = 0;
	flags->len = 0;
}

static int	ft_parse_star(t_flags *flags, va_list args)
{
	flags->star = 1;
	flags->width = va_arg(args, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
	}
	return (1);
}

static int	ft_parse_width(t_flags *flags, const char *format, va_list args)
{
	int	i;

	i = 0;
	if (format[i] == '*')
		return (ft_parse_star(flags, args));
	while (ft_isdigit(format[i]))
	{
		flags->width = (flags->width * 10) + (format[i] - '0');
		i++;
	}
	return (i);
}
