/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:35:22 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/07 17:47:19 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of a node if needed.

static t_list	*ft_lstnew_with_del_f(void *content, void (*del)(void *))
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		del(content);
		return (NULL);
	}
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_head;

	new_node = NULL;
	while (lst)
	{
		new_head = ft_lstnew_with_del_f(f(lst->content), del);
		if (!new_head)
		{
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		ft_lstadd_back(&new_node, new_head);
		lst = lst->next;
	}
	return (new_node);
}

// ------------------------------------------------------------------------
// t_list	*ft_lstnew_safe(void *content)
// {
// 	t_list	*new_node;

// 	new_node = (t_list *)malloc(sizeof(t_list));
// 	if (new_node == NULL)
// 	{
// 		free(content);
// 		return (NULL);
// 	}
// 	new_node->content = content;
// 	new_node->next = NULL;
// 	return (new_node);
// }

// // Iterates the list ’lst’ and applies the function
// // ’f’ on the content of each node. Creates a new
// // list resulting of the successive applications of
// // the function ’f’.
// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*new_head;
// 	t_list	*current;
// 	t_list	*create_node;

// 	if (lst == NULL || f == NULL)
// 		return (NULL);
// 	create_node = ft_lstnew_safe((*f)(lst->content));
// 	if (create_node == NULL)
// 		return (NULL);
// 	new_head = create_node;
// 	current = new_head;
// 	lst = lst->next;
// 	while (lst)
// 	{
// 		create_node = ft_lstnew_safe((*f)(lst->content));
// 		if (create_node == NULL)
// 		{
// 			ft_lstclear(&new_head, del);
// 			return (NULL);
// 		}
// 		current->next = create_node;
// 		current = current->next;
// 		lst = lst->next;
// 	}
// 	return (new_head);
// }
