/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:53:12 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/19 19:10:03 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  Allocates memory using malloc(3) and returns a new node. The 'content' member
 *  variable is initialized with the given parameter 'content'. The variable
 *  'next' is initialized to NULL.
 *  The function returns a pointer to the new node.
 */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
