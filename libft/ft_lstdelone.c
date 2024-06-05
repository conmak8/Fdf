/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:31:43 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 11:13:38 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Takes as a parameter a node and frees the memory of
// the node’s content using the function ’del’ given
// as a parameter and free the node. The memory of
// ’next’ must not be freed.
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if ((lst == NULL) || (lst->content == NULL) || (del == NULL))
		return ;
	del(lst->content);
	free(lst);
	lst = NULL;
}

/* void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && lst->content && del)
	{
		del(lst->content);
		free(lst);
	}
} */
