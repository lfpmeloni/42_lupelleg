/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:09:18 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/07 11:20:20 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	left;
	int	right;
	int	mid;

	if (nb <= 0)
		return (0);
	left = 1;
	right = nb;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (mid > nb / mid)
			right = mid - 1;
		else
			left = mid + 1;
	}
	if ((left - 1) * (left - 1) == nb)
		return (left - 1);
	return (0);
}
