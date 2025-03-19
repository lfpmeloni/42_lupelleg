/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:27:22 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/19 19:09:33 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  Deletes and frees the given node and all its successors, using the function
 *  del' and free(3). Finally, set the pointer to the list to NULL.
 *  The function returns nothing.
 */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
