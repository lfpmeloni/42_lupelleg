/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:27:27 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/11 11:32:31 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* The isdigit() function tests for a decimal digit character. 
* The isdigit() and isnumber() functions return zero if the character tests
* false and returns non-zero if the character tests true.
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
