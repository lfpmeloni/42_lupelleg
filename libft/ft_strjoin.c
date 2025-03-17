/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:32:01 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/17 17:48:26 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  Allocates memory (using malloc(3)) and returns a new string, which is the
 *  result of concatening 's1' and 's2'.
 *  The function returns the new string or NULL if the allocation fails.
 */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*ptr;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	size = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, size + 1);
	ft_strlcat(ptr, s2, size + 1);
	return (ptr);
}
