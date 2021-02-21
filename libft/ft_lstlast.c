/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 16:06:46 by Xiaojing      #+#    #+#                 */
/*   Updated: 2020/11/20 21:23:33 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *head;

	if (!lst)
		return (NULL);
	head = lst;
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}
