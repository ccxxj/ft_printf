/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/20 20:31:08 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/21 15:29:47 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putchar_n(char c, int n)
{
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
}

int		check_zero(t_ptflist *node, long long int i)
{
	int	temp;

	if (node->precision >= 0)
		node->zero = -1;
	if (node->precision >= node->size)
	{
		temp = node->size;
		if (i < 0)
		{
			node->tsize = node->precision + 1;
			return (node->precision - temp + 1);
		}
		else
		{
			node->tsize = node->precision;
			return (node->precision - temp);
		}
	}
	if ((node->width > node->tsize) && node->zero == 1 &&
	node->left_justify == -1)
		return (node->width - node->tsize);
	return (0);
}

int		check_space(t_ptflist *node)
{
	if (node->width > node->tsize && (node->zero == -1 ||
	(node->left_justify == 1 && node->zero == 1)))
		return (node->width - node->tsize);
	return (0);
}

void	width_adp(int a, t_ptflist *node)
{
	if (a < 0)
	{
		node->left_justify = 1;
		node->width = -(node->tempw);
	}
	else
		node->width = node->tempw;
}
