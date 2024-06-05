/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:27:23 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/06 16:52:33 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the last node of the list.
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;
	t_list	*ptr_catch;

	ptr = NULL;
	if (lst == 0)
		return (0);
	ptr = lst;
	while (ptr != 0)
	{
		ptr_catch = ptr;
		ptr = ptr->next;
	}
	return (ptr_catch);
}

/* // Returns the last node of the list.
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (!lst)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
} */