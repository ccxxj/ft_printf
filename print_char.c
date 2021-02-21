/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 23:29:57 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/21 13:25:02 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, t_ptflist *node)
{
	int	count;
	int i;

	i = node->width;
	if (node->left_justify == 1)
		write(1, &c, 1);
	if (node->width > 1)
	{
		count = node->width;
		while (i > 1)
		{
			if (node->zero == 1 && node->left_justify == -1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			i--;
		}
	}
	else
		count = 1;
	if (node->left_justify == -1)
		write(1, &c, 1);
	return (count);
}
