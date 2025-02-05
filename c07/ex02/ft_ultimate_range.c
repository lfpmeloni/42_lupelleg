/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:30:08 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/30 17:13:50 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = (int *)malloc(size * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int *ptr = NULL;
// 	int min;
// 	int max;
// 	int size;
// 	int i;

// 	min = 1;
// 	max = 6;
// 	size = ft_ultimate_range(&ptr, min, max);
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
