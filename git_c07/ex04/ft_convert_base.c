/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:02:26 by lupelleg          #+#    #+#             */
/*   Updated: 2025/02/04 15:43:56 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		base_length(char *base);
int		check_duplicate(char *base);
int		get_index(char c, char *base);
void	*ft_malloc(int size);

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

char	*ft_itoa_base(int nbr, char *base, char *result)
{
	int		i;
	int		size;
	long	long_nbr;

	long_nbr = nbr;
	size = base_length(base);
	if (size >= 2 && !check_duplicate(base))
	{
		if (long_nbr / size >= 1)
		{
			ft_itoa_base(long_nbr / size, base, result);
			i = 0;
			while (result[i] != '\0')
				i++;
			result[i] = base[long_nbr % size];
		}
		else
		{
			i = 0;
			while (result[i] != 0)
				i++;
			result[i] = base[long_nbr % size];
		}
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		int_nbr;
	int		size;
	char	*result;

	if (base_length(base_from) >= 2 && base_length(base_to) >= 2
		&& !check_duplicate(base_from) && !check_duplicate(base_to))
	{
		size = base_length(nbr);
		result = ft_malloc(size + 1);
		i = 0;
		while (i < (size + 1))
			result[i++] = '\0';
		int_nbr = ft_atoi_base(nbr, base_from);
		if (int_nbr < 0)
		{
			int_nbr = -int_nbr;
			result[0] = '-';
		}
		result = ft_itoa_base(int_nbr, base_to, result);
		return (result);
	}
	else
		return (NULL);
}

// int	main(void)
// {
// 	char	*nbr = "-178";
// 	char	*base_from = "0123456789";
// 	char	*base_to = "01";
// 	char	*ptr;

// 	ptr = ft_convert_base(nbr, base_from, base_to);
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	return (0);
// }
