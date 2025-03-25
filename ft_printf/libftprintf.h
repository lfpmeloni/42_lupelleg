/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:12:33 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/25 08:01:33 by lupelleg         ###   ########.fr       */
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

#endif
