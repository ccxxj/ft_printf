/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 08:41:03 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/21 16:04:30 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *str, size_t n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		((unsigned char *)str)[i] = '\0';
		i++;
		n--;
	}
}
