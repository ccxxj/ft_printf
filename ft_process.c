/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_process.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 22:42:03 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/21 16:09:59 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		extract_flag(const char *str, char *comp, t_ptflist *node)
{
	int		i;
	int		j;
	int		match;

	i = 0;
	match = -1;
	while (str[i])
	{
		j = 0;
		while (comp[j])
		{
			if (str[i] == comp[j])
			{
				if (i > 29)
					ft_strlcpy2(node->flag, str, 29);
				else
					ft_strlcpy2(node->flag, str, i);
				return (i);
			}
			else
				j++;
		}
		i++;
	}
	return (-1);
}

int		ft_extractnbr(char *str, int i, t_ptflist *node, int j)
{
	node->temp = 0;
	while (str[i] < 58 && str[i] > 47 && str[i])
	{
		node->temp = node->temp * 10 + str[i] - 48;
		i++;
	}
	if (j == 1)
		node->precision = node->temp;
	else
		node->width = node->temp;
	node->temp = 0;
	return (i);
}

void	transf_flag(t_ptflist *node, va_list args)
{
	int	i;

	i = 0;
	while (node->flag[i])
	{
		if (node->flag[i] == '-')
			node->left_justify = 1;
		if (node->flag[i] == '*')
			width_adp(node->tempw = va_arg(args, int), node);
		if (node->flag[i] == '0')
			node->zero = 1;
		if (node->flag[i] == '.')
		{
			if (node->flag[i + 1] == '*')
			{
				node->precision = va_arg(args, int);
				i++;
			}
			else
				i = ft_extractnbr(node->flag, i + 1, node, 1);
		}
		if (node->flag[i] < 58 && node->flag[i] > 47)
			i = ft_extractnbr(node->flag, i, node, 0) - 1;
		i++;
	}
}

int		node_process(t_ptflist *node, va_list args, char c)
{
	int	x;

	transf_flag(node, args);
	node->spcf = c;
	x = ft_replace(node, args);
	*node = nodeinit();
	return (x);
}

int		ft_process(const char *str, t_ptflist *node, va_list args, int count)
{
	int	i;
	int	x;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			x = extract_flag(str + i + 1, "cspdsiuxX%", node);
			if (x == -1)
				return (-1);
			i = i + x + 1;
			x = node_process(node, args, str[i]);
			if (x == -1)
				return (-1);
			count = count + x;
		}
		if (!str[i + 1])
			break ;
		node->temp = print_beg(str + i + 1);
		count = count + node->temp;
		i = i + node->temp + 1;
	}
	return (count);
}
