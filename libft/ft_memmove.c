/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:18:06 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/18 13:11:57 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*  The memmove() function copies n bytes from memory area src to memory area
*  dest. The memory areas may overlap: copying takes place as though the bytes
*  in are first copied into a temporary array that does not overlap src or
*  dest, and the bytes are then copied from the temporary array to dest.
*  The function returns a pointer to dest.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}
