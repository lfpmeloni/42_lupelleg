/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:09:13 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/21 11:04:32 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	while (str[i] && result == 1)
	{
		if (str[i] >= '0' && str[i] <= '9')
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
// 	char str[] = "012345a6789";

// 	int result = ft_str_is_numeric(str);
// 	printf("%i", result);
// 	return (0);
// }
