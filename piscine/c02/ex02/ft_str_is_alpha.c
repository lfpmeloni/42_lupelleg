/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:08:53 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/22 10:05:40 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	while (str[i] && result == 1)
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
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
// 	char str[] = "AHelloWorlz";

// 	int result = ft_str_is_alpha(str);
// 	printf("%i", result);
// 	return (0);
// }
