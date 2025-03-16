/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:30:17 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/15 13:50:48 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  The atoi() function converts the initial portion of the string pointed to by
 *  str to int representation.
 */

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	while ((*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r') && *str != '\0')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
