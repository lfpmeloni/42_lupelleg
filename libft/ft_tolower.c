/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:41:05 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/14 11:47:31 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*  The tolower() function converts a upper-case letter to the corresponding
*  lower-case letter. The argument must be representable as an unsigned char
*  or the value of EOF.
*  If the argument is a upper-case letter, the function returns the
*  corresponding lower-case letter if there is one; otherwise, the argument is
*  returned unchanged.
*/

int	ft_tolower(int c)
{
	if ((unsigned int)c >= 'A' && (unsigned int)c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}
