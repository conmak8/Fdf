/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:23:38 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/06 15:58:14 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts the number of nodes in a list
int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*ptr;

	ptr = NULL;
	count = 0;
	if (lst == 0)
		return (0);
	ptr = lst;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

/* int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	i = 0;
	current = lst;
	if (!lst)
		return (0);
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
} */