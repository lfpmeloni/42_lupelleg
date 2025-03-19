/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:04:00 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/19 10:11:31 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Outputs the character 'c' to the specified file descriptor.
 * This function has no return value.
 */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
