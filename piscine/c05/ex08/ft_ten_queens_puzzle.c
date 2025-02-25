/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:35:02 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/29 16:47:44 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_queens(int *queens)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = queens[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_safe(int *queens, int index, int pos)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (queens[i] == pos || queens[i] - i == pos - index
			|| queens[i] + i == pos + index)
			return (0);
		i++;
	}
	return (1);
}

int	generate_queens(int *queens, int index)
{
	int	num;
	int	count;

	if (index == 10)
	{
		print_queens(queens);
		return (1);
	}
	count = 0;
	num = 0;
	while (num < 10)
	{
		if (is_safe(queens, index, num))
		{
			queens[index] = num;
			count += generate_queens(queens, index +1);
		}
		num ++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];
	int	i;

	i = 0;
	while (i < 10)
	{
		queens[i] = 0;
		i++;
	}
	return (generate_queens(queens, 0));
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_ten_queens_puzzle());
// 	return (0);
// }
