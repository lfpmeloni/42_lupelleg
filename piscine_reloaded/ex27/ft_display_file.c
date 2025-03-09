/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:29:18 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/09 13:34:06 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_puterror(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

void	read_file(char *file)
{
	int		fd;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_puterror("Cannot read file.\n");
		return ;
	}
	while (read(fd, &c, 1))
	{
		write(1, &c, 1);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_puterror("File name missing.\n");
	}
	else if (argc > 2)
	{
		ft_puterror("Too many arguments.\n");
	}
	else
	{
		read_file(argv[1]);
	}
	return (0);
}
