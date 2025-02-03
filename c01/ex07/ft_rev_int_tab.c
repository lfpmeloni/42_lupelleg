/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:50:50 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/20 17:06:36 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}

// int	main(void)
// {
// 	int	i;
// 	int	arr[5] = {1, 2, 3, 4, 5};
// 	int	*ptr = arr; // ptr points to the first element of arr

// 	ft_rev_int_tab(arr, 5);
// 	for (i = 0; i < 5; i++)
// 	{
// 		printf("%d ", arr[i]);
// 	}
// }
