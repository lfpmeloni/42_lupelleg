/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:10:36 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/30 13:45:19 by lupelleg         ###   ########.fr       */
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
	if ((left - 1) * (left - 1) <= nb)
		return (left - 1);
	return (0);
}

int	ft_is_prime(int nb)
{
	int	prime;
	int	sqrt_nb;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	prime = 3;
	sqrt_nb = ft_sqrt(nb);
	while (prime <= sqrt_nb)
	{
		if (nb % prime == 0)
			return (0);
		prime += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 0)
		return (2);
	if (nb >= 0 && nb <= 2)
		return (2);
	while (!ft_is_prime(nb))
	{
		nb++;
	}
	return (nb);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n",ft_find_next_prime(136510));
// 	return(0);
// }
