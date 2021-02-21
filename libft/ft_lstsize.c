/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 15:40:23 by Xiaojing      #+#    #+#                 */
/*   Updated: 2020/11/27 11:28:32 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_lstsize(t_list *lst)
{
	t_list	*head;
	int		count;

	head = malloc(sizeof(t_list));
	if (!head)
		return (0);
	count = 0;
	head = lst;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
