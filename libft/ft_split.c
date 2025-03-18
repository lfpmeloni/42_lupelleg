/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:16:22 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/18 14:38:02 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  Allocates memory using malloc(3) and returns an array of strings obtained
 *  by splitting 's' using the character 'c' as a delimiter. The array must end
 *  with a NULL pointer.
 *  The function returns the array of new strings resulting from the split or
 *  NULL if the allocation fails.
 */

#include "libft.h"

static size_t	ft_splitcount(char const *s, char c)
{
	size_t	count;
	int		aux;

	count = 0;
	aux = 0;
	while (*s)
	{
		if (*s != c && aux == 0)
		{
			aux = 1;
			count ++;
		}
		else if (*s == c)
			aux = 0;
		s++;
	}
	return (count);
}

static void	ft_freesplit(char **split, int j)
{
	while (j > 0)
	{
		j--;
		free(split[j]);
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*start;
	size_t	i;

	split = (char **)malloc((ft_splitcount(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = (char *)s;
			s = ft_strchr(s, c);
			if (!s)
				s = start + ft_strlen(start);
			split[i] = ft_substr(start, 0, s - start);
			if (!split[i++])
				return (ft_freesplit(split, i), NULL);
		}
	}
	split[i] = NULL;
	return (split);
}
