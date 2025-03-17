/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:04:35 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/17 15:55:54 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TESTER_H
# define LIBFT_TESTER_H

# include <stdlib.h>
# include <string.h>

typedef struct s_test_case
{
	void		*input;
	void		*expected;
}				t_test_case;

typedef struct s_function_test
{
	const char	*func_name;
	void		*(*func_wrapper)(void *input);
	t_test_case	*cases;
	size_t		nb_cases;
	size_t		result_size;
	void		(*print_input)(void *input);
}				t_function_test;

typedef struct s_mem_func_input
{
	const char	*dest_initial;
	const char	*src;
	size_t		n;
}				t_mem_func_input;

void			print_int(void *input);
void			print_str(void *input);
void			print_size_t(void *input);

#endif
