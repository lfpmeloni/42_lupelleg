/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:16:02 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/27 19:16:49 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_matrix(int result[4][4]);
int		generate_matrices(int grid[4][4], int row, int col, int input[]);

int	ft_stoia(char *str, int *input_int)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (*str >= '1' && *str <= '4')
		{
			input_int[count] = (*str - '0');
			count++;
			flag++;
		}
		else if (*str == ' ')
			flag--;
		else
			return (0);
		if (flag < 0 || flag >= 2)
			return (0);
		str++;
	}
	if (flag <= 0 || flag >= 2)
		return (0);
	return (count);
}

void	ft_create_2d_array(int array[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			array[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	input_int[16];
	int	size;
	int	result[4][4];

	ft_create_2d_array(result);
	if (argc == 2)
	{
		size = ft_stoia(argv[1], input_int);
		if (size != 16)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (generate_matrices(result, 0, 0, input_int))
			return (0);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
