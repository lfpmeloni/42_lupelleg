/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:21:12 by lupelleg          #+#    #+#             */
/*   Updated: 2025/02/02 18:12:17 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// man free

void	ft_putstr(char *str);
char	*read_dictionary(char *filename);
char	**parse_dictionary(char *dict);
void	convert_number(char **entries, char *num);

int	is_valid_number(char *num)
{
	if (*num == '-')
		return (0);
	while (*num)
	{
		if (!(*num >= '0' && *num <= '9'))
			return (0);
		else
			num++;
	}
	return (1);
}

int	print_error(void)
{
	ft_putstr("Error\n");
	return (1);
}

int	main(int argc, char **argv)
{
	char	*dict_content;
	char	**entries;
	int		i;

	if (argc != 2 && argc != 3)
		return (print_error());
	if (argc == 2)
		dict_content = read_dictionary("numbers.dict");
	else
		dict_content = read_dictionary(argv[1]);
	if (dict_content == NULL)
		return (print_error());
	if (!is_valid_number(argv[argc - 1]))
		return (print_error());
	entries = parse_dictionary(dict_content);
	convert_number(entries, argv[argc - 1]);
	i = 0;
	while (entries[i])
	{
		free(entries[i]);
		i++;
	}
	free(entries);
	free(dict_content);
	return (0);
}
