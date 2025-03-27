/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:12:33 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/27 14:13:18 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
	int		star;
	int		type;
	int		len;
}				t_flags;

int		ft_printf(const char *format, ...);
int		ft_parse_flags(t_flags *flags, const char *format, va_list args);
int		ft_print_type(t_flags *flags, va_list args);
int		ft_print_char(t_flags *flags, int c);
int		ft_print_string(t_flags *flags, char *str);
int		ft_print_pointer(t_flags *flags, unsigned long long n);
int		ft_print_int(t_flags *flags, int n);
int		ft_print_unsigned_int(t_flags *flags, unsigned int n);
int		ft_print_hex(t_flags *flags, unsigned int n);
int		ft_print_percent(t_flags *flags);

#endif
