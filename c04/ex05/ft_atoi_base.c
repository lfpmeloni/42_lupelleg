/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:15:54 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/27 16:35:25 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_duplicate(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base [i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		else
		{
			j = i + 1;
			while (base[j] != '\0')
			{
				if (base[i] == base[j])
					return (1);
				j++;
			}
			i++;
		}
	}
	return (0);
}

int	base_length(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	index;

	sign = 1;
	result = 0;
	if (base_length(base) >= 2 && !check_duplicate(base))
	{
		while ((*str >= 9 && *str <= 13) || *str == ' '
			|| *str == '-' || *str == '+')
		{
			if (*str == '-')
				sign = sign * -1;
			str++;
		}
		while (*str != '\0')
		{
			index = get_index(*str, base);
			result = result * base_length(base) + index;
			str++;
		}
	}
	return (result * sign);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = "-2A";
// 	char base[] = "0123456789ABCDEF";
// 	int result = ft_atoi_base(str, base);
// 	printf("%d\n", result);
// 	return (0);
// }