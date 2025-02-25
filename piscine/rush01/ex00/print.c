/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyigit <yuyigit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:42:30 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/26 14:44:43 by yuyigit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_matrix(int result[4][4])
{
	int		i;
	int		j;
	char	text;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			text = result[i][j] + '0';
			write(1, &text, 1);
			if (j < 3)
			{
				write(1, " ", 1);
			}
			j++;
		}
		j = 0;
		i++;
		write(1, "\n", 1);
	}
}
