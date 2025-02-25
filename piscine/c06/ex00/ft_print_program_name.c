/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:26:03 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/29 13:19:49 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		size;
	int		i;
	char	c;
	char	*prog_name;

	prog_name = argv[0];
	size = 0;
	while (prog_name[size])
	{
		size++;
	}
	if (argc >= 0)
	{
		i = 0;
		while (i < size)
		{
			c = prog_name[i];
			write(1, &c, 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
