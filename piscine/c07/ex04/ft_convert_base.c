/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:02:26 by lupelleg          #+#    #+#             */
/*   Updated: 2025/02/05 14:16:27 by lupelleg         ###   ########.fr       */
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
	int		i;
	int		size;

	size = base_length(base);
	i = 0;
	if (nbr < 0)
	{
		result[i++] = '-';
		nbr *= -1;
	}
	if ((nbr / size) > 0)
	{
		ft_itoa_base((nbr / size), base, result);
		while (result[i] != '\0')
			i++;
		result[i] = base[nbr % size];
	}
	else
	{
		i = 0;
		while (result[i] != 0)
			i++;
		result[i] = base[nbr % size];
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		int_nbr;
	int		max_size;
	char	*result;

	if (base_length(base_from) < 2 || base_length(base_to) < 2
		|| check_duplicate(base_from) || check_duplicate(base_to))
		return (NULL);
	int_nbr = ft_atoi_base(nbr, base_from);
	max_size = 35;
	result = (char *)ft_malloc(max_size);
	if (!result)
		return (NULL);
	i = 0;
	while (i < 35)
		result[i++] = '\0';
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
