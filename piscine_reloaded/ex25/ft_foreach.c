/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:39:32 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/08 17:47:34 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//
//void	ft_putchar(char c)
//{
//	write(1, &c, 1);
//}
//
//void	ft_putnbr(int nb)
//{
//	unsigned int	nbr;
//
//	if (nb < 0)
//	{
//		ft_putchar('-');
//		nbr = -nb;
//	}
//	else
//		nbr = nb;
//	if (nbr >= 10)
//		ft_putnbr(nbr / 10);
//	ft_putchar(nbr % 10 + '0');
//}

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

//int	main(void)
//{
//	int		tab[5] = {1, 2, 3, 4, 5};
//
//	ft_foreach(tab, 5, &ft_putnbr);
//	return (0);
//}
