/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:20:05 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/27 15:50:06 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	print_char(char c)
{
	write(1, &c, 1);
}

void	printnbr_base(unsigned int nbr, char *base, int base_size)
{
	if (nbr >= (unsigned int)base_size)
	{
		printnbr_base(nbr / base_size, base, base_size);
	}
	print_char(base[nbr % base_size]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	size = base_length(base);
	if (size >= 2 && !check_duplicate(base))
	{
		if (nbr < 0)
		{
			print_char('-');
			if (nbr == -2147483648)
			{
				printnbr_base((unsigned int) 2147483648, base, size);
				return ;
			}
			nbr = -nbr;
		}
		printnbr_base(nbr, base, size);
	}
}

// int	main(void)
// {
// 	int		nbr;
// 	char	*base;

// 	nbr = -2147483648;
// 	base = "01";
// 	ft_putnbr_base(nbr, base);
// }
