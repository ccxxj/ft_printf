/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_intd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/20 10:34:54 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/21 15:21:42 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	neg_print(int i, char *str)
{
	int	n;

	n = 1;
	write(1, &str[0], 1);
	putchar_n('0', i);
	while (str[n])
	{
		write(1, &str[n], 1);
		n++;
	}
}

void	print_process(char *str, t_ptflist *node)
{
	if (node->left_justify == 1)
	{
		if (node->negnbr == 1)
			neg_print(node->padzero, str);
		else
		{
			putchar_n('0', node->padzero);
			putstr_n(str, node->size);
		}
		putchar_n(' ', node->padspace);
	}
	if (node->left_justify == -1)
	{
		putchar_n(' ', node->padspace);
		if (node->negnbr == 1)
			neg_print(node->padzero, str);
		else
		{
			putchar_n('0', node->padzero);
			putstr_n(str, node->size);
		}
	}
}

int		check_edge(int width)
{
	if (width > 0)
	{
		putchar_n(' ', width);
		return (width);
	}
	else
		return (0);
}

int		print_intd(long long int i, t_ptflist *node)
{
	char	*nbr;
	int		count;

	if (i < 0)
		node->negnbr = 1;
	if (node->precision == 0 && i == 0)
		return (check_edge(node->width));
	else
	{
		if (node->spcf == 'x' || node->spcf == 'X')
			nbr = ft_htoa(i, node->spcf, 0);
		else
			nbr = ft_itoa(i);
		if (!nbr)
			return (-1);
		node->size = ft_strlen(nbr);
		node->tsize = node->size;
		node->padzero = check_zero(node, i);
		node->padspace = check_space(node);
	}
	print_process(nbr, node);
	count = ft_strlen(nbr) + node->padspace + node->padzero;
	free(nbr);
	return (count);
}
