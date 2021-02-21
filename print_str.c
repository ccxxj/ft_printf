/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/20 22:11:28 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/21 15:09:22 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str, t_ptflist *node, int freebl)
{
	int	count;

	if (!str && node->spcf == 's')
		str = "(null)";
	if (!str && node->spcf == 'p')
		return (-1);
	node->size = ft_strlen(str);
	node->tsize = node->size;
	if (node->precision < node->size && node->precision > -1)
	{
		node->tsize = node->precision;
		node->size = node->tsize;
	}
	if (freebl == 1)
		node->padzero = check_zero(node, 1);
	node->padspace = check_space(node);
	print_process(str, node);
	count = node->tsize + node->padspace + node->padzero;
	if (freebl == 1)
		free(str);
	return (count);
}
