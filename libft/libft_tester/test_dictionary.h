/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dictionary.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:32:06 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/17 17:13:26 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_DICTIONARY_H
# define TEST_DICTIONARY_H

# include "libft_tester.h"
# include "../libft.h"
# include <string.h>

#define EXPECTED_STRCHR2 NULL
#define EXPECTED_STRRCHR2 NULL
#define EXPECTED_MEMCHR NULL
#define EXPECTED_STRNSTR2 NULL
#define EXPECTED_CALLOC2 NULL
#define EXPECTED_STRDUP2 NULL

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

# define GENERATE_MEM_FUNC_WRAPPER(func, struct_type)	\
void	*wrap_##func(void *input)	\
{	\
	struct_type *data = (struct_type *)input;	\
	size_t buf_size = strlen(data->dest_initial) + 1;	\
	char *buf = malloc(buf_size);	\
	if (!buf)	\
		return (NULL);	\
	strcpy(buf, data->dest_initial);	\
	func(buf, data->src, data->n);	\
	return (void *)buf;	\
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
	const char	*initial;
	int			c;
	size_t		len;
}	t_memset_input;

void *wrap_ft_memset(void *input)
{
	t_memset_input	*data = (t_memset_input *)input;
	char			*buf;
	size_t			buf_size;

	buf_size = strlen(data->initial) + 1;
	buf = malloc(buf_size);
	if (!buf)
		return (NULL);
	strcpy(buf, data->initial);
	ft_memset(buf, data->c, data->len);
	return (void *)buf;
}

typedef struct	s_bzero_input
{
	const char	*initial;
	size_t		n;
}	t_bzero_input;

void	*wrap_ft_bzero(void *input)
{
	t_bzero_input *data = (t_bzero_input *)input;
	size_t buf_size = strlen(data->initial) + 1;
	char *buf = malloc(buf_size);
	if (!buf)
		return (NULL);
	strcpy(buf, data->initial);
	ft_bzero(buf, data->n);
	return (void *)buf;
}

GENERATE_MEM_FUNC_WRAPPER(ft_memcpy, t_mem_func_input)
GENERATE_MEM_FUNC_WRAPPER(ft_memmove, t_mem_func_input)

typedef struct s_strlcpy_input
{
	char	*dst;
	const char *src;
	size_t	dstsize;
}	t_strlcpy_input;

void *wrap_ft_strlcpy(void *input)
{
	t_strlcpy_input *data = (t_strlcpy_input *)input;
	size_t min_alloc = strlen(data->dst) + 1;
	size_t alloc_size = (data->dstsize > min_alloc) ? data->dstsize : min_alloc;
	char *buf = malloc(alloc_size);
	if (!buf)
		return (NULL);
	strncpy(buf, data->dst, alloc_size);
	buf[alloc_size - 1] = '\0';
	size_t result = ft_strlcpy(buf, data->src, data->dstsize);
	size_t *ptr = malloc(sizeof(size_t));
	if (!ptr)
	{
		free(buf);
		return (NULL);
	}
	*ptr = result;
	free(buf);
	return (void *)ptr;
}

typedef struct s_strlcat_input
{
	char	*dst;
	const char *src;
	size_t	dstsize;
}	t_strlcat_input;

void *wrap_ft_strlcat(void *input)
{
	t_strlcat_input *data = (t_strlcat_input *)input;
	size_t min_alloc = strlen(data->dst) + 1;
	size_t alloc_size = (data->dstsize > min_alloc) ? data->dstsize : min_alloc;
	char *buf = malloc(alloc_size);
	if (!buf)
		return (NULL);
	strncpy(buf, data->dst, alloc_size);
	buf[alloc_size - 1] = '\0';
	size_t result = ft_strlcat(buf, data->src, data->dstsize);
	size_t *ptr = malloc(sizeof(size_t));
	if (!ptr)
	{
		free(buf);
		return (NULL);
	}
	*ptr = result;
	free(buf);
	return (void *)ptr;
}

GENERATE_WRAPPER(ft_toupper, int, int)
GENERATE_WRAPPER(ft_tolower, int, int)

typedef struct s_strchr_input
{
	const char	*s;
	int			c;
}	t_strchr_input;

void *wrap_ft_strchr(void *input)
{
	t_strchr_input *data = (t_strchr_input *)input;
	char *result = ft_strchr(data->s, data->c);
	if (!result)
		return (NULL);
	char *result_copy = ft_strdup(result);
	return (void *)result_copy;
}

typedef struct s_strrchr_input
{
	const char	*s;
	int			c;
}	t_strrchr_input;

void *wrap_ft_strrchr(void *input)
{
	t_strrchr_input *data = (t_strrchr_input *)input;
	char *result = ft_strrchr(data->s, data->c);
	if (!result)
		return (NULL);
	char *result_copy = ft_strdup(result);
	return (void *)result_copy;
}

typedef struct s_strncmp_input
{
	const char	*s1;
	const char	*s2;
	size_t		n;
}	t_strncmp_input;

void *wrap_ft_strncmp(void *input)
{
	t_strncmp_input *data = (t_strncmp_input *)input;
	int result = ft_strncmp(data->s1, data->s2, data->n);
	int *ptr = malloc(sizeof(int));
	if (!ptr)
		return (NULL);
	*ptr = result;
	return (void *)ptr;
}

typedef struct s_memchr_input
{
	const void	*s;
	int			c;
	size_t		n;
}	t_memchr_input;

void *wrap_ft_memchr(void *input)
{
	t_memchr_input *data = (t_memchr_input *)input;
	void *result = ft_memchr(data->s, data->c, data->n);
	if (!result)
		return (NULL);
	char *result_copy = ft_strdup((char *)result);
	return (void *)result_copy;
}

typedef struct s_memcmp_input
{
	const void	*s1;
	const void	*s2;
	size_t		n;
}	t_memcmp_input;

void *wrap_ft_memcmp(void *input)
{
	t_memcmp_input *data = (t_memcmp_input *)input;
	int result = ft_memcmp(data->s1, data->s2, data->n);
	int *ptr = malloc(sizeof(int));
	if (!ptr)
		return (NULL);
	*ptr = result;
	return (void *)ptr;
}

typedef struct s_strnstr_input
{
	const char	*haystack;
	const char	*needle;
	size_t		len;
}	t_strnstr_input;

void *wrap_ft_strnstr(void *input)
{
	t_strnstr_input *data = (t_strnstr_input *)input;
	char *result = ft_strnstr(data->haystack, data->needle, data->len);
	if (!result)
		return (NULL);
	char *result_copy = ft_strdup(result);
	return (void *)result_copy;
}

typedef struct s_atoi_input
{
	const char	*str;
}	t_atoi_input;

void *wrap_ft_atoi(void *input)
{
	t_atoi_input *data = (t_atoi_input *)input;
	int result = ft_atoi(data->str);
	int *ptr = malloc(sizeof(int));
	if (!ptr)
		return (NULL);
	*ptr = result;
	return (void *)ptr;
}

typedef struct s_calloc_input
{
	size_t	count;
	size_t	size;
}	t_calloc_input;

void *wrap_ft_calloc(void *input)
{
	t_calloc_input *data = (t_calloc_input *)input;
	void *result = ft_calloc(data->count, data->size);
	return result;
}

typedef struct s_strdup_input
{
	const char	*s1;
}	t_strdup_input;

void *wrap_ft_strdup(void *input)
{
	t_strdup_input *data = (t_strdup_input *)input;
	char *result = ft_strdup(data->s1);
	return (void *)result;
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

static t_bzero_input bzero_input1 = { "Hello World", 5 };
static char expected_bzero1[] = "\0\0\0\0\0 World";

static t_test_case g_bzero_cases[] = {
	{ (void *)&bzero_input1, (void *)expected_bzero1 },
};

static t_mem_func_input memcpy_input1 = { "Hello World", "42 School", 7 };
static char expected_memcpy1[] = "42 Schoorld";

static t_test_case g_memcpy_cases[] = {
	{ (void *)&memcpy_input1, (void *)expected_memcpy1 },
};

static t_mem_func_input memmove_input1 = { "Overlapping", "Test", 4 };
static char expected_memmove1[] = "Testlapping";

static t_test_case g_memmove_cases[] = {
	{ (void *)&memmove_input1, (void *)expected_memmove1 },
};

static t_strlcpy_input strlcpy_input1 = { "Hello", "World", 3 };
static size_t expected_strlcpy1 = 5;

static t_strlcpy_input strlcpy_input2 = { "Hello", "World", 6 };
static size_t expected_strlcpy2 = 5;

static t_test_case g_strlcpy_cases[] = {
	{ (void *)&strlcpy_input1, (void *)&expected_strlcpy1 },
	{ (void *)&strlcpy_input2, (void *)&expected_strlcpy2 },
};

static t_strlcat_input strlcat_input1 = { "Hello", "World", 3 };
static size_t expected_strlcat1 = 8;

static t_strlcat_input strlcat_input2 = { "Hello", "World", 6 };
static size_t expected_strlcat2 = 10;

static t_test_case g_strlcat_cases[] = {
	{ (void *)&strlcat_input1, (void *)&expected_strlcat1 },
	{ (void *)&strlcat_input2, (void *)&expected_strlcat2 },
};

static t_test_case g_toupper_cases[] = {
	{ (void *)&(int){'a'}, (void *)&(int){'A'} },
	{ (void *)&(int){'Z'}, (void *)&(int){'Z'} },
	{ (void *)&(int){'1'}, (void *)&(int){'1'} },
	{ (void *)&(int){' '}, (void *)&(int){' '} },
};

static t_test_case g_tolower_cases[] = {
	{ (void *)&(int){'a'}, (void *)&(int){'a'} },
	{ (void *)&(int){'Z'}, (void *)&(int){'z'} },
	{ (void *)&(int){'1'}, (void *)&(int){'1'} },
	{ (void *)&(int){' '}, (void *)&(int){' '} },
};

static t_strchr_input strchr_input1 = { "Hello", 'l' };
static const char expected_strchr1[] = "llo";

static t_strchr_input strchr_input2 = { "Hello", 'z' };
static const char *expected_strchr2 = NULL;

static t_test_case g_strchr_cases[] = {
	{ (void *)&strchr_input1, (void *)expected_strchr1 },
	{ (void *)&strchr_input2, (void *)EXPECTED_STRCHR2 },
};

static t_strrchr_input strrchr_input1 = { "Hello", 'l' };
static const char expected_strrchr1[] = "lo";

static t_strrchr_input strrchr_input2 = { "Hello", 'z' };
static const char *expected_strrchr2 = NULL;

static t_test_case g_strrchr_cases[] = {
	{ (void *)&strrchr_input1, (void *)expected_strrchr1 },
	{ (void *)&strrchr_input2, (void *)EXPECTED_STRRCHR2 },
};

static t_strncmp_input strncmp_input1 = { "Hello", "Hello", 5 };
static int expected_strncmp1 = 0;

static t_strncmp_input strncmp_input2 = { "Hello", "Hello", 3 };
static int expected_strncmp2 = 0;

static t_strncmp_input strncmp_input3 = { "Hello", "World", 5 };
static int expected_strncmp3 = -15;

static t_test_case g_strncmp_cases[] = {
	{ (void *)&strncmp_input1, (void *)&expected_strncmp1 },
	{ (void *)&strncmp_input2, (void *)&expected_strncmp2 },
	{ (void *)&strncmp_input3, (void *)&expected_strncmp3 },
};

static t_memchr_input memchr_input1 = { "Hello", 'l', 5 };
static const char expected_memchr1[] = "llo";

static t_memchr_input memchr_input2 = { "Hello", 'z', 5 };
static const char *expected_memchr2 = NULL;

static t_test_case g_memchr_cases[] = {
	{ (void *)&memchr_input1, (void *)expected_memchr1 },
	{ (void *)&memchr_input2, (void *)EXPECTED_MEMCHR },
};

static t_memcmp_input memcmp_input1 = { "Hello", "Hello", 5 };
static int expected_memcmp1 = 0;

static t_memcmp_input memcmp_input2 = { "Hello", "Hello", 3 };
static int expected_memcmp2 = 0;

static t_memcmp_input memcmp_input3 = { "Hello", "World", 5 };
static int expected_memcmp3 = -15;

static t_test_case g_memcmp_cases[] = {
	{ (void *)&memcmp_input1, (void *)&expected_memcmp1 },
	{ (void *)&memcmp_input2, (void *)&expected_memcmp2 },
	{ (void *)&memcmp_input3, (void *)&expected_memcmp3 },
};

static t_strnstr_input strnstr_input1 = { "Hello World", "World", 11 };
static const char expected_strnstr1[] = "World";

static t_strnstr_input strnstr_input2 = { "Hello World", "World", 5 };
static const char *expected_strnstr2 = NULL;

static t_test_case g_strnstr_cases[] = {
	{ (void *)&strnstr_input1, (void *)expected_strnstr1 },
	{ (void *)&strnstr_input2, (void *)EXPECTED_STRNSTR2 },
};

static t_atoi_input atoi_input1 = { "42" };
static int expected_atoi1 = 42;

static t_atoi_input atoi_input2 = { "-42" };
static int expected_atoi2 = -42;

static t_atoi_input atoi_input3 = { "42a" };
static int expected_atoi3 = 42;

static t_test_case g_atoi_cases[] = {
	{ (void *)&atoi_input1, (void *)&expected_atoi1 },
	{ (void *)&atoi_input2, (void *)&expected_atoi2 },
	{ (void *)&atoi_input3, (void *)&expected_atoi3 },
};

static t_calloc_input calloc_input1 = { 5, 4 };
static const char expected_calloc1[20] = {0};

static t_test_case g_calloc_cases[] = {
	{ (void *)&calloc_input1, (void *)expected_calloc1 },
};

static t_strdup_input strdup_input1 = { "Hello" };
static const char expected_strdup1[] = "Hello";

static t_test_case g_strdup_cases[] = {
	{ (void *)&strdup_input1, (void *)expected_strdup1 },
};

static t_function_test g_tests[] = {
	{ "ft_isalpha", &wrap_ft_isalpha, g_isalpha_cases, sizeof(g_isalpha_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_isdigit", &wrap_ft_isdigit, g_isdigit_cases, sizeof(g_isdigit_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_isalnum", &wrap_ft_isalnum, g_isalnum_cases, sizeof(g_isalnum_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_isascii", &wrap_ft_isascii, g_isascii_cases, sizeof(g_isascii_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_isprint", &wrap_ft_isprint, g_isprint_cases, sizeof(g_isprint_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_strlen", &wrap_ft_strlen, g_strlen_cases, sizeof(g_strlen_cases) / sizeof(t_test_case), sizeof(size_t), &print_str },
	{ "ft_memset", &wrap_ft_memset, g_memset_cases, sizeof(g_memset_cases) / sizeof(t_test_case), sizeof(expected_memset1), &print_str },
	{ "ft_bzero", &wrap_ft_bzero, g_bzero_cases, sizeof(g_bzero_cases) / sizeof(t_test_case), sizeof(expected_bzero1), &print_str },
	{ "ft_memcpy", &wrap_ft_memcpy, g_memcpy_cases, sizeof(g_memcpy_cases) / sizeof(t_test_case), sizeof(expected_memcpy1), &print_str },
	{ "ft_memmove", &wrap_ft_memmove, g_memmove_cases, sizeof(g_memmove_cases) / sizeof(t_test_case), sizeof(expected_memmove1), &print_str },
	{ "ft_strlcpy", &wrap_ft_strlcpy, g_strlcpy_cases, sizeof(g_strlcpy_cases) / sizeof(t_test_case), sizeof(size_t), &print_size_t },
	{ "ft_strlcat", &wrap_ft_strlcat, g_strlcat_cases, sizeof(g_strlcat_cases) / sizeof(t_test_case), sizeof(size_t), &print_size_t },
	{ "ft_toupper", &wrap_ft_toupper, g_toupper_cases, sizeof(g_toupper_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_tolower", &wrap_ft_tolower, g_tolower_cases, sizeof(g_tolower_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_strchr", &wrap_ft_strchr, g_strchr_cases, sizeof(g_strchr_cases) / sizeof(t_test_case), sizeof(expected_strchr1), &print_str },
	{ "ft_strrchr", &wrap_ft_strrchr, g_strrchr_cases, sizeof(g_strrchr_cases) / sizeof(t_test_case), sizeof(expected_strrchr1), &print_str },
	{ "ft_strncmp", &wrap_ft_strncmp, g_strncmp_cases, sizeof(g_strncmp_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_memchr", &wrap_ft_memchr, g_memchr_cases, sizeof(g_memchr_cases) / sizeof(t_test_case), sizeof(expected_memchr1), &print_str },
	{ "ft_memcmp", &wrap_ft_memcmp, g_memcmp_cases, sizeof(g_memcmp_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_strnstr", &wrap_ft_strnstr, g_strnstr_cases, sizeof(g_strnstr_cases) / sizeof(t_test_case), sizeof(expected_strnstr1), &print_str },
	{ "ft_atoi", &wrap_ft_atoi, g_atoi_cases, sizeof(g_atoi_cases) / sizeof(t_test_case), sizeof(int), &print_int },
	{ "ft_calloc", &wrap_ft_calloc, g_calloc_cases, sizeof(g_calloc_cases) / sizeof(t_test_case), sizeof(expected_calloc1), &print_str },
	{ "ft_strdup", &wrap_ft_strdup, g_strdup_cases, sizeof(g_strdup_cases) / sizeof(t_test_case), sizeof(expected_strdup1), &print_str },
};

static size_t g_nb_tests = sizeof(g_tests) / sizeof(t_function_test);

#endif
