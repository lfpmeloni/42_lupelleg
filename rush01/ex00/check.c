/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyigit <yuyigit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:35:41 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/26 14:37:31 by yuyigit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_down(int input, int j, int grid[4][4]);
int	check_up(int input, int j, int grid[4][4]);
int	check_right(int input, int j, int grid[4][4]);
int	check_left(int input, int j, int grid[4][4]);

int	check_direction_down(int input[], int grid[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_down(input[i], i, grid))
			return (0);
		i++;
	}
	return (1);
}

int	check_direction_up(int input[], int grid[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_up(input[i + 4], i, grid))
			return (0);
		i++;
	}
	return (1);
}

int	check_direction_right(int input[], int grid[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_right(input[i + 8], i, grid))
			return (0);
		i++;
	}
	return (1);
}

int	check_direction_left(int input[], int grid[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_left(input[i + 12], i, grid))
			return (0);
		i++;
	}
	return (1);
}

int	check(int input[], int grid[4][4])
{
	if (!(check_direction_down(input, grid)))
		return (0);
	if (!(check_direction_up(input, grid)))
		return (0);
	if (!(check_direction_right(input, grid)))
		return (0);
	if (!(check_direction_left(input, grid)))
		return (0);
	return (1);
}
