/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:00:39 by lupelleg          #+#    #+#             */
/*   Updated: 2025/02/02 18:14:37 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// man malloc
#include <fcntl.h>
// man 2 open
#include <unistd.h>
// man 2 read

void	*ft_malloc(int size);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

char	*read_dictionary(char *filename)
{
	int		fd;
	char	*buffer;
	int		bytes_read;
	int		size;

	size = 4096;
	buffer = (char *)ft_malloc(size + 1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Dict ");
		free(buffer);
		return (NULL);
	}
	bytes_read = read(fd, buffer, size);
	buffer[bytes_read] = '\0';
	close(fd);
	return (buffer);
}

char	**parse_dictionary(char *dict)
{
	char	**entries;
	int		i;
	int		j;

	i = 0;
	entries = (char **)ft_malloc(100 * sizeof(char *));
	while (*dict)
	{
		while (*dict == '\n')
			dict++;
		entries[i] = (char *)ft_malloc(ft_strlen(dict) + 1);
		j = 0;
		while (*dict && *dict != '\n')
		{
			entries[i][j++] = *dict;
			dict++;
		}
		entries[i][j] = '\0';
		if (*dict == '\n')
			dict++;
		i++;
	}
	entries[i] = NULL;
	return (entries);
}

char	*ft_atoa(char *str)
{
	char	*result;
	int		i;
	int		j;

	result = (char *)ft_malloc(ft_strlen(str) + 1);
	i = 0;
	j = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		result[j++] = str[i++];
	result[j] = '\0';
	return (result);
}
