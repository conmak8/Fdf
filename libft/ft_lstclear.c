/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:56:09 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 17:15:28 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deletes and frees the given node and every
// successor of that node, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL.
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*delete_ptr;

	if (lst == NULL || *lst == NULL )
		return ;
	ptr = *lst;
	while (ptr)
	{
		delete_ptr = ptr;
		ptr = ptr->next;
		ft_lstdelone(delete_ptr, del);
	}
	*lst = NULL;
}
