/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:42:54 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/13 18:07:18 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*   The strlcpy() function copies up to size -1 characters from the
*   NUL-terminated string src to dst, NUL-terminating the result.
*   The function returns the total length of the string they tried to create.
*   For strlcpy() that means the length of src.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while ((i < (size - 1)) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
