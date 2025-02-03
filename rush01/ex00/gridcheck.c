/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gridcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyigit <yuyigit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:36:01 by yuyigit           #+#    #+#             */
/*   Updated: 2025/01/26 14:36:10 by yuyigit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_down(int input, int j, int grid[4][4])
{
	int	i;
	int	highest;
	int	visible;

	i = 0;
	highest = 0;
	visible = 0;
	while (i <= 3)
	{
		if (grid[i][j] > highest)
		{
			highest = grid[i][j];
			visible++;
		}
		i++;
	}
	return (input == visible);
}

int	check_up(int input, int j, int grid[4][4])
{
	int	i;
	int	highest;
	int	visible;

	i = 3;
	highest = 0;
	visible = 0;
	while (i >= 0)
	{
		if (grid[i][j] > highest)
		{
			highest = grid[i][j];
			visible++;
		}
		i--;
	}
	return (input == visible);
}

int	check_right(int input, int j, int grid[4][4])
{
	int	i;
	int	highest;
	int	visible;

	i = 0;
	highest = 0;
	visible = 0;
	while (i <= 3)
	{
		if (grid[j][i] > highest)
		{
			highest = grid[j][i];
			visible++;
		}
		i++;
	}
	return (input == visible);
}

int	check_left(int input, int j, int grid[4][4])
{
	int	i;
	int	highest;
	int	visible;

	i = 3;
	highest = 0;
	visible = 0;
	while (i >= 0)
	{
		if (grid[j][i] > highest)
		{
			highest = grid[j][i];
			visible++;
		}
		i--;
	}
	return (input == visible);
}
