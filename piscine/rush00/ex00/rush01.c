/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:19:38 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/18 15:14:57 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_line(int line_size, char ch_1, char ch_2, char ch_3);

void	rush01(int columns, int lines)
{
	int	line;

	line = 1;
	if (columns >= 1 && lines >= 1)
	{
		while (line <= lines)
		{
			if (line == 1)
				print_line(columns, '/', '*', '\\');
			else if (line == lines)
				print_line(columns, 92, '*', '/');
			else
				print_line(columns, '*', ' ', '*');
			line++;
		}
	}
	else
		write(1, "invalid parameters", 18);
}
