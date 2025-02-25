/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:11:31 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/22 13:29:54 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		temp;
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] >= 32 && (unsigned char)str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			temp = hex_digits[(unsigned char)str[i] / 16];
			write(1, &temp, 1);
			temp = hex_digits[(unsigned char)str[i] % 16];
			write(1, &temp, 1);
		}
		i++;
	}
}

// int	main(void)
// {
// 	char	str[] = "Coucou\ntu vas bien ?";

// 	ft_putstr_non_printable(str);
// 	return (0);
// }
