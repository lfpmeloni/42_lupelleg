/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:18:11 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/30 14:24:45 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		size;
	char	*ptr;
	int		i;

	size = 0;
	while (src[size])
	{
		size++;
	}
	ptr = (char *)malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = "Test copy";
// 	char *ptr;

// 	ptr = ft_strdup(str);
// 	if (ptr == NULL)
// 	{
// 		printf("Memory allocation failed\n", ptr);
// 		return (1);
// 	}
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	return (0);
// }
