/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:09:34 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/21 11:05:35 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	while (str[i] && result == 1)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
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
// 	char str[] = "ahelHloz";

// 	int result = ft_str_is_lowercase(str);
// 	printf("%i", result);
// 	return (0);
// }
