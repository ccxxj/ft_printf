/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 13:24:30 by Xiaojing      #+#    #+#                 */
/*   Updated: 2020/11/27 11:30:39 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int	m;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 0)
	{
		m = n % 10 + '0';
		n = n / 10;
		if (n > 0)
			ft_putnbr_fd(n, fd);
		write(fd, &m, 1);
	}
	else
		write(fd, "0", 1);
}
