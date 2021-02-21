/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_replace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 23:11:20 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/21 13:23:50 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_replace(t_ptflist *node, va_list args)
{
	int	count;

	if (node->spcf == 'c')
		count = print_char(va_arg(args, int), node);
	if (node->spcf == '%')
		count = print_char('%', node);
	if (node->spcf == 'd' || node->spcf == 'i')
		count = print_intd(va_arg(args, int), node);
	if (node->spcf == 'u')
		count = print_intd((unsigned int)va_arg(args, unsigned int), node);
	if (node->spcf == 'x' || node->spcf == 'X')
		count = print_intd((unsigned int)va_arg(args, int), node);
	if (node->spcf == 's')
		count = print_str(va_arg(args, char *), node, 0);
	if (node->spcf == 'p')
		count = print_str(ft_htoa((uintptr_t)(va_arg(args, void *)), 'x', 1),
		node, 1);
	return (count);
}
