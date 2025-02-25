/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:47:36 by lupelleg          #+#    #+#             */
/*   Updated: 2025/02/03 13:56:31 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_combn_recursive(int n, int current_digit, char *comb, int index)
{
	if (index == n)
	{
		write(1, comb, n);
		if (comb[0] != '9' - n + 1)
			write(1, ", ", 2);
		return ;
	}
	while (current_digit <= 9)
	{
		comb[index] = current_digit + '0';
		print_combn_recursive(n, current_digit + 1, comb, index + 1);
		current_digit++;
	}
}

void	ft_print_combn(int n)
{
	char	comb[10];

	if (n > 0 && n < 10)
	{
		print_combn_recursive(n, 0, comb, 0);
	}
}

// int	main(void)
// {
// 	ft_print_combn(2);
// 	return (0);
// }
