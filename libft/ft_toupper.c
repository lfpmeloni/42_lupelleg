/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:20:07 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/14 11:49:00 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*  The toupper() function converts a lower-case letter to the corresponding
*  upper-case letter. The argument must be representable as an unsigned char
*  or the value of EOF.
*  If the argument is a lower-case letter, the function returns the
*  corresponding upper-case letter if there is one; otherwise, the argument is
*  returned unchanged.
*/

int	ft_toupper(int c)
{
	if ((unsigned int)c >= 'a' && (unsigned int)c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}
