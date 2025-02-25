/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:09:50 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/21 11:06:07 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	while (str[i] && result == 1)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
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
// 	char str[] = "HELLOZA";

// 	int result = ft_str_is_uppercase(str);
// 	printf("%i", result);
// 	return (0);
// }
