/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:10:51 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/23 14:26:03 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	in_word;

	i = 0;
	in_word = 1;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (in_word && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			else if (!in_word && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] += 32;
			in_word = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			in_word = 0;
		else
			in_word = 1;
		i++;
	}
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = "salut, comment tu vas ? 42mots quarante-deux cinquante+et+un";

// 	printf("%s", ft_strcapitalize(str));
// 	return (0);
// }
