/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:26:47 by lupelleg          #+#    #+#             */
/*   Updated: 2025/02/02 17:12:39 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_atoa(char *str);
char	*ft_strncpy(char *dest, const char *src, int n);
void	*ft_malloc(int size);

char	*get_normalized_entry(char *entry_num_str)
{
	char	*normalized_entry_num;

	normalized_entry_num = ft_atoa(entry_num_str);
	return (normalized_entry_num);
}

char	*find_colon_pos(char *entry_num_str)
{
	char	*colon_pos;

	colon_pos = entry_num_str;
	while (*colon_pos && *colon_pos != ':')
		colon_pos++;
	if (*colon_pos == ':')
	{
		colon_pos++;
		while (*colon_pos == ' ')
			colon_pos++;
		return (colon_pos);
	}
	return (NULL);
}

char	*find_number(char **entries, char *num)
{
	int		i;
	char	*normalized_num;
	char	*entry_num_str;
	char	*colon_pos;
	char	*normalized_entry_num;

	normalized_num = ft_atoa(num);
	i = 0;
	while (entries[i])
	{
		entry_num_str = entries[i];
		normalized_entry_num = get_normalized_entry(entry_num_str);
		if (ft_strcmp(normalized_entry_num, normalized_num) == 0)
		{
			free(normalized_entry_num);
			free(normalized_num);
			colon_pos = find_colon_pos(entry_num_str);
			if (colon_pos)
				return (colon_pos);
		}
		free(normalized_entry_num);
		i++;
	}
	free(normalized_num);
	return (NULL);
}

char	*create_magnitude_str(int magnitude)
{
	char	*str;
	int		i;

	str = ft_malloc(magnitude * 3 + 2);
	str[0] = '1';
	i = 1;
	while (i <= magnitude * 3)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	print_magnitude(char **entries, int magnitude)
{
	char	*mag_str;
	char	*value;

	mag_str = create_magnitude_str(magnitude);
	value = find_number(entries, mag_str);
	if (value)
	{
		ft_putstr(" ");
		ft_putstr(value);
	}
	free(mag_str);
}
