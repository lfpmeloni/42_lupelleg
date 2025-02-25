/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:20:38 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/20 16:02:10 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// int	main(void)
// {
// 	int	x;
// 	int	y;

// 	x = 4;
// 	y = 2;
// 	ft_swap(&x, &y);
// 	printf("%d %d", x, y);
// 	return (0);
// }
