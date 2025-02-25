/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:39:02 by lupelleg          #+#    #+#             */
/*   Updated: 2025/02/06 10:44:16 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

int	abs(int value)
{
	if (value < 0)
		return (-value);
	else
		return (value);
}

# define ABS(value) abs(value)

#endif
