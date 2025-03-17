/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:32:17 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/17 16:58:03 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*  The strdup() function allocates sufficient memory for a copy of the string
*  s1, does the copy, anf returns a pointer to it. The pointer may subsequently
*  be used as an argument to the function free. If insufficient memory is
*  available, NULL is returned and errno is set to ENOMEM.
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	str_len;
	char	*dup;

	if (!s1)
		return (NULL);
	str_len = ft_strlen(s1);
	dup = (char *)malloc((str_len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s1, str_len + 1);
	return (dup);
}
