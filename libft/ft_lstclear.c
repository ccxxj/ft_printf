/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 17:26:37 by Xiaojing      #+#    #+#                 */
/*   Updated: 2020/11/14 16:11:12 by xxu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *head;
	t_list *next;

	head = *lst;
	while (head)
	{
		next = head->next;
		ft_lstdelone(head, del);
		head = next;
	}
	*lst = NULL;
}
