/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:01:25 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/11 12:09:11 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  The strlen() function computes the length of the string s.
 *  The function returns the numver of characters that precede the terminating
 *  NUL character.
 */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}
