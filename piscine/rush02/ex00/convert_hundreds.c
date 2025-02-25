/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hundreds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:03:36 by lupelleg          #+#    #+#             */
/*   Updated: 2025/02/02 17:08:42 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	*ft_malloc(int size);
char	*find_number(char **entries, char *num);

char	*find_hundred(char **entries)
{
	return (find_number(entries, "100"));
}

void	handle_hundreds(char **entries, char *temp)
{
	ft_putstr(find_number(entries, temp));
	ft_putstr(" ");
	ft_putstr(find_hundred(entries));
}

void	process_hundreds(char **entries, char *num, char *temp)
{
	if (num[0] != '0')
	{
		handle_hundreds(entries, temp);
	}
}

void	print_tens_and_units(char **entries, char *num)
{
	char	*temp;

	temp = (char *)ft_malloc(3 * sizeof(char));
	temp[0] = num[0];
	temp[1] = '0';
	temp[2] = '\0';
	ft_putstr(find_number(entries, temp));
	free(temp);
	if (num[1] != '0')
	{
		ft_putstr(" ");
		temp = (char *)ft_malloc(2 * sizeof(char));
		temp[0] = num[1];
		temp[1] = '\0';
		ft_putstr(find_number(entries, temp));
		free(temp);
	}
}

void	convert_hundreds(char **entries, char *num)
{
	char	*temp;
	int		len;

	len = ft_strlen(num);
	if (len == 1 || (len == 2 && num[0] == '1'))
		ft_putstr(find_number(entries, num));
	else if (len == 2)
		print_tens_and_units(entries, num);
	else if (len == 3)
	{
		temp = (char *)ft_malloc(2 * sizeof(char));
		temp[0] = num[0];
		temp[1] = '\0';
		process_hundreds(entries, num, temp);
		free(temp);
		if (num[1] != '0' || num[2] != '0')
		{
			if (num[0] != '0')
				ft_putstr(" ");
			if (num[1] == '0')
				convert_hundreds(entries, &num[2]);
			else
				convert_hundreds(entries, &num[1]);
		}
	}
}
