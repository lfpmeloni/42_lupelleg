/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:19:27 by lupelleg          #+#    #+#             */
/*   Updated: 2025/02/06 16:47:20 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
	if (n == 1)
		return (1);
	else if (n == 0 || n % 2 != 0)
		return (0);
	return (is_power_of_2(n / 2));
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", is_power_of_2(31));
// 	return (0);
// }
