/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:58:03 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/18 13:24:23 by lupelleg         ###   ########.fr       */
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

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)last);
}
