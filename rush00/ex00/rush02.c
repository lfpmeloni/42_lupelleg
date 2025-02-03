/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:14:26 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/18 15:04:02 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_line(int line_size, char ch_1, char ch_2, char ch_3);

void	rush02(int columns, int lines)
{
	int	line;

	line = 1;
	if (columns >= 1 && lines >= 1)
	{
		while (line <= lines)
		{
			if (line == 1)
				print_line(columns, 'A', 'B', 'A');
			else if (line == lines)
				print_line(columns, 'C', 'B', 'C');
			else
				print_line(columns, 'B', ' ', 'B');
			line++;
		}
	}
	else
		write(1, "invalid parameters", 18);
}
