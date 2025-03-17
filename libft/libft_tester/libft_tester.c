/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:53:40 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/17 16:40:22 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"
#include "test_dictionary.h"
#include <stdio.h>

void	print_int(void *input)
{
	int	*p;

	p = (int *)input;
	printf("%d", *p);
}

void	print_str(void *input)
{
	char	*str;

	str = (char *)input;
	printf("%s", str);
}

void	print_size_t(void *input)
{
	size_t	*p;

	p = (size_t *)input;
	printf("%zu", *p);
}

static int	run_all_tests(t_function_test *tests, size_t nb_functions)
{
	size_t	i;
	size_t	j;
	void	*result;
	int		function_ok;

	i = 0;
	while (i < nb_functions)
	{
		function_ok = 1;
		j = 0;
		while (j < tests[i].nb_cases)
		{
			result = tests[i].func_wrapper(tests[i].cases[j].input);
			if (tests[i].cases[j].expected == NULL && result == NULL)
				;
			else if (tests[i].cases[j].expected == NULL || result == NULL
				|| memcmp(result, tests[i].cases[j].expected,
					tests[i].result_size) != 0)
			{
				printf("%s: KO - input: ", tests[i].func_name);
				tests[i].print_input(tests[i].cases[j].input);
				printf("\n");
				function_ok = 0;
				if (result)
					free(result);
				break ;
			}
			free(result);
			j++;
		}
		if (function_ok)
			printf("%s: OK\n", tests[i].func_name);
		i++;
	}
	return (0);
}

int	main(void)
{
	run_all_tests(g_tests, g_nb_tests);
	return (0);
}
