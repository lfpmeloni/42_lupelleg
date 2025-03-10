/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:21:03 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/10 12:36:44 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*  The isalpha() function tests for any character for which isupper or islower 
*  is true. The value of the argument must be representable as an unsigned char
*  or the value of EOF.
*  The isalpha() function returns zero if the character tests false and returns
*  non-zero (?) if the character tests true.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
