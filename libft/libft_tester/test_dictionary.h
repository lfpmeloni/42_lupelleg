/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dictionary.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:32:06 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/11 18:06:20 by lupelleg         ###   ########.fr       */
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
GENERATE_WRAPPER(ft_isalnum, int, int)
GENERATE_WRAPPER(ft_isascii, int, int)
GENERATE_WRAPPER(ft_isprint, int, int)
GENERATE_WRAPPER(ft_strlen, char *, size_t)
GENERATE_WRAPPER(ft_memset, t_memset_input, void)


static t_test_case g_isalpha_cases[] = {
	{ (void *)&(int){'a'}, (void *)&(int){1} },
	{ (void *)&(int){'Z'}, (void *)&(int){1} },
	{ (void *)&(int){'1'}, (void *)&(int){0} },
	{ (void *)&(int){' '}, (void *)&(int){0} },
};

static t_test_case g_isdigit_cases[] = {
	{ (void *)&(int){'a'}, (void *)&(int){0} },
	{ (void *)&(int){'Z'}, (void *)&(int){0} },
	{ (void *)&(int){'1'}, (void *)&(int){1} },
	{ (void *)&(int){' '}, (void *)&(int){0} },
};

static t_test_case g_isalnum_cases[] = {
	{ (void *)&(int){'a'}, (void *)&(int){1} },
	{ (void *)&(int){'Z'}, (void *)&(int){1} },
	{ (void *)&(int){'1'}, (void *)&(int){1} },
	{ (void *)&(int){' '}, (void *)&(int){0} },
};

static t_test_case g_isascii_cases[] = {
	{ (void *)&(int){'a'}, (void *)&(int){1} },
	{ (void *)&(int){'Z'}, (void *)&(int){1} },
	{ (void *)&(int){'1'}, (void *)&(int){1} },
	{ (void *)&(int){' '}, (void *)&(int){1} },
	{ (void *)&(int){-1}, (void *)&(int){0} },
};

static t_test_case g_isprint_cases[] = {
	{ (void *)&(int){'a'}, (void *)&(int){1} },
	{ (void *)&(int){'Z'}, (void *)&(int){1} },
	{ (void *)&(int){'1'}, (void *)&(int){1} },
	{ (void *)&(int){' '}, (void *)&(int){1} },
	{ (void *)&(int){'\n'}, (void *)&(int){0} },
};

static t_test_case g_strlen_cases[] = {
	{ (void *)"Hello", (void *)&(size_t){5} },
	{ (void *)"", (void *)&(size_t){0} },
};

static t_test_case g_memset_cases[] = {
	{ &(t_memset_input){(void *)malloc(10), 'a', 10}, (void *)malloc(10) },
	{ &(t_memset_input){(void *)malloc(10), 'a', 0}, (void *)malloc(10) },
};

static t_function_test g_tests[] = {
	{ "ft_isalpha", &wrap_ft_isalpha, g_isalpha_cases, sizeof(g_isalpha_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_isdigit", &wrap_ft_isdigit, g_isdigit_cases, sizeof(g_isdigit_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_isalnum", &wrap_ft_isalnum, g_isalnum_cases, sizeof(g_isalnum_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_isascii", &wrap_ft_isascii, g_isascii_cases, sizeof(g_isascii_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_isprint", &wrap_ft_isprint, g_isprint_cases, sizeof(g_isprint_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_strlen", &wrap_ft_strlen, g_strlen_cases, sizeof(g_strlen_cases) / sizeof(t_test_case), sizeof(size_t), &print_str },
	{ "ft_memset", &wrap_ft_memset, g_memset_cases, sizeof(g_memset_cases) / sizeof(t_test_case), sizeof(void *), &print_str },
};

static size_t g_nb_tests = sizeof(g_tests) / sizeof(t_function_test);

#endif
