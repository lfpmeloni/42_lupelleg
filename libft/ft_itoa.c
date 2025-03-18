/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:00:19 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/18 16:49:09 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  Allocates memory using malloc(3) and returns a string representing the
 *  integer received as an argument. Negative numbers must be handled.
 *  The function returns the string representing the integer or NULL if
 *  allocation fails.
 */

#include "libft.h"

static int	ft_count_digits(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n >= 10)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void	ft_rec_itoa(long n, char *s, int *i)
{
	if (n >= 10)
		ft_rec_itoa(n / 10, s, i);
	s[*i] = (n % 10) + '0';
	*i = *i + 1;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;
	long	num;

	num = n;
	len = ft_count_digits(num);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (num < 0)
	{
		str[i] = '-';
		i++;
		num = -num;
	}
	ft_rec_itoa(num, str, &i);
	str[i] = '\0';
	return (str);
}
