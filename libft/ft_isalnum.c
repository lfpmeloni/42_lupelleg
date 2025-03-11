/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:35:52 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/11 12:15:04 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*  The isalnum() function tests for any character for which isalpha or isdigit
*  is true. The isalnum() function returns zero if the character tests false and
*  returns nun-zero if the character tests true.
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

//int	isalnum(int c)
//{
//	if (ft_isalpha(c) || ft_isdigit(c))
//		return (1);
//	else
//		return (0);
//}
