/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 19:42:13 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/21 16:09:44 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ptflist	nodeinit(void)
{
	t_ptflist	a;

	a.left_justify = -1;
	a.precision = -1;
	a.width = -1;
	a.temp = 0;
	a.tempw = 0;
	a.size = 0;
	a.tsize = 0;
	ft_bzero(a.flag, 30);
	a.zero = -1;
	a.count = -1;
	a.negnbr = 0;
	a.padspace = 0;
	a.padzero = 0;
	return (a);
}

void		putstr_n(char *str, int n)
{
	if (str)
		write(1, str, n);
}

void		*ft_strlcpy2(char *dst, const char *src, int n)
{
	unsigned int i;

	i = n;
	if (!dst && !src)
		return (NULL);
	while (i > 0)
	{
		((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
		i--;
	}
	dst[n] = '\0';
	return (dst);
}

int			print_beg(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			i++;
		else
			break ;
	}
	if (i > 0)
		write(1, str, i);
	return (i);
}

int			ft_printf(const char *str, ...)
{
	va_list		args;
	t_ptflist	node;
	int			count;
	int			temp;

	va_start(args, str);
	node = nodeinit();
	count = print_beg(str);
	str = str + count;
	if (!str[0])
	{
		va_end(args);
		return (count);
	}
	temp = ft_process(str, &node, args, 0);
	if (temp == -1)
	{
		va_end(args);
		return (-1);
	}
	else
		count = count + temp;
	va_end(args);
	return (count);
}
