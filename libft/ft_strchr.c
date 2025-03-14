/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:05:02 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/14 12:26:02 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*  The strchr() function locates the first occurence of c (converted to a char)
*  in the string pointed to by s. The terminating null character is considered
*  to be part of the string; therefore if c is '\0', the function locate the
*  terminating '\0'.
*  The strrchr() function is identical to strchr(), except it locates the last
*  occurance of c.
*  The functions return a pointer to the located character, or NULL if the
*  character does not appear in the string.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
