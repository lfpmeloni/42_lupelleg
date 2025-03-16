/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:08:01 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/16 14:24:30 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*   The strlcat() function appends the NUL-terminated string src to the end of
*   dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating
*   the result.
*   The function returns the total length of the string they tried to create.
*   For strlcat() that means the initial length of dst plus the length of src.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	j;

	src_len = 0;
	dst_len = 0;
	while (dst[dst_len] != '\0' && dst_len < size)
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dst_len == size)
		return (size + src_len);
	i = dst_len;
	j = 0;
	while (src[j] != '\0' && i < (size - 1))
		dst[i++] = src [j++];
	if (i < size)
		dst[i] = '\0';
	return (dst_len + src_len);
}
