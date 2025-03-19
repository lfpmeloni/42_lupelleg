/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:57:40 by lupelleg          #+#    #+#             */
/*   Updated: 2025/03/19 19:09:26 by lupelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  Adds the node'new' at the beginning of the list.
 *  The function returns nothing.
 */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
