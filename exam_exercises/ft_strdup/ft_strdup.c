/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:00:22 by lupelleg          #+#    #+#             */
/*   Updated: 2025/02/06 16:00:30 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char *ptr;
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	ptr = (char *)malloc((i * sizeof(char)) + 1);
	i = 0;
	while (src[i] != '\0')
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
// 	char c[] = "Test1";
// 	char *ptr;
// 	ptr = ft_strdup(c);
// 	printf("%s\n", ptr);
// 	return (0);
// }
