/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:10:07 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/21 11:06:43 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	while (str[i] && result == 1)
	{
		if (str[i] >= ' ' && str[i] <= '~')
			;
		else
			result = 0;
		i++;
	}
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = " HELL    OZA~";

// 	int result = ft_str_is_printable(str);
// 	printf("%i", result);
// 	return (0);
// }
