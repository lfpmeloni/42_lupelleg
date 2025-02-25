/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:10:41 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/29 11:03:13 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;
	int	i;

	result = 1;
	i = 1;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		result *= i++;
	}
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n",ft_iterative_factorial(-5));
// 	return (0);
// }