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
	return (result * sign);
}

char	*ft_itoa_base(int nbr, char *base, char *result)
{
	int		len;
	int		size;
	long	long_nbr;

	long_nbr = nbr;
	size = base_length(base);
	len = 0;
	if (long_nbr < 0)
	{
		result[len++] = '-';
		long_nbr = -long_nbr;
	}
	if (long_nbr / size > 0)
		len += ft_itoa_base(long_nbr / size, base, result + len) - result;
	result[len] = base[long_nbr % size];
	result[len + 1] = '\0';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		int_nbr;
	int		max_size;
	char	*result;

	if (base_length(base_from) < 2 || base_length(base_to) < 2
		|| check_duplicate(base_from) || !check_duplicate(base_to))
		return (NULL);
	int_nbr = ft_atoi_base(nbr, base_from);
	max_size = 33;
	result = (char *)ft_malloc(max_size);
	if (!result)
		return (NULL);
	result[0] = '\0';
	return (ft_itoa_base(int_nbr, base_to, result));
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
