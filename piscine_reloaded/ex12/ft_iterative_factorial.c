/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:50:27 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/06 17:51:33 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	factorial;

	i = 1;
	factorial = 1;
	if (nb < 0)
	{
		return (0);
	}
	while (i <= nb)
	{
		factorial = factorial * i;
		i++;
	}
	return (factorial);
}
