/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:25:15 by yuyigit           #+#    #+#             */
/*   Updated: 2025/01/27 09:33:17 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	update_row_col(int *row, int *col)
{
	if (*col == 4)
	{
		(*row)++;
		*col = 0;
	}
}

int	is_safe(int grid[4][4], int row, int col, int num)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		if (grid[row][x] == num || grid[x][col] == num)
			return (0);
		x++;
	}
	return (1);
}
void	print_matrix(int result[4][4]);
int		check(int input[], int grid[4][4]);

int	generate_matrices(int grid[4][4], int row, int col, int input[])
{
	int	num;

	if (row == 3 && col == 4)
	{
		if (check(input, grid))
		{
			print_matrix(grid);
			return (1);
		}
		return (0);
	}
	update_row_col(&row, &col);
	num = 1;
	while (num <= 4)
	{
		if (is_safe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (generate_matrices(grid, row, col + 1, input))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
