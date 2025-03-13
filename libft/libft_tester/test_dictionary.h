/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dictionary.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:32:06 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/13 10:54:50 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_DICTIONARY_H
# define TEST_DICTIONARY_H

# include "libft_tester.h"
# include "../libft.h"
# include <string.h>

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

void	*wrap_ft_strlen(void *input)
{
	char	*value;
	size_t	*result;

	value = (char *)input;
	result = malloc(sizeof(size_t));
	if (!result)
		return (NULL);
	*result = ft_strlen(value);
	return (void *)result;
}

typedef struct	s_memset_input
{
	const char	*inital;
	int			c;
	size_t		len;
}	t_memset_input;

void *wrap_ft_memset(void *input)
{
	t_memset_input	*data = (t_memset_input *)input;
	char			*buf;
	size_t			buf_size;

	buf_size = strlen(data->inital) + 1;
	buf = malloc(buf_size);
	if (!buf)
		return (NULL);
	strcpy(buf, data->inital);
	ft_memset(buf, data->c, data->len);
	return (void *)buf;
}

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

static t_memset_input memset_input1 = { "Hello", 'a', 3 };
static char expected_memset1[] = "aaalo";

static t_memset_input memset_input2 = { "abcdefghij", 'z', 3 };
static char expected_memset2[] = "zzzdefghij";

static t_test_case g_memset_cases[] = {
	{ (void *)&memset_input1, (void *)expected_memset1 },
	{ (void *)&memset_input2, (void *)expected_memset2 },
};

static t_function_test g_tests[] = {
	{ "ft_isalpha", &wrap_ft_isalpha, g_isalpha_cases, sizeof(g_isalpha_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_isdigit", &wrap_ft_isdigit, g_isdigit_cases, sizeof(g_isdigit_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_isalnum", &wrap_ft_isalnum, g_isalnum_cases, sizeof(g_isalnum_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_isascii", &wrap_ft_isascii, g_isascii_cases, sizeof(g_isascii_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_isprint", &wrap_ft_isprint, g_isprint_cases, sizeof(g_isprint_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_strlen", &wrap_ft_strlen, g_strlen_cases, sizeof(g_strlen_cases) / sizeof(t_test_case), sizeof(size_t), &print_str },
	{ "ft_memset", &wrap_ft_memset, g_memset_cases, sizeof(g_memset_cases) / sizeof(t_test_case), sizeof(expected_memset1), &print_str },
};

static size_t g_nb_tests = sizeof(g_tests) / sizeof(t_function_test);

#endif
