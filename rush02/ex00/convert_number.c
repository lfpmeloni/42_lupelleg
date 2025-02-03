/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:52:37 by lupelleg          #+#    #+#             */
/*   Updated: 2025/02/02 18:02:22 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_putstr(char *str);
int			ft_strlen(char *str);
void		*ft_malloc(int size);
char		*ft_strncpy(char *dest, const char *src, int n);
void		print_magnitude(char **entries, int magnitude);
void		convert_hundreds(char **entries, char *num);
char		*find_number(char **entries, char *num);

int	ft_is_non_zero(char *segment)
{
	while (*segment)
	{
		if (*segment != '0')
			return (1);
		segment++;
	}
	return (0);
}

void	convert_segment(char **entries, char *segment, int magnitude)
{
	if (ft_is_non_zero(segment))
	{
		convert_hundreds(entries, segment);
		if (magnitude > 0)
			print_magnitude(entries, magnitude);
	}
}

void	process_segment(char **entries, char *segment,
	int magnitude, int *first_segment)
{
	if (ft_is_non_zero(segment))
	{
		if (!*first_segment)
			ft_putstr(" ");
		*first_segment = 0;
		convert_segment(entries, segment, magnitude);
	}
}

void	iterate_segments(char **entries, char *num, int magnitude)
{
	char		*segment;
	int			len;
	int			segment_len;
	int			i;
	int			first_segment;

	i = 0;
	first_segment = 1;
	len = ft_strlen(num);
	while (len > 0)
	{
		segment_len = len % 3;
		if (segment_len == 0)
			segment_len = 3;
		segment = (char *)ft_malloc((segment_len + 1) * sizeof(char));
		ft_strncpy(segment, &num[i], segment_len);
		segment[segment_len] = '\0';
		process_segment(entries, segment, magnitude, &first_segment);
		free(segment);
		i += segment_len;
		len -= segment_len;
		magnitude--;
	}
}

void	convert_number(char **entries, char *num)
{
	int		len;
	int		magnitude;
	char	*result;

	len = ft_strlen(num);
	while (num[0] == '0' && len > 1)
	{
		num++;
		len--;
	}
	if (len == 1 && num[0] == '0')
	{
		result = find_number(entries, "0");
		if (result)
		{
			ft_putstr(result);
			ft_putstr("\n");
		}
		return ;
	}
	magnitude = (len - 1) / 3;
	iterate_segments(entries, num, magnitude);
	ft_putstr("\n");
}
