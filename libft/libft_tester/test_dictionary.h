/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dictionary.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:32:06 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/10 11:47:08 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_DICTIONARY_H
# define TEST_DICTIONARY_H

# include "libft_tester.h"
# include "../libft.h"

# define GENERATE_WRAPPER(func, in_type, out_type) \
void *wrap_##func(void *input) \
{ \
	in_type value; \
	out_type *result; \
	value = *((in_type *)input); \
	result = malloc(sizeof(out_type)); \
	if (!result) \
		return (NULL); \
	*result = func(value); \
	return (void *)result; \
}

GENERATE_WRAPPER(ft_isalpha, int, int)
GENERATE_WRAPPER(ft_isdigit, int, int)

static t_test_case g_isalpha_cases[] = {
	{ (void *)('a'), (void *)1 },
	{ (void *)('Z'), (void *)1 },
	{ (void *)('1'), (void *)0 },
	{ (void *)(' '), (void *)0 },
	{ (void *)('\t'), (void *)0 },
	{ (void *)('\n'), (void *)0 },
	{ (void *)('\v'), (void *)0 },
	{ (void *)('\f'), (void *)0 },
	{ (void *)('\r'), (void *)0 },
	{ (void *)(0), (void *)0 },
};

static t_test_case g_isdigit_cases[] = {
	{ (void *)('a'), (void *)0 },
	{ (void *)('Z'), (void *)0 },
	{ (void *)('1'), (void *)1 },
	{ (void *)(' '), (void *)0 },
	{ (void *)('\t'), (void *)0 },
	{ (void *)('\n'), (void *)0 },
	{ (void *)('\v'), (void *)0 },
	{ (void *)('\f'), (void *)0 },
	{ (void *)('\r'), (void *)0 },
	{ (void *)(0), (void *)0 },
};

static t_function_test g_tests[] = {
	{ "ft_isalpha", &wrap_ft_isalpha, g_isalpha_cases, sizeof(g_isalpha_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_isdigit", &wrap_ft_isdigit, g_isdigit_cases, sizeof(g_isdigit_cases) / sizeof(t_test_case), sizeof(int), &print_int },
};

static size_t g_nb_tests = sizeof(g_tests) / sizeof(t_function_test);

#endif
