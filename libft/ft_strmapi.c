/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:45:09 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/19 09:57:17 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  Applies the function f to each character of the string s, passing ites index
 *  as the first argument and the character itself as the second. A new string
 *  is created using malloc(3) to store the results from the successive
 *  applications of f. 
 *  The function returns the string created from the successive applications of
 *  'f' or  NULL if the allocation fails.
 */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, *s);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
