/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:16:21 by lupelleg          #+#    #+#             */
/*   Updated: 2025/02/05 14:16:43 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_malloc(int size)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[(i + j)] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	check_size(int size, char **strs)
{
	int	count;

	count = 0;
	while (strs[count])
		count++;
	if (count < size)
		return (count);
	return (size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		total_len;

	if (size == 0)
		return ((char *)ft_malloc(1));
	size = check_size (size, strs);
	i = 0;
	total_len = 0;
	while (i < size)
		total_len += ft_strlen(strs[i++]);
	total_len += ft_strlen(sep) * (size -1);
	result = ft_malloc(total_len);
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}

// int main(void)
// {
// 	// char *strs1[] = {"Hello", "World", NULL};
// 	// char *strs2[] = {"This", "is", "a", "test", NULL};
// 	// char *strs3[] = {"Only one string", "another string", NULL};
// 	char *strs1[] = {"Hello", "World"};
// 	char *strs2[] = {"This", "is", "a", "test"};
// 	char *strs3[] = {"Only one string", "another string"};
// 	char *sep1 = " ";
// 	char *sep2 = "-";
// 	char *sep3 = ">>>";

// 	char *result;

// 	printf("Test 1:\n");
// 	result = ft_strjoin(2, strs1, sep1);
// 	printf("Result: %s\n", result);
// 	free(result);

// 	printf("Test 2:\n");
// 	result = ft_strjoin(4, strs2, sep2);
// 	printf("Result: %s\n", result);
// 	free(result);

// 	printf("Test 3:\n");
// 	result = ft_strjoin(2, strs3, sep3);
// 	printf("Result: %s\n", result);
// 	free(result);

// 	printf("Test 4 (size 0):\n");
// 	result = ft_strjoin(2, strs1, sep1);
// 	printf("Result: %s\n", result);
// 	free(result);

// 	return 0;
// }
