/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:19:38 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/18 15:06:22 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_line(int line_size, char ch_1, char ch_2, char ch_3)
{
	int	letter;

	letter = 1;
	while (letter <= line_size)
	{
		if (letter == 1)
			ft_putchar(ch_1);
		else if (letter == line_size)
			ft_putchar(ch_3);
		else
			ft_putchar(ch_2);
		letter++;
	}
	ft_putchar('\n');
}

void	rush(int columns, int lines)
{
	int	line;

	line = 1;
	if (columns >= 1 && lines >= 1)
	{
	while (line <= lines)
		{
			if ((line == 1) || (line == lines))
				print_line(columns, 'A', 'B', 'C');
			else
				print_line(columns, 'B', ' ', 'B');
			line++;
		}
	}
	else
	write(1, "invalid parameters", 18);
}
