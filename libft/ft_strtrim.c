/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:53:39 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/18 10:15:32 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  Allocates memory using malloc(3) and returns a copy of 's1' with characters
 *  from 'set' removed from the beginning and the end.
 *  The function returns the trimmed string or NULL if the allocation fails.
 */

#include "libft.h"

int	ft_isinset(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	len = ft_strlen(s1);
	while (ft_isinset(set, s1[start]))
		start++;
	while (len > start && ft_isinset (set, s1[len - 1]))
		len --;
	return (ft_substr(s1, start, len - start));
}
