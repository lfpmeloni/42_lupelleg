/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:43:49 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/14 13:05:14 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*  The strncmp() lexicographically compares not more than n characters from the
*  null-terminated strings s1 and s2. Characters that appear after a '\0' char
*  are not compared.
*  The function returns an integer greater than, equal to, or less than 0,
*  according as the string s1 is greater than, equal to, or less than the string
*  s2. The comparison is done using unsigned characters.
*/

#include "libft.h"

int	strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
