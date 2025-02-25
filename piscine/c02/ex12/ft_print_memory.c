/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:47:00 by lupelleg          #+#    #+#             */
/*   Updated: 2025/01/31 11:16:09 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int i;
	int j;
	char **char_ptr = (char **)addr;

	i = 0;
	while (i < size)
	{
		printf("%p: ", (void *)char_ptr[i]);
		j = 0;
		while (char_ptr[i][j])
		{
			printf("%04x ",char_ptr[i][j]);
			j++;
		}
		printf("%s\n", char_ptr[i]);
		i++;
	}
	return (addr);
}

int	main(void)
{
	char *ptr[] = {
		"Bonjour les amin",
		"ches...c. est fo",
		"u.tout.ce qu on",
		"peut faire avec.",
		"..print_memory..",
		"..lol.lol. ."
	};
	int size = 0;
	int index;

	index = 0;
	while (*ptr[index])
	{
		size++;
		index++;
	}
	ft_print_memory(ptr, size);
	return (0);
}