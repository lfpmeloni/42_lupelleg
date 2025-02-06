/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:00:12 by lupelleg          #+#    #+#             */
/*   Updated: 2025/02/06 16:00:14 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				if (argv[1][i] >= 'n')
					put_char(argv[1][i] - 13);
				else
					put_char(argv[1][i] + 13);
			}
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				if (argv[1][i] >= 'N')
					put_char(argv[1][i] - 13);
				else
					put_char(argv[1][i] + 13);
			}
			else
				put_char(argv[1][i]);
			i++;
		}
	}
	put_char('\n');
	return (0);	
}