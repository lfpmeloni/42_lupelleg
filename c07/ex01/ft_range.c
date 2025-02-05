/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:29:16 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/30 14:58:08 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	i;

	if (min >= max)
		return (NULL);
	ptr = (int *)malloc((max - min) * sizeof(int));
	i = 0;
	while (min < max)
	{
		ptr[i] = min;
		min++;
		i++;
	}
	return (ptr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int *ptr;
// 	int min;
// 	int max;
// 	int size;
// 	int i;

// 	min = 1;
// 	max = 6;
// 	size = max - min;
// 	ptr = ft_range(min, max);
// 	if (ptr == NULL)
// 	{
// 		printf("Memory allocation failed\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d\n", ptr[i]);
// 		i++;
// 	}
// 	free(ptr);
// 	return (0);
// }