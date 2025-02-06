/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:51:32 by lupelleg          #+#    #+#             */
/*   Updated: 2025/02/06 16:15:30 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] != '\0' && (argv[1][i] == ' ' || argv[1][i] == '\t'))
		{
			i++;
		}
		while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
		{
			putchar(argv[1][i]);
			i++;
		}
	}
	putchar('\n');
	return (0);	
}
